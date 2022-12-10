/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:14:13 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/10 21:50:28 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	memfree(Stack *stack)
{
	free(stack->b);
	free(stack->a);
	free(stack);
}

int	is_sorted(Stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	find_in(int *haystack, int needle, int len)
{
	int	i;

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
	int	i;
	int	min;
	int	distance;

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
	return (distance);
}

void	error_exit(Stack *stack)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	memfree(stack);
	exit(EXIT_FAILURE);
}
