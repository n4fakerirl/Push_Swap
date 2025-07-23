/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:07:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 00:59:57 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	first = *stack;
	last = find_last(*stack);
	prev = last->prev;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	prev->next = NULL;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
