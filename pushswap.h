/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:22 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/28 00:23:28 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/header.h"

typedef struct Stack {
	int	*A;
	int	*B;
	int lenA;
	int	lenB;
} Stack;

void	init_stacks(int len, Stack *stack);
void	get_stack(char *arg, Stack *stack);
int		find_duplicate(int *stack, int len);
int		is_sorted(Stack *stack);
int		sort_3(Stack *stack);
void	small_sort(Stack *stack);
int		error_msg(int	flag);

void	swap_a(Stack *stack);
void	swap_b(Stack *stack);
void	swap_both(Stack *stack);
void	push_a(Stack *stack);
void	push_b(Stack *stack);
void	rotate_a(Stack *stack);
void	rotate_b(Stack *stack);
void	rotate_both(Stack *stack);
void	reverse_rotate_a(Stack *stack);
void	reverse_rotate_b(Stack *stack);
void	reverse_rotate_both(Stack *stack);
#endif
