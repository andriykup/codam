NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = -L libft -lft -o
MLX42 = ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

SRC = \
	main.c \
	init.c \
	events.c \
	fractal.c \
	ft_atof.c \

OBJS = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cd MLX42 && cmake -B build && cmake --build build -j4
		$(CC) $(CFLAGS) $(SRC) $(MLX42) $(LIBFT) ${NAME}

clean:
		$(MAKE) -C ./libft clean
		rm -fr ./MLX42/build
		rm -f $(OBJS)

fclean: clean
		$(MAKE) -C ./libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re