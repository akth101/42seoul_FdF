/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:09:16 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/21 16:09:18 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_linked_list(int fd)
{
	char	*input;
	t_list	*head;
	t_list	*new_node;
	int		flag;

	head = NULL;
	flag = 0;
	while (1)
	{
		input = get_next_line(fd);
		if (flag == 0 && input == (void *)0)
		{
			ft_printf("empty file\n");
			exit(1);
		}
		else
			flag = 1;
		if (flag == 1 && input == (void *)0)
			break ;
		new_node = ft_lstnew(input);
		ft_lstadd_back(&head, new_node);
	}
	return (head);
}

void	free_content(void *content)
{
	free(content);
}

void	free_linked_list(t_list *head)
{
	ft_lstclear(&head, free_content);
}
