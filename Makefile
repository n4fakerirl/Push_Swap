# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 00:00:00 by ocviller          #+#    #+#              #
#    Updated: 2025/07/23 20:00:00 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# ---------------------------------------------------------------------------- #
#                            INCLUDES & LIBFT                                  #
# ---------------------------------------------------------------------------- #

INC_DIR			= includes/
INC_BONUS_DIR	= bonus/includes/
LIBFT_DIR		= includes/libft/
LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_FLAGS		= -L$(LIBFT_DIR) -lft
INC_FLAGS		= -I$(INC_DIR) -I$(LIBFT_DIR)
INC_BONUS_FLAGS	= -I$(INC_BONUS_DIR) -I$(LIBFT_DIR)

# ---------------------------------------------------------------------------- #
#                            PUSH_SWAP FILES                                   #
# ---------------------------------------------------------------------------- #

SRC_DIR			= src/
SRC_FILES		= main.c errors.c stack_init.c stack_utils.c \
				  init_a_to_b.c sort_stacks.c sort_small.c
SRCS			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS			= $(SRCS:.c=.o)

OP_DIR			= operations/
OP_FILES		= swap.c rotate.c reverse_rotate.c push.c
OPS				= $(addprefix $(OP_DIR), $(OP_FILES))
OPS_OBJS		= $(OPS:.c=.o)

# ---------------------------------------------------------------------------- #
#                            BONUS FILES (CHECKER)                             #
# ---------------------------------------------------------------------------- #

BONUS_SRC_DIR	= bonus/src/
BONUS_OP_DIR	= bonus/operations/

BONUS_SRC_FILES	= main_bonus.c errors_bonus.c stack_init_bonus.c \
				  stack_utils_bonus.c parse_op_bonus.c
BONUS_OP_FILES	= swap_bonus.c rotate_bonus.c reverse_rotate_bonus.c push_bonus.c

BONUS_SRCS		= $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC_FILES))
BONUS_OPS		= $(addprefix $(BONUS_OP_DIR), $(BONUS_OP_FILES))

BONUS_OBJS		= $(BONUS_SRCS:.c=.o)
BONUS_OPS_OBJS	= $(BONUS_OPS:.c=.o)

# ---------------------------------------------------------------------------- #
#                                 RULES                                        #
# ---------------------------------------------------------------------------- #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(OPS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(OPS_OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "\033[0;32m$(NAME) created!\033[0m"

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_OPS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(BONUS_OPS_OBJS) $(LIBFT_FLAGS) -o $(BONUS_NAME)
	@echo "\033[0;32m$(BONUS_NAME) created!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(INC_BONUS_FLAGS) -c $< -o $@

# ---------------------------------------------------------------------------- #
#                                CLEANING                                      #
# ---------------------------------------------------------------------------- #

clean:
	@$(RM) $(OBJS) $(OPS_OBJS) $(BONUS_OBJS) $(BONUS_OPS_OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "\033[0;31mObject files deleted!\033[0m"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31mAll executables deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
