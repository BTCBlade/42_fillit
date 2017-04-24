/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 09:14:17 by tochen            #+#    #+#             */
/*   Updated: 2017/03/09 19:28:58 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		k;
	char		*results;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	k = -1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i + 1] == '\0')
		return ("");
	while (ft_isspace(s[len - 1 - j]) && (i != len))
		j++;
	results = (char *)malloc(sizeof(char) * (len + 1 - i - j));
	if (!results)
		return (0);
	while (++k < (len - i - j))
		results[k] = s[i + k];
	results[k] = '\0';
	return (results);
}
