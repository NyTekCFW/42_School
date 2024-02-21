CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c utils.c utils2.c
SRCS_SERVER = server.c utils.c utils2.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

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

all: init_header $(NAME_CLIENT) $(NAME_SERVER)


$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(COLOR_BOLD)$(COLOR_MAGENTA)Client Compilation done.$(COLOR_RESET)"
	@echo ""

$(NAME_SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(COLOR_BOLD)$(COLOR_MAGENTA)Server Compilation done.$(COLOR_RESET)"
	@echo ""

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(COLOR_BOLD)$(COLOR_CYAN)Compile %-30s ➜$(COLOR_RESET) $(COLOR_BOLD)$(COLOR_GREEN) %-30s$(COLOR_RESET) $(OK_COLOR)[✓]$(NO_COLOR)\n" $(notdir $<) $(notdir $@)

bonus: all

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)All .o files removed.$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)$(NAME_CLIENT) and $(NAME_SERVER) removed.$(COLOR_RESET)"

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
