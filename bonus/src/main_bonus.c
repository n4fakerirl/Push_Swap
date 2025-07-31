/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:53:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/31 18:21:04 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <stdio.h>

void	free_all(char *line, t_stack **a, t_stack **b)
{
	free(line);
	free_errors(a);
	free_errors(b);
	write(2, "Error\n", 6);
}

int	read_fd(char *line, t_stack **a, t_stack **b)
{
	while (line != NULL)
	{
		if (!apply_instruction(line, a, b))
			return (free_all(line, a, b), 0);
		free(line);
		line = get_next_line(0);
	}
	if (stack_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (1);
		if (!init_stack_a(&a, split))
			return (ft_free(split), write(2, "Error\n", 6), 1);
		ft_free(split);
	}
	else if (!init_stack_a(&a, av + 1))
		return (free_errors(&a), write(2, "Error\n", 6), 1);
	line = get_next_line(0);
	if (!read_fd(line, &a, &b))
		return (free_both(&a, &b), 0);
	free_both(&a, &b);
}
