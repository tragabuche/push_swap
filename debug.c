/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:23:56 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/11 00:09:20 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This file contais functions only relevant for debuging
** DELETE BEFORE __SET AS FINISHED__
*/

void	print_stack(Stack *stack)
{
	int	i;

	i = 0;
	ft_putstr("Stack->A=");
	while (i < stack->len_a)
		ft_printf("%i ", stack->a[i++]);
	ft_putchar('\n');
	i = 0;
	ft_putstr("Stack->B=");
	while (i < stack->len_b)
		ft_printf("%i ", stack->b[i++]);
	ft_putchar('\n');
}
