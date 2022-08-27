/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/28 00:50:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TO DO:
** small_sort():
**		make sure stackA can accomodate the 2 numbers from stackB before pushing
**		them back to stackA
** push_a/b():
**		check memory access (some values might be overwritten)
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
	int i;

	i = 0;
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
		if (stack->B[0] < stack->B[1])
			swap_b(stack);
		push_a(stack);
		push_a(stack);
	}
}

int main(int argc, char **argv)
{
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
		//big sort
	}
	free(stack);
	return (EXIT_SUCCESS);
}
