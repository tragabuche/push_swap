/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:14:13 by mpascual          #+#    #+#             */
/*   Updated: 2022/10/11 22:03:49 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(Stack *stack)
{
	int i;

	i = 0;
	while (i < stack->lenA - 1)
	{
		if (stack->A[i] > stack->A[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	find_in(int *haystack, int needle, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (haystack[i] == needle)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	find_smallest_mod(int *stack, int *distarr, int len)
{
	int i;
	int min;
	int distance;

	i = 0;
	distance = 0;
	min = stack[i];
	while (i < len)
	{
		if (stack[i] < min && find_in(distarr, i, len))
		{
			min = stack[i];
			distance = i;
		}
		i++;
	}
	return(distance);
}

void	error_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);	
}