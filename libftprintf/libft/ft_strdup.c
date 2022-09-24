/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:13:50 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/04 17:13:05 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	i;
	unsigned int	l;
	char			*ptr;

	i = 0;
	l = ft_strlen(src);
	ptr = malloc(l + 1);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (src[i] != 0)
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
}
