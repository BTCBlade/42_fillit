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
**	initiates the grid_thing
*/
grid_struct		*grid_thing_init(int grid_size, tetri_list *head, int *x_pos, int *y_pos)
{
	grid_struct		*ret;

	ret = (grid_struct *)malloc(sizeof(grid_struct));
	if (!ret)
		return (0);

	ret->grid = grid_init(grid_create(grid_size), grid_size);
	ret->grid_size = grid_size;
	ret->priority = 'A';
	ret->piece_identifier = 'X';
	ret->x_pos = *x_pos;
	ret->y_pos = *y_pos;

	return (ret);
}
