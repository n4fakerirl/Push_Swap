/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:57:42 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/29 13:16:19 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rr(b, a);
	set_median(*a);
	set_median(*b);
}
