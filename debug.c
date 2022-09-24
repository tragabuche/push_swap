/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:23:56 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/24 18:26:58 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This file will compile only when DEBUG mode is set in Makefile config.
** It contains functions only relevant for debuggin
*/

void	print_stack(Stack *stack, int A)
{
	int i;

	i = 0;
	if (A)
	{
		ft_putstr("Stack->A=");
		while (i < stack->lenA)
			ft_printf("%i ", stack->A[i++]);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Stack->B=");
		while (i < stack->lenB)
			ft_printf("%i ", stack->B[i++]);
		ft_putchar('\n');
	}
}