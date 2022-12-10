/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:13:08 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/11 00:08:30 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(Stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr("sa\n");
}

void	swap_b(Stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_putstr("sb\n");
}

void	swap_both(Stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_putstr("ss\n");
}

int	push_a(Stack *stack)
{
	int	i;

	if (stack->len_b == 0)
		return (0);
	i = stack->len_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = stack->b[i];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->len_b--;
	stack->len_a++;
	ft_putstr("pa\n");
	return (1);
}

int	push_b(Stack *stack)
{
	int	i;

	if (stack->len_a == 0)
		return (0);
	i = stack->len_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = stack->a[i];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->len_a--;
	stack->len_b++;
	ft_putstr("pb\n");
	return (1);
}

void	rotate_a(Stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	ft_putstr("ra\n");
}

void	rotate_b(Stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
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
	int	i;
	int	tmp;

	i = stack->len_a - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	ft_putstr("rra\n");
}

void	reverse_rotate_b(Stack *stack)
{
	int	i;
	int	tmp;

	i = stack->len_b - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	ft_putstr("rrb\n");
}

void	reverse_rotate_both(Stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	ft_putstr("rrr\n");
}
