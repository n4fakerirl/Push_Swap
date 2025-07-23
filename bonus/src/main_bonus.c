/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:53:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/24 01:12:41 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	free_all(char *line, t_stack **a, t_stack **b)
{
	free(line);
	free_errors(a);
	free_errors(b);
	write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack_a(&a, argv + 1))
		return (free_errors(&a), write(2, "Error\n", 6), 1);
	while ((line = get_next_line(0)) != NULL)
	{
		if (!apply_instruction(line, &a, &b))
			return (free_all(line, &a, &b), 1);
		free(line);
	}
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_errors(&a);
	free_errors(&b);
	return (0);
}
