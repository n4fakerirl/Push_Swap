/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:31:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/23 23:24:43 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_stack	*find_last(t_stack *node)
{
	t_stack	*last;

	if (!node)
		return (NULL);
	last = node;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	**init_stack_a(t_stack **a, char **av)
{
	int		y;
	long	nbr;

	y = 0;
	while (av[y])
	{
		if (error_syntax(av[y]))
			return (free_errors(a), NULL);
		nbr = ft_atol(av[y]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (free_errors(a), NULL);
		if (error_duplicate(*a, (int)nbr))
			return (free_errors(a), NULL);
		append_node(a, (int)nbr);
		y++;
	}
	return (a);
}
