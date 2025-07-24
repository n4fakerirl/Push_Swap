/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:54:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 19:53:38 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = a;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_stack	*min_node(t_stack *a)
{
	t_stack	*min;
	t_stack	*node;

	node = a;
	min = a;
	while (node != NULL)
	{
		if (min->value > node->value)
			min = node;
		node = node->next;
	}
	return (min);
}

t_stack	*max_node(t_stack *a)
{
	t_stack	*max;
	t_stack	*node;

	node = a;
	max = a;
	while (node != NULL)
	{
		if (max->value < node->value)
			max = node;
		node = node->next;
	}
	return (max);
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*node;
	t_stack	*cheapest_node;

	node = a;
	cheapest_node = node;
	while (node != NULL)
	{
		node->cheapest = false;
		if (node->push_cost < cheapest_node->push_cost)
			cheapest_node = node;
		node = node->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}
