/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:29:34 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/19 21:23:29 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*first_from;
	t_stack	*second_from;
	t_stack	*first_to;

	first_from = *from;
	second_from = first_from->next;
	second_from->prev = NULL;
	*from = second_from;
	if (!*to)
	{
		*to = first_from;
		first_from->next = NULL;
	}
	else
	{
		first_to = *to;
		first_from->next = first_to;
		first_to->prev = first_from;
		*to = first_from;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
