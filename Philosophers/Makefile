######## Colours ########

RST = "\033[0m"
RED = "\033[31m"
GRN = "\033[32m"
YEL = "\033[33m"
BLU = "\033[34m"
MAG = "\033[35m"
CYN = "\033[36m"
WHT = "\033[37m"

######## Typographicals ########

BLD = "\033[1m"
FNT = "\033[2m"
ITA = "\033[3m"
UNL = "\033[4m"

######## ------------- ########

NAME = philo
CC = cc -pthread #-fsanitize=thread -g #-fsanitize=address -g
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)

SRC = \
	main.c \
	./src/input_check.c \
	./src/checks.c \
	./src/utils.c \
	./src/philo_init.c \
	./src/start_party.c \
	./src/p_routine.c \
	./src/exit.c \
	./src/print.c \

all: $(NAME)

$(NAME): $(OBJS)
		@echo $(GRN)"Compiling..." $(YEL)$(NAME)$(RST)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)
		@echo $(GRN)"\n\n			Compilation Completed :)\n\n" $(RST)

clean:
		@echo $(RED)"removing object files"$(RST)
		rm -f $(OBJS)
		@echo $(GRN)"request completed"$(RST)

fclean: clean
		@echo $(RED)"removing executable" $(YEL)$(NAME)$(RST)
		@rm -f $(NAME)
		@echo $(GRN)"request completed"$(RST)

re:	fclean all

.PHONY: all clean fclean re