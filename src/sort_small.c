/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:38:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/29 17:52:26 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;
	t_stack	*min;

	max = max_node(*a);
	min = min_node(*a);
	if (stack_len(*a) != 3)
		return ;
	if (max->next == NULL)
		sa(a);
	else if (max->prev == NULL && max->next == min)
		ra(a);
	else if (min->prev == NULL && min->next == max)
	{
		sa(a);
		ra(a);
	}
	else if (min->next == NULL && min->prev == max)
		rra(a);
	else if (max->prev == NULL && min->next == NULL)
	{
		ra(a);
		sa(a);
	}
}

void	set_median(t_stack *stack)
{
	int		i;
	int		len;
	t_stack	*node;

	i = 0;
	node = stack;
	len = stack_len(stack);
	while (node != NULL)
	{
		node->index = i;
		if (i < (len / 2))
			node->above_median = true;
		else
			node->above_median = false;
		i++;
		node = node->next;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_median(a);
	set_median(b);
	set_target_a_to_b(a, b);
	push_cost_a_to_b(&a, &b);
	find_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_median(b);
	set_median(a);
	set_target_b_to_a(b, a);
	push_cost_b_to_a(&b, &a);
	find_cheapest(b);
}
