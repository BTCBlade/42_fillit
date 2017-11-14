/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:28:36 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:28:37 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	initiates the ge
*/

t_x		*ge_init(int grid_size, int x_pos, int y_pos)
{
	t_x		*ret;

	ret = (t_x *)malloc(sizeof(t_x));
	if (!ret)
		return (0);
	ret->grid = grid_init(grid_create(grid_size), grid_size);
	ret->grid_size = grid_size;
	ret->priority = 'A';
	ret->piece_identifier = 'X';
	ret->x_pos = x_pos;
	ret->y_pos = y_pos;
	return (ret);
}

/*
**	returns the size of a square grid
*/

int		grid_size(char **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i][j])
	{
		j++;
	}
	return (j);
}

/*
**	at end of grid
*/

int		is_at_end_of_grid(t_x *ge)
{
	if (ge->x_pos == ge->grid_size - 1 &&
		ge->y_pos == ge->grid_size - 1)
	{
		return (1);
	}
	else
		return (0);
}

/*
**	back_track_helper.c extra function
*/

void	init_variables(t_x *ge, t_et *current)
{
	ge->piece_identifier = current->piece_identifier;
	ge->priority = current->priority;
	ge->y_pos = current->y_pos;
	ge->x_pos = current->x_pos;
}

/*
**	finds out what size we should start grid_size at
*/

int		first_gridsize(int tetri_count)
{
	int		size;

	size = 2;
	while ((size * size) - (tetri_count * 4) < 0)
		size++;
	return (size);
}
