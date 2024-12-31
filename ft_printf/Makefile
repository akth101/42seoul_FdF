
CC = cc

NAME = libftprintf.a

HEADER = printf.h

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c letsprint_ts.c printf_c.c printf_s.c printf_p.c \
	      printf_d.c printf_i.c printf_u.c printf_lower_x.c printf_upper_x.c \
		  printf_percent.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all fclean clean re
