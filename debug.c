/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:23:56 by mpascual          #+#    #+#             */
/*   Updated: 2022/11/23 20:45:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This file contais functions only relevant for debuging
** DELETE BEFORE __SET AS FINISHED__
*/

void	print_stack(Stack *stack)
{
	int i;

	i = 0;
	ft_putstr("Stack->A=");
	while (i < stack->lenA)
		ft_printf("%i ", stack->A[i++]);
	ft_putchar('\n');
	i = 0;
	ft_putstr("Stack->B=");
	while (i < stack->lenB)
		ft_printf("%i ", stack->B[i++]);
	ft_putchar('\n');
	ft_printf("len->A=%i\n", stack->lenA);
	ft_printf("len->B=%i\n", stack->lenB);
}