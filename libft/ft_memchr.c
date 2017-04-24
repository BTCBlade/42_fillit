/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:06:34 by tochen            #+#    #+#             */
/*   Updated: 2017/03/03 14:07:11 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*tmp;
	size_t				i;

	tmp = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (tmp[i] == (unsigned char)c)
		{
			return ((void *)&s[i]);
		}
		i++;
		n--;
	}
	return (0);
}
