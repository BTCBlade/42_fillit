/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:10:10 by tochen            #+#    #+#             */
/*   Updated: 2017/03/07 08:09:48 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *c)
{
	size_t			i;
	int				sign_flag;
	int				results;

	results = 0;
	sign_flag = 1;
	i = 0;
	while (ft_isspace(c[i]))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i++] == '-')
			sign_flag = -1;
	}
	if (!(c[i] >= '0' && c[i] <= '9'))
		return (0);
	while (c[i] && (c[i] >= '0' && c[i] <= '9'))
	{
		results = results * 10;
		results = results + (c[i++] - '0');
	}
	return (results * sign_flag);
}
