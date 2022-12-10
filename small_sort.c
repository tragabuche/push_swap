/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:52:07 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/10 21:35:12 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest(int *stack, int len)
{
	int	i;
	int	min;
	int	distance;

	i = 0;
	distance = 0;
	min = stack[i];
	while (i < len)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			distance = i;
		}
		i++;
	}
	return (distance);
}

void	small_sort(Stack *stack)
{
	if (stack->len_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
	}
	else if (stack->len_a == 3)
		sort_3(stack);
	else if (stack->len_a == 4)
		sort_4(stack);
	else
		sort_5(stack);
}

int	sort_3(Stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2])
		return (EXIT_SUCCESS);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[2] < stack->a[0])
		rotate_a(stack);
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
		reverse_rotate_a(stack);
	else
	{
		swap_a(stack);
		sort_3(stack);
	}
	return (EXIT_SUCCESS);
}

void	sort_4(Stack *stack)
{
	int	distance;

	distance = find_smallest(stack->a, stack->len_a);
	if (distance == 1)
		swap_a(stack);
	else if (distance == 2)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if (distance == 3)
		reverse_rotate_a(stack);
	push_b(stack);
	sort_3(stack);
	push_a(stack);
}

void	sort_5(Stack *stack)
{
	int	distance;

	distance = find_smallest(stack->a, stack->len_a);
	if (distance == 1)
		swap_a(stack);
	else if (distance == 2)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	else if (distance == 4)
	{
		reverse_rotate_a(stack);
	}
	push_b(stack);
	sort_4(stack);
	push_a(stack);
}
