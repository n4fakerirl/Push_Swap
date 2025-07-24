/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:33:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 19:29:32 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*best_target;

	current_a = a;
	while (current_a)
	{
		current_b = b;
		best_target = NULL;
		while (current_b)
		{
			if (current_b->value > current_a->value)
			{
				if (!best_target || current_b->value < best_target->value)
					best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (!best_target)
			best_target = min_node(b);
		current_a->target = best_target;
		current_a = current_a->next;
	}
}

void	push_cost(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;
	t_stack	*node;

	node = a;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (node != NULL)
	{
		if (node->above_median)
			cost_a = node->index;
		else
			cost_a = len_a - node->index;
		if (node->target->above_median)
			cost_b = node->target->index;
		else
			cost_b = len_b - node->target->index;
		if (node->above_median == node->target->above_median)
		{
			if (cost_a > cost_b)
				node->push_cost = cost_a;
			else
				node->push_cost = cost_b;
		}
		else
			node->push_cost = cost_a + cost_b;
		node = node->next;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_median(a);
	set_median(b);
	set_target(a, b);
	push_cost(a, b);
	find_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_median(b);
	set_median(a);
	set_target(b, a);
	push_cost(b, a);
	find_cheapest(b);
}
