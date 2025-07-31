# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 19:27:15 by ocviller          #+#    #+#              #
#    Updated: 2025/07/30 19:28:35 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

LIBFT_DIR = includes/libft
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
GNL_DIR = $(LIBFT_DIR)/get_next_line

INCLUDES_DIR = includes
BONUS_INCLUDES_DIR = bonus/includes

SRC_DIR = src
OPERATIONS_DIR = operations
BONUS_SRC_DIR = bonus/src
BONUS_OPERATIONS_DIR = bonus/operations

LIBFT_A = $(LIBFT_DIR)/libft.a

HEADERS = $(INCLUDES_DIR)/push_swap.h $(LIBFT_DIR)/libft.h
BONUS_HEADERS = $(BONUS_INCLUDES_DIR)/push_swap_bonus.h $(LIBFT_DIR)/libft.h

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/errors.c \
       $(SRC_DIR)/init_a_to_b.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_stacks.c \
       $(SRC_DIR)/stack_init.c \
       $(SRC_DIR)/stack_utils.c \
       $(OPERATIONS_DIR)/push.c \
       $(OPERATIONS_DIR)/reverse_rotate.c \
       $(OPERATIONS_DIR)/rotate.c \
       $(OPERATIONS_DIR)/swap.c

BONUS_SRCS = $(BONUS_SRC_DIR)/main_bonus.c \
             $(BONUS_SRC_DIR)/errors_bonus.c \
             $(BONUS_SRC_DIR)/parse_op_bonus.c \
             $(BONUS_SRC_DIR)/stack_init_bonus.c \
             $(BONUS_SRC_DIR)/stack_utils_bonus.c \
             $(BONUS_OPERATIONS_DIR)/push_bonus.c \
             $(BONUS_OPERATIONS_DIR)/reverse_rotate_bonus.c \
             $(BONUS_OPERATIONS_DIR)/rotate_bonus.c \
             $(BONUS_OPERATIONS_DIR)/swap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(NC)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT_A) $(BONUS_OBJS)
	@echo "$(CYAN)Linking $(BONUS_NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS_NAME)
	@echo "$(GREEN)✅ $(BONUS_NAME) compiled successfully!$(NC)"

%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(BONUS_INCLUDES_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(BONUS_OPERATIONS_DIR)/%.o: $(BONUS_OPERATIONS_DIR)/%.c $(BONUS_HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(BONUS_INCLUDES_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT_A):
	@echo "$(MAGENTA)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)✅ libft compiled successfully!$(NC)"

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✅ Object files cleaned!$(NC)"

fclean: clean
	@echo "$(RED)Cleaning executables...$(NC)"
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✅ Executables cleaned!$(NC)"

re: fclean all

.PHONY: all bonus clean fclean re test test100 test500 visualizer