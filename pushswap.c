/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/21 00:37:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* - Parse (copy arg into stack A if no errors are detected)						DONE
* - Check if stack A is already sorted											DONE
* - Check stack A size and call the apropiate function (small_sort for A < 5)
*   (big_sort for everything else)
* - //OPTIONAL// run diferent algorithms and implement the fastest
* - //OPTIONAL// check list to remove canceling/useless instructions
*/

#include "pushswap.h"

int	is_sorted(int *stack)
{
	int i;

	i = 0;
	while (stack[i] && stack[i + 1])
	{
		if (stack[i] > stack[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
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
	if (is_sorted(stack->A))
	{
		ft_putstr("Stack A is already sorted\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
