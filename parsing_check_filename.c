/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:34:38 by seongjko          #+#    #+#             */
/*   Updated: 2024/02/16 20:34:39 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_name(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (!(file_name[len - 1] == 'f' && file_name[len - 2] == 'd' && \
	file_name[len - 3] == 'f' && file_name[len - 4] == '.'))
		return (-1);
	return (0);
}
