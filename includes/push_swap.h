/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:35:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/30 17:18:31 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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

int					error_syntax(char *str);
int					error_duplicate(t_stack *node, int nbr);
void				free_err(t_stack **a);
void				set_target_a_to_b(t_stack *a, t_stack *b);
void				set_target_b_to_a(t_stack *b, t_stack *a);
int					calculate_cost(int index, int len, int above_median);
void				push_cost_a_to_b(t_stack **a, t_stack **b);
void				push_cost_b_to_a(t_stack **b, t_stack **a);
void				check_sorted(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				set_median(t_stack *stack);
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				move_a_to_b(t_stack **a, t_stack **b);
void				move_b_to_a(t_stack **a, t_stack **b);
void				min_on_top(t_stack **a);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_last(t_stack *node);
void				append_node(t_stack **stack, int nbr);
t_stack				**init_stack_a(t_stack **a, char **av);
void				prep_for_push(t_stack **stack, t_stack *top, char name);
int					stack_sorted(t_stack *a);
int					stack_len(t_stack *a);
t_stack				*min_node(t_stack *a);
t_stack				*max_node(t_stack *a);
t_stack				*find_cheapest(t_stack *a);
void				rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap);
void				rotate_both(t_stack **a, t_stack **b, t_stack *cheap);
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

#endif