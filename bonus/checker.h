/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:36:14 by mpascual          #+#    #+#             */
/*   Updated: 2022/12/11 00:15:20 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

typedef struct Stack {
	int	*a;
	int	*b;
	int len_a;
	int	len_b;
}	Stack;

void	init_stacks(int len, Stack *stack);
int		is_sorted(Stack *stack);
void	swap_a(Stack *stack);
void	swap_b(Stack *stack);
void	swap_both(Stack *stack);
int		push_a(Stack *stack);
int		push_b(Stack *stack);
void	rotate_a(Stack *stack);
void	rotate_b(Stack *stack);
void	rotate_both(Stack *stack);
void	reverse_rotate_a(Stack *stack);
void	reverse_rotate_b(Stack *stack);
void	reverse_rotate_both(Stack *stack);

#endif