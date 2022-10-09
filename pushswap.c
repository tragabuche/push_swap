/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/10/09 22:29:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TO DO:
** small_sort():
**		Figure out the logic for stacks of size > 3 && <= 5
** Simplify_numbers()
** Radix_sort()
*/

#include "pushswap.h"

int	simplify(Stack *stack)
{
	int i;
	int *distances;

	i = 0;
	distances = malloc(stack->lenA * sizeof(int));
	if (distances == NULL)
		error_exit();
	while (i < stack->lenA)
		distances[i++] = 0;
	i = 0;
	while (i < stack->lenA)
	{
		distances[i] = find_smallest_mod(&stack->A[i], distances, stack->lenA);
		i++;
	}
	i = 0;
	ft_putstr("distances=");
	while (i < stack->lenA)
		ft_printf("%i ", distances[i++]);
	while (i < stack->lenA)
	{
		stack->A[distances[i]] = i;
		i++;
	}
	free (distances);
	return (EXIT_SUCCESS);
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
			print_stack(stack);
		}
	}
	//print_stack(stack);
	free(stack);
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
