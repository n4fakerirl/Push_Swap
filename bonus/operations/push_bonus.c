/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:29:34 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 01:10:14 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*first_from;
	t_stack	*second_from;
	t_stack	*first_to;

	if (!*from || !from)
		return ;
	first_from = *from;
	second_from = first_from->next;
	*from = second_from;
	if (second_from)
		second_from->prev = NULL;
	first_to = *to;
	first_from->next = first_to;
	if (first_to)
		first_to->prev = first_from;
	*to = first_from;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}
