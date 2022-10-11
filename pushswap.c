/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/10/11 22:04:17 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TO DO:
** Simplify_numbers()
** Radix_sort()
*/

#include "pushswap.h"

int	simplify(Stack *stack)
{
	int i;
	int *distances;

	i = 0;
	distances = malloc(stack->lenA * sizeof(int) - 1);
	if (distances == NULL)
		error_exit();
	while (i < stack->lenA - 1)
		distances[i++] = 0;
	i = 0;
	while (i < stack->lenA)
	{
		distances[i] = find_smallest_mod(stack->A, distances, stack->lenA);
		i++;
	}
	i = 0;
	while (i < stack->lenA)
	{
		stack->A[distances[i]] = i;
		i++;
	}
	free (distances);
	return (EXIT_SUCCESS);
}

void	radix_sort(Stack *stack)
{
	int max_n;
	int n_bits;
	int i;
	int j;

	max_n = stack->lenA - 1;
	n_bits = 0;
	while ((max_n >> n_bits) != 0)
		n_bits++;
	i = 0;
	while (i < n_bits)
	{
		j = 0;
		while (j < stack->lenA)
		{
			//ft_printf("%i >> %i&1=%i\n", stack->A[0], i, (stack->A[0] >> i)&1);
			if (((stack->A[0] >> i)&1) == 1)
				rotate_a(stack);
			else
				push_b(stack);
			j++;
		}
		while (stack->lenB)
			push_a(stack);
		i++;
	}
}

int main(int argc, char **argv)
{
	Stack *stack;

	stack = malloc(sizeof(Stack));
	if (stack == NULL)
		error_exit();
	get_stack(argc, argv, stack);
	if (!is_sorted(stack))
	{
		if (stack->lenA <= 5)
			small_sort(stack);
		else
		{
			simplify(stack);
			//print_stack(stack);
			radix_sort(stack);
		}
	}
	//print_stack(stack);
	free(stack->B);
	free(stack->A);
	free(stack);
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
