/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:34:38 by ocviller          #+#    #+#             */
/*   Updated: 2025/07/18 20:01:35 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int error_syntax(char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
        {
            printf("erreur\n");
            return (1);
        }
        i++;
    }
    printf("cest bon gg\n");
    return (0);
}