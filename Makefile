# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 21:37:24 by seongjko          #+#    #+#              #
#    Updated: 2024/02/18 13:38:03 by seongjko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = fdf

B_NAME = fdf_bonus

SRCS = convert_map_to_rotation.c draw_rotated_line.c draw_rotated_point.c \
		keycode.c main.c parsing_linked_list.c parsing_main.c \
		parsing_row_column_cnt.c rotate_coordinates.c \
		tuned_coordinates.c ./get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c parsing_check_filename.c

B_SRCS = draw_new_img_bonus.c keycode_bonus.c main_bonus.c \
		convert_map_to_rotation.c draw_rotated_line.c draw_rotated_point.c \
		parsing_linked_list.c parsing_main.c \
		parsing_row_column_cnt.c rotate_coordinates.c \
		tuned_coordinates.c ./get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c parsing_check_filename.c

OBJS = $(SRCS:.c=.o)

B_OBJS = ${B_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS =  -L./minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

LIBFTA = ./libft/libft.a
MLXA = ./minilibx/libmlx.a
PRINTFA = ./ft_printf/libftprintf.a

$(NAME) : $(OBJS)
	$(MAKE) bonus -C ./libft
	$(MAKE) -C ./minilibx
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) ${LIBFTA} ${MLXA} $(MLXFLAGS) ${PRINTFA} $^ -o ${NAME}
	
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus : ${B_NAME}

${B_NAME} : ${B_OBJS}
	$(MAKE) bonus -C ./libft
	$(MAKE) -C ./minilibx
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) ${LIBFTA} ${MLXA} $(MLXFLAGS) ${PRINTFA} $^ -o ${B_NAME}

clean:
	rm -f ${OBJS}
	rm -f ${B_OBJS}
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx clean

fclean : clean
	rm -f ${NAME}
	rm -f ${B_NAME}
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx clean

re : 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY : bonus
.PHONY : all
.PHONY : clean
.PHONY : fclean
.PHONY : re