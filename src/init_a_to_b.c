/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:33:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/29 17:46:15 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_a_to_b(t_stack *a, t_stack *b)
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
			if (current_b->value < current_a->value)
			{
				if (!best_target || current_b->value > best_target->value)
					best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (!best_target)
			best_target = max_node(b);
		current_a->target = best_target;
		current_a = current_a->next;
	}
}

void	set_target_b_to_a(t_stack *b, t_stack *a)
{
	t_stack	*current_b;
	t_stack	*current_a;
	t_stack	*best_target;

	current_b = b;
	while (current_b)
	{
		current_a = a;
		best_target = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value)
			{
				if (!best_target || current_a->value < best_target->value)
					best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (!best_target)
			best_target = min_node(a);
		current_b->target = best_target;
		current_b = current_b->next;
	}
}

int	calculate_cost(int index, int len, int above_median)
{
	if (above_median)
		return (index);
	return (len - index);
}

void	push_cost_a_to_b(t_stack **a, t_stack **b)
{
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;
	t_stack	*node;

	node = *a;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (node != NULL)
	{
		cost_a = calculate_cost(node->index, len_a, node->above_median);
		cost_b = calculate_cost(node->target->index, len_b,
				node->target->above_median);
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

void	push_cost_b_to_a(t_stack **b, t_stack **a)
{
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;
	t_stack	*node;

	node = *b;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (node != NULL)
	{
		cost_b = calculate_cost(node->index, len_b, node->above_median);
		cost_a = calculate_cost(node->target->index, len_a,
				node->target->above_median);
		if (node->above_median == node->target->above_median)
		{
			if (cost_b > cost_a)
				node->push_cost = cost_b;
			else
				node->push_cost = cost_a;
		}
		else
			node->push_cost = cost_a + cost_b;
		node = node->next;
	}
}
