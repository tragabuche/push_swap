/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:21:42 by mpascual          #+#    #+#             */
/*   Updated: 2022/10/09 22:25:11 by mpascual         ###   ########.fr       */
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
	char **nbrs;
	int	stack_len;
	int	i;

	i = 0;
	if (argc == 2)
	{
		stack_len = 0;
		nbrs = ft_split(argv[1], ' ');
		while (nbrs[stack_len] != NULL)
			stack_len++;
		init_stacks(stack_len, stack);
		while (stack_len > 1 && nbrs[i])
		{
			stack->A[i] = ft_atoi(nbrs[i]);
			i++;
		}
	}
	else
	{
		init_stacks(argc - 1, stack);
		while (stack->lenA > 1 && i < argc)
		{
			stack->A[i] = ft_atoi(argv[i + 1]);
		}
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