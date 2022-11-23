/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:22 by mpascual          #+#    #+#             */
/*   Updated: 2022/11/07 13:34:12 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

typedef struct Stack {
	int	*A;
	int	*B;
	int lenA;
	int	lenB;
} Stack;

void	init_stacks(int len, Stack *stack);
void	get_stack(int argc, char **argv, Stack *stack);
int	find_duplicate(int *stack, int len);
int	is_sorted(Stack *stack);
int	sort_3(Stack *stack);
void	sort_4(Stack *stack);
void	sort_5(Stack *stack);
void	small_sort(Stack *stack);
int	find_smallest(int *stack, int len);
int	find_smallest_mod(int *stack, int *distarr, int len);
int	simplify(Stack *stack);
int	find_in(int *haystack, int needle, int len);
void	memfree(Stack *stack);
void	error_exit(void);
void	swap_a(Stack *stack);
void	swap_b(Stack *stack);
void	swap_both(Stack *stack);
int	push_a(Stack *stack);
int	push_b(Stack *stack);
void	rotate_a(Stack *stack);
void	rotate_b(Stack *stack);
void	rotate_both(Stack *stack);
void	reverse_rotate_a(Stack *stack);
void	reverse_rotate_b(Stack *stack);
void	reverse_rotate_both(Stack *stack);

/*
** DEBUG
*/
void	print_stack(Stack *stack);
#endif
