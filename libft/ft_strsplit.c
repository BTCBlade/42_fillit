/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:28:00 by tochen            #+#    #+#             */
/*   Updated: 2017/03/09 21:16:55 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_pre_iter(char const *s, char c, size_t *word_len, size_t *i)
{
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	*word_len = 0;
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t		i;
	size_t		word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == (char)(c))
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != (char)(c))
			word_count++;
		while (s[i] != (char)(c) && s[i])
		{
			i++;
		}
	}
	return (word_count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			a;
	size_t			word_len;
	char			**results;

	a = 0;
	if (!s || !(results = (char **)malloc(sizeof(char *) *
		(ft_word_count(s, c) + 1))))
		return (0);
	i = 0;
	while (a < ft_word_count(s, c))
	{
		ft_pre_iter(s, c, &word_len, &i);
		while (s[i + word_len] != '\0' && s[i + word_len] != c)
			word_len++;
		if (!(results[a] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (0);
		j = 0;
		while (j < word_len)
			results[a][j++] = s[i++];
		results[a++][j] = '\0';
	}
	results[a] = 0;
	return (results);
}
