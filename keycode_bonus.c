/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:53:51 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/26 21:53:52 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_move(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT)
	{
		mlx->coor.center_x -= 10;
		draw_new_img(mlx);
	}
	else if (keycode == RIGHT)
	{
		mlx->coor.center_x += 10;
		draw_new_img(mlx);
	}
	else if (keycode == UP)
	{
		mlx->coor.center_y -= 10;
		draw_new_img(mlx);
	}
	else if (keycode == DOWN)
	{
		mlx->coor.center_y += 10;
		draw_new_img(mlx);
	}
}

void	key_magnify(int keycode, t_mlx *mlx)
{
	if (keycode == PLUS)
	{
		mlx->coor.magnify += 1;
		draw_new_img(mlx);
	}
	else if (keycode == MINUS && mlx->coor.magnify != 0)
	{
		mlx->coor.magnify -= 1;
		draw_new_img(mlx);
	}
}

void	key_degree(int keycode, t_mlx *mlx)
{
	if (keycode == X)
	{
		if (mlx->degree.x == 360)
			mlx->degree.x = 0;
		else
			mlx->degree.x += 10;
	}
	if (keycode == Y)
	{
		if (mlx->degree.y == 360)
			mlx->degree.y = 0;
		else
			mlx->degree.y += 10;
	}
	if (keycode == Z)
	{
		if (mlx->degree.z == 360)
			mlx->degree.z = 0;
		else
			mlx->degree.z += 10;
	}
	convert_map_to_rotation(mlx);
	draw_new_img(mlx);
}

void	key_extra_view(int keycode, t_mlx *mlx)
{
	if (keycode == ONE)
	{
		mlx->degree.x = 0;
		mlx->degree.y = 0;
		mlx->degree.z = 0;
		convert_map_to_rotation(mlx);
		draw_new_img(mlx);
	}
	else if (keycode == TWO)
	{
		mlx->degree.x = 90;
		mlx->degree.y = 0;
		mlx->degree.z = 0;
		convert_map_to_rotation(mlx);
		draw_new_img(mlx);
	}
	if (keycode == THREE)
	{
		mlx->degree.x = 90;
		mlx->degree.y = 90;
		mlx->degree.z = 0;
		convert_map_to_rotation(mlx);
		draw_new_img(mlx);
	}
}

int	key_hook_bonus(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	else if (keycode == LEFT || keycode == RIGHT \
			|| keycode == UP || keycode == DOWN)
		key_move(keycode, mlx);
	else if (keycode == PLUS || keycode == MINUS)
		key_magnify(keycode, mlx);
	else if (keycode == X || keycode == Y || keycode == Z)
		key_degree(keycode, mlx);
	else if (keycode == ONE || keycode == TWO || keycode == THREE)
		key_extra_view(keycode, mlx);
	return (0);
}
