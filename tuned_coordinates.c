/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuned_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:17:41 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/24 01:17:46 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tuned	*create_1d_ary_tuned(int column)
{
	t_tuned	*ary;

	ary = (t_tuned *)malloc(sizeof(t_tuned) * column);
	return (ary);
}

t_tuned	**secure_space_for_tuned_coordinates(t_mlx *mlx)
{
	t_tuned	**ary;
	int		i;

	i = 0;
	ary = (t_tuned **)malloc(sizeof(t_tuned *) * (mlx->map.row));
	while (i < mlx->map.row)
	{
		ary[i] = create_1d_ary_tuned(mlx->map.column);
		i++;
	}
	return (ary);
}

int	exit_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}
