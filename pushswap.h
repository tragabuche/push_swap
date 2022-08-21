/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:22 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/21 18:47:10 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/header.h"

typedef struct Stack {
	int	*A;
	int	*B;
	int len;
} Stack;

void	init_stacks(int len, Stack *stack);
void	get_stack(char *arg, Stack *stack);
int		find_duplicate(int *stack, int len);
int		is_sorted(Stack *stack);
int		error_msg(int	flag);
#endif
