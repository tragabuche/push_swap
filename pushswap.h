/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:22 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/20 23:31:46 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/header.h"

typedef struct Stack {
	int	*A;
	int	*B;
} Stack;

void	init_stacks(int len, Stack *stack);
void	get_stack(char *arg, Stack *stack);
int		find_duplicate(int	*stack);
int		is_sorted(int *stack);
int		error_msg(int	flag);
#endif
