/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotated_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:15:41 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/23 21:15:42 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	integer_to_x_rotate(t_tuned first, t_tuned second, t_1d_equation info, \
t_mlx *mlx)
{
	double	x;
	double	y;

	if (first.x < second.x)
	{
		x = first.x;
		while (x <= second.x)
		{
			y = info.m * x + info.b;
			my_mlx_pixel_put(mlx, x, y, 0x0000FF00);
			x++;
		}
	}
	else
	{
		x = second.x;
		while (x <= first.x)
		{
			y = info.m * x + info.b;
			my_mlx_pixel_put(mlx, x, y, 0x0000FF00);
			x++;
		}	
	}
}

void	integer_to_y_rotate(t_tuned first, t_tuned second, t_1d_equation info, \
t_mlx *mlx)
{
	double	x;
	double	y;
	double	y_end;

	if (first.y < second.y)
	{
		y = first.y;
		y_end = second.y;
	}
	else
	{
		y = second.y;
		y_end = first.y;
	}
	while (y <= y_end)
	{
		if (info.m == 0)
			x = first.x;
		else
			x = (y - info.b) / info.m;
		my_mlx_pixel_put(mlx, x, y, 0x00FF0000);
		y++;
	}
}

void	draw_rotated_line(t_tuned first, t_tuned second, t_mlx *mlx)
{
	t_1d_equation	info;

	if (second.y - first.y == 0 || second.x - first.x == 0)
		info.m = 0;
	else
		info.m = (double)(second.y - first.y) / (double)(second.x - first.x);
	info.b = first.y - info.m * first.x;
	if (info.m == 0 && second.y - first.y == 0)
		integer_to_x_rotate(first, second, info, mlx);
	else if (info.m == 0 && second.x - first.x == 0)
		integer_to_y_rotate(first, second, info, mlx);
	else if (info.m != 0 && (-1 <= info.m && info.m <= 1))
		integer_to_x_rotate(first, second, info, mlx);
	else
		integer_to_y_rotate(first, second, info, mlx);
}

void	draw_rotated_row_line_to_img(t_mlx *mlx, t_tuned **tuned_pos)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->map.row)
	{
		x = -1;
		while (++x < mlx->map.column - 1)
			draw_rotated_line(tuned_pos[y][x], tuned_pos[y][x + 1], mlx);
	}
}

void	draw_rotated_column_line_to_img(t_mlx *mlx, t_tuned **tuned_pos)
{
	int	y;
	int	x;

	x = -1;
	while (++x < mlx->map.column)
	{
		y = -1;
		while (++y < mlx->map.row - 1)
			draw_rotated_line(tuned_pos[y][x], tuned_pos[y + 1][x], mlx);
	}
}
