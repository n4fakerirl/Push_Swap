/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:32:58 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/23 20:24:57 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = find_cheapest(*a);
	if (cheap->above_median && cheap->target->above_median)
		rotate_both(a, b, cheap);
	else if (!(cheap->above_median) && (cheap->target->above_median))
		rev_rotate_both(a, b, cheap);
	prep_for_push(a, cheap, 'a');
	prep_for_push(b, cheap->target, 'b');
	pb(a, b);
}

void move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

void min_on_top(t_stack **a)
{
	while ((*a)->value != min_node(*a)->value)
	{
		if (min_node(*a)->above_median == 1)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_median(*stack_a);
	min_on_top(stack_a);
}
