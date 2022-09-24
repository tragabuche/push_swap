/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:46:58 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/04 17:17:43 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	stop;

	stop = ft_strlen(s);
	s += ft_strlen(s);
	while (*s != c)
	{
		if (stop-- == 0)
			return (NULL);
		s--;
	}
	return ((char *)s);
}
