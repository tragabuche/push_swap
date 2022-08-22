/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:21:42 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/22 16:10:02 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stacks(int len, Stack *stack)
{
	stack->A = malloc(len * sizeof(int) + 1);
	stack->B = malloc(len * sizeof(int) + 1);
	stack->len = len;
	if (stack->A == NULL || stack->B == NULL)
	{
		error_msg(2);
		exit(EXIT_FAILURE);
	}
}

void	get_stack(char *arg, Stack *stack)
{
	char **nbrs;
	int	stack_len;
	int	i;

	nbrs = ft_split(arg, ' ');
	stack_len = 0;
	i = 0;
	while (nbrs[stack_len] != NULL)
		stack_len++;
	init_stacks(stack_len, stack);

	while (nbrs[i])
	{
		stack->A[i] = ft_atoi(nbrs[i]);
		i++;
	}
	if (find_duplicate(stack->A, stack_len))
	{
		error_msg(1);
		exit(EXIT_FAILURE);
	}
}

/*
** Checking all elements of the array against any other element not previusly checked
** (O = n^2 - n)
** This may not be the best solution...
*/

int	find_duplicate(int *stack, int len)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (stack[i] != stack[j] && j < len)
			j++;
		if (stack[i] == stack[j] && j != len)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		error_msg(int	flag)
{
	ft_putstr("Error\n");
	if (flag == 1)
		ft_putstr("Invalid argument\n");
	else if (flag == 2)
		ft_putstr("Memory allocation failed\n");
	return (EXIT_FAILURE);	
}