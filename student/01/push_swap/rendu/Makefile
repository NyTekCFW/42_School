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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
OBJ_DIR = obj
SRC_DIR = ./src/

BONUS_NAME = checker
B_DIR = ./bonus
OBJ_DIR_BONUS = ./bonus/obj

SRCS := $(shell find $(SRC_DIR) -name '*.c')

vpath %.c $(SRC_DIR) $(shell find $(SRC_DIR) -type d)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
all: init_header $(OBJ_DIR) $(NAME)

BONUS_FILES = $(B_DIR)/bmain.c \
		$(B_DIR)/checker/bcheck_0.c \
		$(B_DIR)/checker/bcheck_1.c \
		$(B_DIR)/checker/bpiles.c \
		$(B_DIR)/checker/bswap_0.c \
		$(B_DIR)/checker/bswap_1.c \
		$(B_DIR)/checker/bswap_2.c \
		$(B_DIR)/checker/bswap_3.c \
		$(B_DIR)/utils/bmemory.c \
		$(B_DIR)/utils/bstring_0.c \
		$(B_DIR)/utils/bstring_1.c \
		$(B_DIR)/utils/bstring_2.c \
		$(B_DIR)/utils/bstring_3.c \
		$(B_DIR)/utils/bxsort.c

OBJ_BONUS := $(patsubst $(B_DIR)/%.c, $(OBJ_DIR_BONUS)/%.o, $(BONUS_FILES))

$(OBJ_DIR_BONUS):
	@echo "$(COLOR_CYAN)Creating directory $(OBJ_DIR_BONUS)$(COLOR_RESET)"
	@mkdir -p $(OBJ_DIR_BONUS) $(OBJ_DIR_BONUS)/checker $(OBJ_DIR_BONUS)/utils
	@chmod 777 $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(B_DIR)/%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@ || (rm -f $@; exit 1)
	@printf "$(COLOR_BOLD)$(COLOR_CYAN)Compile %-30s ➜$(COLOR_RESET) $(COLOR_BOLD)$(COLOR_GREEN) %-30s$(COLOR_RESET) $(OK_COLOR)[✓]$(NO_COLOR)\n" $(notdir $<) $(notdir $@)

$(BONUS_NAME): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS) -lncurses
	@echo "$(COLOR_BOLD)$(COLOR_MAGENTA)Compilation done.$(COLOR_RESET)"
	@echo ""


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lncurses
	@echo "$(COLOR_BOLD)$(COLOR_MAGENTA)Compilation done.$(COLOR_RESET)"
	@echo ""


$(OBJ_DIR):
	@echo "$(COLOR_CYAN)Creating directory $(OBJ_DIR)$(COLOR_RESET)"
	@mkdir -p $(OBJ_DIR)
	@chmod 755 $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ || (rm -f $@; exit 1)
	@printf "$(COLOR_BOLD)$(COLOR_CYAN)Compile %-30s ➜$(COLOR_RESET) $(COLOR_BOLD)$(COLOR_GREEN) %-30s$(COLOR_RESET) $(OK_COLOR)[✓]$(NO_COLOR)\n" $(notdir $<) $(notdir $@)

clean:
	@$(RM) $(OBJS) $(OBJ_BONUS)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)All .o files removed.$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)$(NAME) removed.$(COLOR_RESET)"
	@echo "$(COLOR_BOLD)$(COLOR_YELLOW)$(BONUS_NAME) removed.$(COLOR_RESET)"

re: fclean all

bonus: init_header $(OBJ_DIR_BONUS) $(BONUS_NAME)

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
