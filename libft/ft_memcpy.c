/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:31:38 by tochen            #+#    #+#             */
/*   Updated: 2017/03/02 21:39:35 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_container;
	unsigned char	*src_container;
	size_t			i;

	dst_container = (unsigned char *)dst;
	src_container = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_container[i] = src_container[i];
		i++;
	}
	return (dst);
}
