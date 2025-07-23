/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:38:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/23 20:40:13 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;
	t_stack	*min;

	max = max_node(*a);
	min = min_node(*a);
	if (max->next == NULL)
		sa(a);
	else if (max->prev == NULL && max->next == min)
		ra(a);
	else if (min->prev == NULL && min->next == max)
	{
		sa(a);
		ra(a);
	}
	else if (min->next == NULL && min->prev == max)
		rra(a);
	else if (max->prev == NULL && min->next == NULL)
	{
		ra(a);
		sa(a);
	}
}
