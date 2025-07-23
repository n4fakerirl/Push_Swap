/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:17:53 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/23 19:45:21 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*nodea;
	t_stack	*nodeb;

	nodea = a;
	nodeb = b;
	if (a)
	{
		printf("Stack A : ");
		while (nodea->next != NULL)
		{
			printf("%d, ", nodea->value);
			nodea = nodea->next;
		}
		printf("%d\n", nodea->value);
	}
	if (b)
	{
		printf("Stack B : ");
		while (nodeb->next != NULL)
		{
			printf("%d, ", nodeb->value);
			nodeb = nodeb->next;
		}
		printf("%d\n", nodeb->value);
	}
}

void	print_stack2(t_stack *a, t_stack *b)
{
	t_stack	*node;
	t_stack *node2;

	node = a;
	node2 = b;
	if (a)
	{
		printf("Stack A :\n");
		while (node->next != NULL)
		{
			printf("%d : [%d] | %d\n", node->value, node->index,
				node->above_median);
			node = node->next;
		}
		printf("%d : [%d] | %d\n", node->value, node->index,
			node->above_median);
	}
	if (b)
	{
		printf("Stack B :\n");
		while (node->next != NULL)
		{
			printf("%d : [%d] | %d\n", node2->value, node2->index,
				node2->above_median);
			node2 = node2->next;
		}
		printf("%d : [%d] | %d\n", node2->value, node2->index,
			node2->above_median);
	}
}

void	print_target(t_stack *a)
{
	t_stack	*node;

	node = a;
	if (a)
	{
		printf("Stack A :\n");
		while (node->next != NULL)
		{
			if (node->target)
				printf("Valeur : %d, Target : %d\n", node->value,
					node->target->value);
			node = node->next;
		}
		if (node->target)
			printf("Valeur : %d, Target : %d\n", node->value,
				node->target->value);
	}
}

void	print_cost(t_stack *a)
{
	t_stack	*node;

	node = a;
	if (a)
	{
		printf("Stack A :\n");
		while (node->next != NULL)
		{
			if (node->target)
				printf("Valeur : %d, Push_Cost : %d\n", node->value, node->push_cost);
			node = node->next;
		}
		if (node->target)
			printf("Valeur : %d, Push_Cost : %d\n", node->value,
				node->push_cost);
	}
}