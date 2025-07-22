/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:32:58 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/22 18:34:17 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_stack *node, t_stack **b)
{
	t_stack	*b_node;
	t_stack	*min;

	b_node = *b;
	min = min_node(*b);
	node->target = min;
	while (b_node != NULL)
	{
		if (node->value > b_node->value && node->target->value < b_node->value)
			node->target = b_node;
		b_node = b_node->next;
	}
	if (node->value < node->target->value)
		node->target = max_node(*b);
}

// int push_cost(t_stack **a, t_stack **b)
// {

// }
