/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_row_column_cnt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:16 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/21 16:01:19 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	row_cnt(t_list *list)
{
	return (ft_lstsize(list));
}

int	column_cnt(t_list *list)
{
	int		column;
	int		flag;
	char	*s;

	column = 0;
	flag = 0;
	s = list->content;
	while (*s)
	{
		if (flag == 0 && *s != ' ' && *s != '\n')
		{
			column++;
			flag = 1;
		}
		if (flag == 1 && *s == ' ')
			flag = 0;
		s++;
	}
	return (column);
}

int	row_column_cnt(t_mlx *mlx, t_list *list)
{
	t_list	*current;
	int		temp_column;

	mlx->map.row = row_cnt(list);
	current = list;
	temp_column = column_cnt(list);
	current = current->next;
	while (current != NULL)
	{
		if (column_cnt(current) != temp_column)
		{
			ft_printf("Map is not rectangle\n");
			return (0);
		}
		current = current->next;
	}
	mlx->map.column = temp_column;
	return (1);
}

void	is_file_opened(int fd, char *filename)
{
	if (fd == -1)
	{
		ft_printf("failed openning file\n");
		exit(1);
	}
	else if (check_file_name(filename) == -1)
	{
		ft_printf("invalid file name\n");
		exit(1);
	}
	else
		ft_printf("fd: %d\n", fd);
}

int	check_valid_char_ary(char *ary)
{
	if (*ary == '-')
		ary++;
	while (*ary && *ary != '\n')
	{
		if (!('0' <= *ary && *ary <= '9'))
			return (0);
		ary++;
	}
	return (1);
}
