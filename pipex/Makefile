NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = \
	pipex.c \
	util.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(SRC) -L libft -lft -o ${NAME}

clean:
		$(MAKE) -C ./libft clean
		rm -f $(OBJS)

fclean: clean
		$(MAKE) -C ./libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re