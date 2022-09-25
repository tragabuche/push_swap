/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/25 12:16:26 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TO DO:
** small_sort():
**		Figure out the logic for stacks of size > 3 && <= 5
** push_a/b():
**		check memory access (some values might be overwritten)
** Simpliify_numbers()
** Radix_sort()
*/

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
int	sort_3(Stack *stack)
{
	if (stack->A[0] < stack->A[1] && stack->A[1] < stack->A[2])
		return(EXIT_SUCCESS);
	else if (stack->A[0] > stack->A[1] && stack->A[1] < stack->A[2]
			&& stack->A[2] < stack->A[0])
		rotate_a(stack);
	else if (stack->A[0] < stack->A[1] && stack->A[1] > stack->A[2]
			&& stack->A[2] < stack->A[0])
		reverse_rotate_a(stack);
	else
	{
		swap_a(stack);
		sort_3(stack);
	}
	return(EXIT_SUCCESS);
}

void	small_sort(Stack *stack)
{
	if (stack->lenA == 2)
	{
		if (stack->A[0] > stack->A[1])
			swap_a(stack);
	}
	else if (stack->lenA == 3)
		sort_3(stack);
	else
	{
		push_b(stack);
		push_b(stack);
		sort_3(stack);
		if (stack->B[0] < stack->A[0])
			push_a(stack);
		else if (stack->B[1] > stack->A[0])
		{
			swap_b(stack);
			push_a(stack);
		}
		else if (stack->B[0] > stack->A[stack->lenA])
		{
			push_a(stack);
			rotate_a(stack);
		}
		else if (stack->B[1] > stack->A[stack->lenA])
		{
			swap_b(stack);
			push_a(stack);
			rotate_a(stack);
		}
		else
			ft_putstr("Fucked\n");
		push_a(stack);
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	Stack *stack;

	if (argc != 2)
		return (error_msg(1));
	stack = malloc(sizeof(Stack));
	if (stack == NULL)
		return (error_msg(2));
	get_stack(argv[1], stack);
	if (is_sorted(stack))
	{
		free(stack);
		return (EXIT_SUCCESS);
	}
	if (stack->lenA <= 5)
		small_sort(stack);
	else
	{
		ft_printf("caca\n");
	}
	while (i < stack->lenA)
		ft_printf("%i ", stack->A[i++]);
	ft_putchar('\n');
	free(stack);
	return (EXIT_SUCCESS);
}
