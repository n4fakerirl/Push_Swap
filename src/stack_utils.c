/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:54:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/19 21:22:38 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(t_stack *a)
{
	t_stack	*node;
	t_stack	*tmp;

	node = a;
	while (node != NULL)
	{
		tmp = node;
		while (tmp != NULL)
		{
			if (node->value > tmp->value)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = a;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}
