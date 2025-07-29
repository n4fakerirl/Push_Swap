/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:53:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/29 12:59:15 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (1);
	init_stack_a(&a, av + 1);
	if (!a)
		return (printf("Erreur\n"), 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (min_node(a)->index == 0)
		printf("min on top\n");
	else
		printf("no\n");
	if (stack_sorted(a))
		printf("c trie\n");
	else
		printf("c pas trie\n");
	free_errors(&a);
	free_errors(&b);
}
