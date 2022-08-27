/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/26 18:39:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* - Check stack A size and call the apropiate function (small_sort for A < 5)
*   (big_sort for everything else)
* - //OPTIONAL// run diferent algorithms and implement the fastest
* - //OPTIONAL// check list to remove canceling/useless instructions
*/

#include "pushswap.h"

int	is_sorted(Stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->A[i] > stack->A[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
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
		return (EXIT_SUCCESS);
	if (stack->len <= 5)
	{
		//small sort
	}
	else
	{
		//big sort
	}
	free(stack);
	return (EXIT_SUCCESS);
}
