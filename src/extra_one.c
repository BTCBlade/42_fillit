/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 23:05:19 by tochen            #+#    #+#             */
/*   Updated: 2017/05/10 23:05:33 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** cuts front and back '.' of input buffer tetrimino
*/

char		*ft_strtrim_dot(char const *s)
{
	int			i;
	int			j;
	int			len;
	int			k;
	char		*results;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	k = -1;
	while (s[i] == '.')
		i++;
	if (s[i + 1] == '\0')
		return ("X");
	while (s[len - 1 - j] == '.' && (i != len))
		j++;
	results = (char *)malloc(sizeof(char) * (len + 1 - i - j));
	if (!results)
		return (0);
	while (++k < (len - i - j))
		results[k] = s[i + k];
	results[k] = '\0';
	return (results);
}

/*
**	ft_lstnew named for t_et
*/

t_et		*ft_lstnew(void const *content, int content_size, t_et *prev)
{
	t_et *new;

	new = (t_et *)malloc(sizeof(t_et));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void*)malloc(content_size);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = prev;
	return (new);
}

void		*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst_container;
	unsigned char	*src_container;
	int				i;

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

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	return (t1[i] - t2[i]);
}

char		*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(src);
	i = 0;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!src || !str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
