/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 23:11:01 by tochen            #+#    #+#             */
/*   Updated: 2017/05/10 23:11:04 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** tetrimino buffer to shortened tetrimino piece for matching
*/

char		*input_storage_mod(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = '.';
		i++;
	}
	return (ft_strtrim_dot(buffer));
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	if (!s || !*s)
		return ;
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
}

int			ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int			ft_putstr_ret0(void)
{
	ft_putstr("error\n");
	return (0);
}
