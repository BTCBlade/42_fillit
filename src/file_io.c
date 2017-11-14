/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:07 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:27:08 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** scans buffer for invalid input
*/

int			valid_buffer_piece20(char *str)
{
	int		i;
	int		hash_count;
	int		dot_count;

	i = 0;
	hash_count = 0;
	dot_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		if (str[i] == '#')
			hash_count++;
		i++;
	}
	if (i == 20 && hash_count == 4 && dot_count == 16)
		return (1);
	return (0);
}

int			valid_buffer_piece(char *str)
{
	int		i;
	int		hash_count;
	int		dot_count;

	i = 0;
	hash_count = 0;
	dot_count = 0;
	while (str[i])
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n') ||
			((i + 1) % 5 == 0 && str[i] != '\n'))
			return (0);
		if (str[i] == '.')
			dot_count++;
		if (str[i] == '#')
			hash_count++;
		i++;
	}
	if (i <= 19 || i >= 22 || (hash_count != 4) || (dot_count != 12))
		return (0);
	if (str[i - 1] == '\n' && i == 21)
		return (1);
	if (i == 20)
		return (20);
	return (0);
}

/*
**	sets tmp->next and stores information about
*/

int			tmp_assign(t_et *tmp_list, char *tmp, char *priority, int ret_in)
{
	tmp_list->next = ft_lstnew((void *)ft_strdup(tmp), ret_in + 1, tmp_list);
	tmp_list->next->piece_identifier = piece_matching(tmp);
	tmp_list->next->priority = *priority;
	*priority = *priority + 1;
	tmp_list->is_last_piece = 0;
	tmp_list->next->x_pos = 0;
	tmp_list->next->y_pos = 0;
	free(tmp_list->next->content);
	tmp_list->next->content = NULL;
	if (tmp_list->next->piece_identifier == 'X')
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int			file_io_bot(t_et *tmp_list, char *buffer, int i)
{
	if (i == 0)
		return (ft_putstr_ret0());
	tmp_list->is_last_piece = 1;
	tmp_list->next = 0;
	if (valid_buffer_piece20(buffer) == 0)
		return (ft_putstr_ret0());
	return (i);
}

/*
** reads buffer 21 char at a time, handles input errors, each node = one tetri
*/

int			file_io(t_et *tmp_list, int fd)
{
	int			ret_in;
	char		buffer[21 + 2];
	char		*tmp;
	char		priority;
	int			i;

	i = 0;
	priority = 'A';
	while ((ret_in = read(fd, buffer, 21)) > 0)
	{
		buffer[ret_in] = '\0';
		if (valid_buffer_piece(buffer) == 0)
			return (ft_putstr_ret0());
		tmp = input_storage_mod(buffer);
		if (tmp_assign(tmp_list, tmp, &priority, ret_in) == 0)
			return (0);
		free(tmp);
		tmp_list = tmp_list->next;
		i++;
	}
	return (file_io_bot(tmp_list, buffer, i));
}
