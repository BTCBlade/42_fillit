/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:51:26 by tochen            #+#    #+#             */
/*   Updated: 2017/03/08 16:04:49 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t		len;
	size_t		i;
	char		*results;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	i = 0;
	results = (char *)malloc(sizeof(char) * (len + 1));
	if (!results)
		return (0);
	while (s[i])
	{
		results[i] = f(s[i]);
		i++;
	}
	results[i] = '\0';
	return (results);
}
