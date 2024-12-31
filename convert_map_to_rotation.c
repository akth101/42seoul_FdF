/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotate_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:13 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/23 17:38:14 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_arbitrary_axis_rotation(int x, int y, int z, t_mlx *mlx)
{
	double	rad_x;
	double	rad_y;
	double	rad_z;

	rad_x = (mlx->degree.x * M_PI) / 180;
	rad_y = (mlx->degree.y * M_PI) / 180;
	rad_z = (mlx->degree.z * M_PI) / 180;
	mlx->rotate_pos[y][x].x = x * (cos(rad_y) * cos(rad_z)) \
	+ y * (sin(rad_x) * sin(rad_y) * cos(rad_z) - cos(rad_x) * sin(rad_z)) \
	+ z * (cos(rad_x) * sin(rad_y) * cos(rad_z) + sin(rad_x) * sin(rad_z));
	mlx->rotate_pos[y][x].y = x * (cos(rad_y) * sin(rad_z)) \
	+ y * (sin(rad_x) * sin(rad_y) * sin(rad_z) + cos(rad_x) * cos(rad_z)) \
	+ z * (cos(rad_x) * sin(rad_y) * sin(rad_z) - sin(rad_x) * cos(rad_z));
	mlx->rotate_pos[y][x].z = -x * sin(rad_y) \
	+ y * (sin(rad_x) * cos(rad_y)) \
	+ z * (cos(rad_x) * cos(rad_y));
}

void	convert_map_to_rotation(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->map.row)
	{
		x = -1;
		while (++x < mlx->map.column)
			calculate_arbitrary_axis_rotation(x, y, mlx->map.map[y][x], mlx);
	}
}
