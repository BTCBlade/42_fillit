/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:35:00 by tochen            #+#    #+#             */
/*   Updated: 2017/03/03 14:05:17 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_copy;
	unsigned char const	*src_copy;
	size_t				i;

	dst_copy = (unsigned char *)dst;
	src_copy = (unsigned char const*)src;
	i = 0;
	while (i < n)
	{
		dst_copy[i] = src_copy[i];
		if (src_copy[i] == (unsigned char)(c))
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
