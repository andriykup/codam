NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	main.c \
	st_split.c \
	util.c \
	sort_util.c \
	push_swap_util.c \
	error_handling.c \
	swap_command.c \
	rotate_command.c \
	push_command.c \
	rev_rotate_command.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRC) -o ${NAME}

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re