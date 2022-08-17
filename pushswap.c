/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:31:04 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/16 17:46:11 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* - Parse (copy arg into stack A if no errors are detected)
* - Check if stack A is already sorted
* - Check stack A size and call the apropiate function (small_sort for A < 5)
*   (big_sort for everything else)
* - //OPTIONAL// run diferent algorithms and implement the fastest
 - 
*/

#include "pushswap.h"

int	get_stack(char *argv, Stack *stack)
{
	
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	int i;
	Stack *stack;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (EXIT_FAILURE);
	}
	init_stack();
	if (get_stack(argv[2], stack) != 0)
	{
		error 
	}
	
	return (0);
}
