/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:06:02 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/04 16:20:58 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (n)
	{
		str[i] = 0;
		i++;
		n--;
	}
}
