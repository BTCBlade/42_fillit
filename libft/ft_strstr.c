/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:08:35 by tochen            #+#    #+#             */
/*   Updated: 2017/03/03 14:08:48 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return (char *)(big);
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return (char *)(&big[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
