/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:54:01 by seongjko          #+#    #+#             */
/*   Updated: 2024/02/23 18:54:18 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate_size_setting(t_mlx *mlx)
{
	mlx->coor.center_x = 1920 / 2;
	mlx->coor.center_y = 1080 / 2;
	mlx->coor.magnify = 30;
	mlx->degree.x = 35.264;
	mlx->degree.y = 45;
	mlx->degree.z = 0;
}

void	initiate_mlx_setting(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "fdf!");
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
}

void	preset_for_coordinates_handling(t_mlx *mlx, char **argv)
{
	mlx->map.map = parse_input_coordinates(mlx, argv);
	mlx->rotate_pos = secure_space_for_rotated_coordinates(mlx);
	mlx->tuned_pos = secure_space_for_tuned_coordinates(mlx);
}

void	draw_isometric_img_to_window(t_mlx *mlx)
{
	draw_rotated_point_to_img(mlx, mlx->tuned_pos, mlx->rotate_pos);
	draw_rotated_row_line_to_img(mlx, mlx->tuned_pos);
	draw_rotated_column_line_to_img(mlx, mlx->tuned_pos);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_printf("no input\n");
		return (0);
	}
	initiate_size_setting(&mlx);
	initiate_mlx_setting(&mlx);
	preset_for_coordinates_handling(&mlx, argv);
	convert_map_to_rotation(&mlx);
	draw_isometric_img_to_window(&mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, exit_hook, &mlx);
	mlx_loop(mlx.mlx);
}
