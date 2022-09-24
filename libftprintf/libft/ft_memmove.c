/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:46:49 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/04 17:09:18 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	if (src < dst)
		while (len--)
			ptrd[len] = ptrs[len];
	else
		ptrd = ft_memcpy(dst, src, len);
	return (ptrd);
}
