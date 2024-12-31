/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:56:30 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/18 10:56:31 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char_ary(char	**char_ary)
{
	int	i;

	i = 0;
	while (char_ary[i] != NULL)
		free(char_ary[i++]);
	free(char_ary);
}

int	char_to_int(char **char_ary, int *int_ary)
{
	int	i;

	i = -1;
	while (char_ary[++i] && char_ary[i][0] != '\n')
	{
		if (check_valid_char_ary(char_ary[i]) == 0)
		{
			ft_printf("wrong argument: %s\n", char_ary[i]);
			ft_printf("argument is not valid from [create_1d_ary]\n");
			return (0);
		}
		else if (ft_atoi(char_ary[i]) < -2147483648 || \
		ft_atoi(char_ary[i]) > 2147483647)
		{
			ft_printf("argument is too big\n");
			return (0);
		}
		else
			int_ary[i] = ft_atoi(char_ary[i]);
	}
	return (1);
}

int	*create_1d_ary(t_list *list, int column)
{
	char	**char_ary;
	int		*int_ary;

	char_ary = ft_split(list->content, ' ');
	int_ary = (int *)malloc(sizeof(int) * (column));
	if (int_ary == NULL)
	{
		ft_printf("malloc failed from [create_1d_ary]\n");
		return (NULL);
	}
	if (char_to_int(char_ary, int_ary) == 0)
	{
		free(int_ary);
		free_char_ary(char_ary);
		return (NULL);
	}
	free_char_ary(char_ary);
	return (int_ary);
}

int	**create_2d_ary(t_list *head, t_mlx *mlx)
{
	int		**ary;
	int		i;
	t_list	*current;

	i = 0;
	current = head;
	if (row_column_cnt(mlx, head) == 0)
		exit(1);
	ary = (int **)malloc(sizeof(int *) * (mlx->map.row));
	if (ary == NULL)
	{
		ft_printf("malloc failed from [create_2d_ary]\n");
		exit(1);
	}
	while (current != NULL)
	{
		ary[i] = create_1d_ary(current, mlx->map.column);
		if (ary[i] == NULL)
			exit(1);
		current = current->next;
		i++;
	}
	return (ary);
}

int	**parse_input_coordinates(t_mlx *mlx, char **argv)
{
	int		fd;
	int		**ary;
	t_list	*head;

	fd = open(argv[1], O_RDONLY);
	is_file_opened(fd, argv[1]);
	head = create_linked_list(fd);
	ary = create_2d_ary(head, mlx);
	free_linked_list(head);
	return (ary);
}
