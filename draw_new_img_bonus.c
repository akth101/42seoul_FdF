/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:57:09 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/26 21:57:10 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_new_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
	draw_rotated_point_to_img(mlx, mlx->tuned_pos, mlx->rotate_pos);
	draw_rotated_row_line_to_img(mlx, mlx->tuned_pos);
	draw_rotated_column_line_to_img(mlx, mlx->tuned_pos);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
