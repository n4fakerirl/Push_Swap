/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:34:38 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/30 18:54:33 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack *node, int nbr)
{
	t_stack	*start;

	if (!node)
		return (0);
	start = node;
	while (start->next != NULL)
	{
		if (start->value == nbr)
			return (1);
		start = start->next;
	}
	if (start->value == nbr)
		return (1);
	else
		return (0);
}

void	free_errors(t_stack **a)
{
	t_stack	*node;
	t_stack	*next;

	if (!a || !*a)
		return ;
	node = *a;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*a = NULL;
}

void	free_both(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*next;

	free_errors(a);
	if (!b || !*b)
		return ;
	node = *b;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*b = NULL;
}

int	error_and_exit(void)
{
	ft_putstr_fd("Erreur\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}
