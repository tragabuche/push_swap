/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:21:42 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/10 21:49:00 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stacks(int len, Stack *stack)
{
	stack->a = malloc(len * sizeof(int));
	stack->b = malloc(len * sizeof(int));
	stack->len_a = len;
	stack->len_b = 0;
	if (stack->a == NULL || stack->b == NULL)
		error_exit(stack);
}

void	get_stack(int argc, char **argv, Stack *stack)
{
	int	i;
	int	j;
	int	argv_len;

	i = 0;
	init_stacks(argc - 1, stack);
	while (stack->len_a > 1 && i < argc - 1)
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
				error_exit(stack);
		}
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (find_duplicate(stack->a, stack->len_a))
		error_exit(stack);
}

int	find_duplicate(int *stack, int len)
{
	int	i;
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
