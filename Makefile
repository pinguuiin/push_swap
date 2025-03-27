BBLACK=\033[1;30m
BRED=\033[1;31m
BGREEN=\033[1;32m
BYELLOW=\033[1;33m
BBLUE=\033[1;34m
BPURPLE=\033[1;35m
BCYAN=\033[1;36m
BWHITE=\033[1;37m
RESET=\033[0m

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./srcs/libft
LIBFT = ./srcs/libft/libft.a
SRCS_DIR = ./srcs
OBJS_DIR = ./objs
HEADER = -I./include

SRCS_FILES = block_operation.c \
			error_free.c \
			input_check.c \
			move_push.c \
			move_reverse_rotate.c \
			move_rotate.c \
			move_swap.c \
			push_swap.c \
			sort_stack.c \
			sort_three.c \
			stack_stats.c \
			utils.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(FLAGS) $(HEADER) -c $< -o $@
		@echo "✅ $(BGREEN) Compiled $^ $(RESET)"

$(NAME): $(LIBFT) $(OBJS)
		@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo "✅ $(BPURPLE) Linked $(RESET)"

clean:
		@make clean -C $(LIBFT_DIR)
		@rm -rf $(OBJS_DIR)
		@echo "✅ $(BBLUE) Cleaned .o files $(RESET)"

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@rm -f $(NAME)
		@echo "✅ $(BBLUE) Cleaned all $(RESET)"

re: fclean all

.PHONY: all clean fclean re



