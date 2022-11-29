/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:21:42 by mpascual          #+#    #+#             */
/*   Updated: 2022/11/29 21:54:32 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stacks(int len, Stack *stack)
{
	stack->A = malloc(len * sizeof(int));
	stack->B = malloc(len * sizeof(int));
	stack->lenA = len;
	stack->lenB = 0;
	if (stack->A == NULL || stack->B == NULL)
		error_exit();
}

void	get_stack(int argc, char **argv, Stack *stack)
{
	int	i;
	int	j;
	int	argv_len;

	i = 0;
	init_stacks(argc - 1, stack);
	while (stack->lenA > 1 && i < argc - 1)
	{
		j = 0;
		argv_len = ft_strlen(argv[i + 1]);
		while (j < argv_len)
		{
			if (j == 0 && (argv[i + 1][j] == '-' || argv[i + 1][j] == '+'))
				j++;
			if (ft_isdigit(argv[i + 1][j]))
				j++;
			else
				error_exit();
		}
		stack->A[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (find_duplicate(stack->A, stack->lenA))
		error_exit();
}

/*
** Checking all elements of the array against any other element not previusly checked
** (O = n^2 - n)??
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
			return (1);
		i++;
	}
	return (0);
}
