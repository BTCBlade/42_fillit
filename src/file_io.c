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
int				valid_buffer_piece(char *str)
{
	size_t		i;
	size_t		hash_count;
	size_t		dot_count;

	i = 0;
	hash_count = 0;
	dot_count = 0;
	while (str[i])
	{
		if ((i + 1) % 5 == 0 && str[i] != '\n')
			return (0);
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
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
	if  (i == 20)
		return (2);
	return (0);
}

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

/*
**	ft_lstnew named for tetri_list
*/
tetri_list	*ft_lstnew(void const *content, size_t content_size, tetri_list *prev)
{
	tetri_list *new;

	new = (tetri_list *)malloc(sizeof(tetri_list));
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

/*
** reads buffer 21 char at a time, handles input errors, each node = one tetri
*/
int			file_io(tetri_list *tmp_list, char **argv)
{
	int			input_fd;
	int			ret_in;
	char		buffer[21 + 1];
	char		*tmp;
	char		priority;

	input_fd = open(argv[1], O_RDONLY);
	priority = 'A';
	while ((ret_in = read(input_fd, buffer, 21)) > 0)
	{
		buffer[ret_in] = '\0';
		// printf("buffer:\n%s\n", buffer);
		if (!valid_buffer_piece(buffer))
		{
			ft_putstr("error\n");
			return (0);
		}
		tmp = input_storage_mod(buffer);
		// printf("tmp:\n%s\n", tmp);
		tmp_list->next = ft_lstnew((void *)ft_strdup(tmp), ret_in + 1, tmp_list);
		tmp_list->next->piece_identifier = piece_matching(tmp);
		tmp_list->next->priority = priority;
		tmp_list->is_last_piece = 0;
		priority++;
		tmp_list->next->x_pos = 0;
		tmp_list->next->y_pos = 0;
		if (tmp_list->piece_identifier == 'X' || tmp_list->piece_identifier == 'x')
		{
			ft_putstr("error\n");
			return (0);
		}
		free(tmp);
		tmp_list = tmp_list->next;
	}
	tmp_list->is_last_piece = 1;
	tmp_list->next = 0;
	close(input_fd);
	return (1);
}
