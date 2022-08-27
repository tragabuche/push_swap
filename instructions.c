/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:13:08 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/28 00:30:39 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(Stack *stack)
{
	int tmp;

	tmp = stack->A[0];
	stack->A[0] = stack->A[1];
	stack->A[1] = tmp;
	ft_putstr("sa\n");
}

void	swap_b(Stack *stack)
{
	int tmp;

	tmp = stack->A[0];
	stack->B[0] = stack->B[1];
	stack->B[1] = tmp;
	ft_putstr("sb\n");
}

void	swap_both(Stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_putstr("ss\n");
}

void	push_a(Stack *stack)
{
	int i;

	if (stack->lenB == 0)
		return;
	i = stack->lenA;
	while (i < 0)
	{
		stack->A[i] = stack->A[i - 1];
		i--;
	}
	stack->A[i] = stack->B[i]; //i should always be 0 here
	while (i < stack->lenB - 1)
	{
		stack->B[i] = stack->B[i + 1];
		i++;
	}
	stack->lenB--;
	stack->lenA++;
	ft_putstr("pa\n");
}

void	push_b(Stack *stack)
{
	int i;

	if (stack->lenA == 0)
		return;
	i = stack->lenB;
	while (i < 0)
	{
		stack->B[i] = stack->B[i - 1];
		i--;
	}
	stack->B[i] = stack->A[i]; //i should always be 0 here
	while (i < stack->lenA - 1)
	{
		stack->A[i] = stack->A[i + 1];
		i++;
	}
	stack->lenA--;
	stack->lenB++;
	ft_putstr("pb\n");
}

void	rotate_a(Stack *stack)
{
	int i;
	int tmp;

	i = 0;
	tmp = stack->A[0];
	while (i < stack->lenA - 1)
	{
		stack->A[i] = stack->A[i + 1];
		i++;
	}
	stack->A[i] = tmp;
	ft_putstr("ra\n");
}

void	rotate_b(Stack *stack)
{
	int i;
	int tmp;

	i = 0;
	tmp = stack->B[0];
	while (i < stack->lenB - 1)
	{
		stack->B[i] = stack->B[i + 1];
		i++;
	}
	stack->B[i] = tmp;
	ft_putstr("rb\n");
}

void	rotate_both(Stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	ft_putstr("rr\n");
}

void	reverse_rotate_a(Stack *stack)
{
	int i;
	int tmp;

	i = stack->lenA - 1;
	tmp = stack->A[i];
	while (i > 0)
	{
		stack->A[i] = stack->A[i - 1];
		i--;
	}
	stack->A[i] = tmp;
	ft_putstr("rra\n");
}

void	reverse_rotate_b(Stack *stack)
{
	int i;
	int tmp;

	i = stack->lenB - 1;
	tmp = stack->B[i];
	while (i > 0)
	{
		stack->B[i] = stack->B[i - 1];
		i--;
	}
	stack->B[i] = tmp;
	ft_putstr("rrb\n");
}

void	reverse_rotate_both(Stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	ft_putstr("rrr\n");
}