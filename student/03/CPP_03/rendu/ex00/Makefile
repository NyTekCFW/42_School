# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchiva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 04:31:54 by lchiva            #+#    #+#              #
#    Updated: 2024/09/06 14:49:50 by lchiva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Styles de texte
COLOR_RESET = \033[0m
COLOR_BOLD = \033[1m
COLOR_DIM = \033[2m
COLOR_UNDERLINE = \033[4m
COLOR_BLINK = \033[5m
COLOR_REVERSE = \033[7m
COLOR_HIDDEN = \033[8m

# Couleurs du texte (texte / fond)
COLOR_BLACK = \033[30m
COLOR_RED = \033[31m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m
COLOR_MAGENTA = \033[35m
COLOR_CYAN = \033[36m
COLOR_WHITE = \033[37m

# Couleurs de fond
COLOR_BG_BLACK = \033[40m
COLOR_BG_RED = \033[41m
COLOR_BG_GREEN = \033[42m
COLOR_BG_YELLOW = \033[43m
COLOR_BG_BLUE = \033[44m
COLOR_BG_MAGENTA = \033[45m
COLOR_BG_CYAN = \033[46m
COLOR_BG_WHITE = \033[47m

# Styles de texte supplémentaires
COLOR_BOLD_BRIGHT = \033[1;1m
COLOR_DIM_BRIGHT = \033[2;2m
COLOR_UNDERLINE_BRIGHT = \033[4;4m
COLOR_BLINK_BRIGHT = \033[5;5m
COLOR_REVERSE_BRIGHT = \033[7;7m
COLOR_HIDDEN_BRIGHT = \033[8;8m

CC = c++
CFLAGS = -Wall -Wextra -Wno-unused -Werror -pedantic -std=c++98
RM = rm -rf
NAME = ClapTrap
OBJ_DIR = obj
SRC_DIR = ./

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
vpath %.cpp $(SRC_DIR) $(shell find $(SRC_DIR) -type d)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
all: init_header $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(COLOR_BOLD)$(COLOR_MAGENTA)Compilation done.$(COLOR_RESET)"
	@echo ""


$(OBJ_DIR):
	@echo "$(COLOR_CYAN)Creating directory $(OBJ_DIR)$(COLOR_RESET)"
	@mkdir -p $(OBJ_DIR)
	@chmod 755 $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ || (rm -f $@; exit 1)
	@printf "$(COLOR_BOLD)$(COLOR_CYAN)Compile %-30s ➜$(COLOR_RESET) $(COLOR_BOLD)$(COLOR_GREEN) %-30s$(COLOR_RESET) $(OK_COLOR)[✓]$(NO_COLOR)\n" $(notdir $<) $(notdir $@)

clean:
	@$(RM) $(OBJS)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)All .o files removed.$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)$(NAME) removed.$(COLOR_RESET)"

re: fclean all

init_header: 
	@clear
	@echo ".-----------------."
	@echo "| .--------------. |"
	@echo "| | ____  _____  | |"
	@echo "| ||_   \|_   _| | |"
	@echo "| |  |   \ | |   | |"
	@echo "| |  | |\ \| |   | |"
	@echo "| | _| |_\   |_  | |"
	@echo "| ||_____|\____| | |"
	@echo "| |              | |"
	@echo "| '--------------' |"
	@echo " '----------------' "
	@echo ""
