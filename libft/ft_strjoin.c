/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 08:59:51 by tochen            #+#    #+#             */
/*   Updated: 2017/03/09 09:12:46 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	char			*results;

	if (!s1 || !s2)
		return (0);
	i = 0;
	results = (char *)malloc(1 * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!results)
		return (0);
	while (s1[i])
	{
		results[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		results[i] = *s2;
		s2++;
		i++;
	}
	results[i] = '\0';
	return (results);
}
