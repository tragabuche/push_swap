/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:35:09 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/11 00:13:44 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	store_arg(int argc, char **argv, Stack *stack)
{
	int i;

	i = 0;
	init_stacks(argc - 1, stack);
	while (stack->lenA > 1 && i < argc - 1)
	{
		stack->A[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (find_duplicate(stack->A, stack->lenA))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
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

int main(int argc, char **argv)
{
	Stack *stack;

	stack = malloc(sizeof(Stack));
	if (stack == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		get_stack(argc, argv, stack);
		//read()
		//execute instructions
		if (is_sorted(stack))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	free(stack);
	return (EXIT_SUCCESS);
}
