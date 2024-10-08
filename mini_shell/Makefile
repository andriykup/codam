# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 11:24:23 by aconvent          #+#    #+#              #
#    Updated: 2024/08/05 14:35:09 by aconvent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

######## Static lib Name ########

NAME = minishell

######## Directories ########

SRC_DIR = ./

FILES = \
			main \
			main_utils\
			main_utils2\
			split_pipes\
			src/add_nodes\
			src/init_structs\
			src/mini_hell \
			src/mini_hell2 \
			src/mini_hell3 \
			src/open_file \
			src/local_environ \
			src/utils/utils\
			src/utils/utils2\
			src/utils/mini_hell_utils \
			src/utils/mini_hell_utils2 \
			src/utils/ft_split \
			src/utils/ft_itoa\
			src/utils/error \
			src/commands/echo \
			src/commands/pwd \
			src/commands/cd \
			src/commands/unset \
			src/commands/export \
			src/commands/env \
			src/commands/exit \
			src/commands/commands_utils \
			src/parsing/parsing_utils \
			src/parsing/parsing_utils_2 \
			src/parsing/parsing_utils_3 \
			src/parsing/parsing \
			src/parsing/parsing_commands \
			src/parsing/parsing_quotes\
			src/parsing/parsing_quotes_2\
			src/parsing/parsing_redir

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(O_DIR), $(addsuffix .o, $(FILES)))

######## Compiler and flags ########

CC := cc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror 
######## first rule called by make ########

all : $(NAME)

######## creating the executable ########
$(NAME): $(OBJS) 
	@echo $(RED)Start compiling $(YEL)$(NAME) $(RST)
	@$(CC) $(CFLAGS) $(SRCS) -lreadline -o $(NAME)
	@echo $(GRN)Completed $(RST)

######## create the object dir if it doesn't exist ######## 

clean : 
	@echo $(RED)removing the object files $(MAG)$(OBJ_DIR)
	@rm -f $(OBJS)
	@echo $(GRN)completed $(RST)

######## same clean + removing the libprintf.h ######## 

fclean : clean 
	@echo $(RED)removing executable$(BLU) $(NAME)
	@rm $(NAME)
	@echo $(GRN)completed $(RST)
	
re : fclean all
