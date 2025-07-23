/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:57:42 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 00:59:54 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	first = *stack;
	next = first->next;
	last = find_last(*stack);
	next->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*stack = next;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
