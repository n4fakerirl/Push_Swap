/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:32:58 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/22 17:42:39 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_stack *node, t_stack **b)
{
	t_stack	*b_node;

	b_node = *b;
	while (b_node != NULL)
	{
		if (node->value < b_node->value)
			node->target = b_node;
		if (node->target)
			if (node->target->value < b_node->value
				&& node->value < b_node->value)
				node->target = b_node;
		b_node = b_node->next;
	}
	if (!node->target)
		node->target = max_node(*b);
}

// int push_cost(t_stack **a, t_stack **b)
// {

// }
