/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:38:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/22 14:23:53 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_index(t_stack **stack)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = *stack;
	while (node != NULL)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*max;
	t_stack	*min;

	max = max_node(*a);
	min = min_node(*a);
	if (max->index == 2)
		sa(a);
	else if (max->index == 0 && min->index == 1)
		ra(a);
	else if (min->index == 0 && max->index == 1)
	{
		sa(a);
		ra(a);
	}
	else if (min->index == 2 && max->index == 1)
		rra(a);
	else if (max->index == 0 && min->index == 2)
	{
		ra(a);
		sa(a);
	}
}
