/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotated_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:15:21 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/23 21:15:22 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (!(0 <= x && x <= 1920) || !(0 <= y && y <= 1080))
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rotated_point_to_img(t_mlx *mlx, t_tuned **tuned_pos, \
t_rotate **rotated_pos)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->map.row)
	{
		x = -1;
		while (++x < mlx->map.column)
		{
			tuned_pos[y][x].x = rotated_pos[y][x].x * mlx->coor.magnify \
			+ mlx->coor.center_x;
			tuned_pos[y][x].y = rotated_pos[y][x].y * mlx->coor.magnify \
			+ mlx->coor.center_y;
			my_mlx_pixel_put(mlx, tuned_pos[y][x].x, \
			tuned_pos[y][x].y, 0x00FF0000);
		}
	}
}
