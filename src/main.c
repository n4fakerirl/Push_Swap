/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:53:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/30 19:57:42 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	check_sorted(t_stack **a, t_stack **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (1);
		if (!init_stack_a(&a, split))
			return (print_error(), ft_free(split), 1);
		ft_free(split);
	}
	else
		init_stack_a(&a, av + 1);
	if (!a)
		return (free_err(&a), free_err(&b), print_error(), 1);
	check_sorted(&a, &b);
	free_err(&a);
	free_err(&b);
}
