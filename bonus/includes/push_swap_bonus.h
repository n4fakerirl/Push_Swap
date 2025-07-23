/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:35:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 00:41:44 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../includes/libft/ft_printf/ft_printf.h"
# include "../includes/libft/get_next_line.h"
# include "../includes/libft/get_next_line_bonus.h"
# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack				**init_stack_a(t_stack **a, char **av);
void				append_node(t_stack **stack, int nbr);
t_stack				*find_last(t_stack *node);
int					error_syntax(char *str);
int					error_duplicate(t_stack *node, int nbr);
void				free_errors(t_stack **a);
int					stack_len(t_stack *a);
int					stack_sorted(t_stack *a);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
int					ft_strcmp(const char *s1, const char *s2);
int					error_and_exit(void);
int					apply_instruction(char *line, t_stack **a, t_stack **b);

#endif