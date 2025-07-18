/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:31:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/18 18:36:59 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *find_last(t_stack *node)
{
    t_stack *last;
    
    if (!node)
        return (NULL);
    last = node;
    while (last->next != NULL)
        last = last->next;
    return (last);
}

void append_node(t_stack **stack, int nbr)
{
    t_stack *node;
    t_stack *last_node;

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

void init_stack_a(t_stack **a, char **av)
{
    int y;
    long nbr;

    y = 0;
    while (av[y])
    {
        if (error_syntax(av[y]))
            free_errors(a);
        nbr = ft_atol(av[y]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)nbr))
            free_errors(a);
        append_node(a, (int)nbr);
        y++;
    }
}
