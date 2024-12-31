/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:06:09 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:11 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rotate	*create_1d_ary_rotate(int column)
{
	t_rotate	*ary;

	ary = (t_rotate *)malloc(sizeof(t_rotate) * column);
	return (ary);
}

t_rotate	**secure_space_for_rotated_coordinates(t_mlx *mlx)
{
	t_rotate	**ary;
	int			i;

	i = 0;
	ary = (t_rotate **)malloc(sizeof(t_rotate *) * (mlx->map.row));
	while (i < mlx->map.row)
	{
		ary[i] = create_1d_ary_rotate(mlx->map.column);
		i++;
	}
	return (ary);
}
