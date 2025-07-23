/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:07:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/23 18:57:10 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*prev;
	t_stack	*last;

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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rrr(a, b);
	set_median(*a);
	set_median(*b);
}