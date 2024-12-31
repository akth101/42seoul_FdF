/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:50:25 by seongjko          #+#    #+#             */
/*   Updated: 2024/01/22 15:50:27 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define PLUS 24 
# define MINUS 27
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define X 7
# define Y 16
# define Z 6
# define ONE 18
# define TWO 19
# define THREE 20

typedef struct s_1d_equation {
	double	m;
	double	b;
}				t_1d_equation;

typedef struct s_map {
	int	column;
	int	row;
	int	**map;
}				t_map;

typedef struct s_rotate {
	double	x;
	double	y;
	double	z;
}				t_rotate;

typedef struct s_tuned {
	double	x;
	double	y;
	double	z;
}				t_tuned;

typedef struct s_degree {
	double	x;
	double	y;
	double	z;
}				t_degree;

typedef struct s_coor {
	int	center_x;
	int	center_y;
	int	magnify;
}				t_coor;

typedef struct s_mlx {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		map;
	t_coor		coor;
	t_degree	degree;
	t_rotate	**rotate_pos;
	t_tuned		**tuned_pos;
}				t_mlx;

typedef struct s_equation {
	int	x;
	int	y;
}				t_equation;

int			**parse_input_coordinates(t_mlx *mlx, char **argv);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void		free_linked_list(t_list *head);
int			row_cnt(t_list *list);
int			column_cnt(t_list *list);
int			row_column_cnt(t_mlx *mlx, t_list *list);
t_list		*create_linked_list(int fd);
void		free_content(void *content);
void		free_linked_list(t_list *head);
t_rotate	**secure_space_for_rotated_coordinates(t_mlx *mlx);
int			key_hook(int keycode, t_mlx *mlx);
int			key_hook_bonus(int keycode, t_mlx *mlx);
void		convert_map_to_rotation(t_mlx *mlx);
void		draw_rotated_point_to_img(t_mlx *mlx, t_tuned **tuned_pos, \
t_rotate **rotated_pos);
void		integer_to_x_rotate(t_tuned first, t_tuned second, \
t_1d_equation info, t_mlx *mlx);
void		integer_to_y_rotate(t_tuned first, t_tuned second, \
t_1d_equation info, t_mlx *mlx);
void		draw_rotated_line(t_tuned first, t_tuned second, t_mlx *mlx);
void		draw_rotated_row_line_to_img(t_mlx *mlx, t_tuned **tuned_pos);
void		draw_rotated_column_line_to_img(t_mlx *mlx, t_tuned **tuned_pos);
t_tuned		**secure_space_for_tuned_coordinates(t_mlx *mlx);
t_tuned		*create_1d_ary_tuned(int column);
void		initiate_size_setting(t_mlx *mlx);
void		initiate_mlx_setting(t_mlx *mlx);
void		preset_for_coordinates_handling(t_mlx *mlx, char **argv);
void		free_char_ary(char	**char_ary);
int			*create_1d_ary(t_list *list, int column);
int			**create_2d_ary(t_list *head, t_mlx *mlx);
void		is_file_opened(int fd, char *filename);
t_rotate	*create_1d_ary_rotate(int column);
t_rotate	**secure_space_for_rotated_coordinates(t_mlx *mlx);
t_tuned		*create_1d_ary_tuned(int column);
t_tuned		**secure_space_for_tuned_coordinates(t_mlx *mlx);
int			check_valid_char_ary(char *ary);
void		draw_new_img(t_mlx *mlx);
void		key_extra_view(int keycode, t_mlx *mlx);
int			exit_hook(t_mlx *mlx);
int			check_file_name(char *file_name);

#endif
