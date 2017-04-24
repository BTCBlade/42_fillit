/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:26:30 by tochen            #+#    #+#             */
/*   Updated: 2017/03/08 09:34:11 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*results;
	size_t		i;

	i = 0;
	results = (void *)malloc(sizeof(void) * (size));
	if (!results)
		return (0);
	while (i < size)
	{
		*((unsigned char *)results + i) = 0;
		i++;
	}
	return (results);
}
