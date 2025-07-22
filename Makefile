# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 00:00:00 by ocviller          #+#    #+#            #
#    Updated: 2025/07/19 00:00:00 by ocviller         ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Sources
SRC_DIR		= src/
SRC_FILES	= main.c errors.c stack_init.c stack_utils.c sort_stacks.c sort_small.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(SRCS:.c=.o)

# Operations
OP_DIR		= operations/
OP_FILES	= swap.c rotate.c reverse_rotate.c push.c

OPS			= $(addprefix $(OP_DIR), $(OP_FILES))
OPS_OBJS	= $(OPS:.c=.o)

# Libft
LIBFT_DIR	= includes/libft/
LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# Headers
INC_DIR		= includes/
INC_FLAGS	= -I$(INC_DIR) -I$(LIBFT_DIR)

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(OPS_OBJS)
	@$(CC) $(OBJS) $(OPS_OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OPS_OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)Object files deleted!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)All executables deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
