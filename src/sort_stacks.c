/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:33:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/22 17:42:44 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_median(t_stack **stack)
{
	int		i;
	int		len;
	t_stack	*node;

	i = 0;
	node = *stack;
	len = stack_len(*stack);
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

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stack(*stack_a, *stack_b);
	node = *stack_a;
	while (node != NULL)
	{
		set_target(node, stack_b);
		node = node->next;
	}
}
