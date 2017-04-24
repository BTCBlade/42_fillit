/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:20:47 by tochen            #+#    #+#             */
/*   Updated: 2017/03/13 20:47:14 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_len_finder(char *tmp, int *i, int *n)
{
	while ((*n / 10) > 0)
	{
		tmp[*i] = (char)((*n % 10) + '0');
		*n = *n / 10;
		*i = *i + 1;
	}
	tmp[*i] = (*n + '0');
}

char		*ft_itoa(int n)
{
	char		tmp[12];
	char		*ret;
	int			i;
	int			j;
	int			neg_flag;

	i = 0;
	j = 0;
	neg_flag = 0;
	if (n == -2147483648)
		return (ft_ret_min_int(n));
	if (n < 0)
	{
		neg_flag = 1;
		n *= -1;
	}
	itoa_len_finder(tmp, &i, &n);
	if (!(ret = (char *)malloc(sizeof(char) * (neg_flag + i + 1 + 1))))
		return (0);
	if (neg_flag)
		ret[j++] = '-';
	while (i >= 0)
		ret[j++] = tmp[i--];
	ret[j] = '\0';
	return (ret);
}
