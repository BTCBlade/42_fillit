/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 03:19:38 by tochen            #+#    #+#             */
/*   Updated: 2017/03/20 03:21:15 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_encode_one(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i] + 1;
		i++;
	}
	return (str);
}
