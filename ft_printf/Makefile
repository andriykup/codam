NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
		./srcs/ft_printf.c \
		./srcs/ft_printhexa.c \
		./srcs/ft_printmem.c \
		./srcs/ft_printstr.c \
		./srcs/ft_putlong.c \
		./srcs/ft_strlen.c \
		./srcs/ft_swap.c
		
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs ${NAME} ${OBJS}

clean:
	-rm -fr $(OBJS)
fclean:
	-rm -fr $(NAME)
re: fclean clean
.PHONY: all clean fclean re