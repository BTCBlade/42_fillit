/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:07:05 by tochen            #+#    #+#             */
/*   Updated: 2017/03/22 14:13:39 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			grid_upgrade(t_x *ge, t_et *head)
{
	ge->priority = 'A';
	ge->grid_size = ge->grid_size + 1;
	ge->x_pos = 0;
	ge->y_pos = 0;
	free(ge->grid);
	ge->grid = grid_init(grid_create(ge->grid_size), ge->grid_size);
	head->next->x_pos = 0;
	head->next->y_pos = 0;
}

int				grid_handle(int *tetri_count)
{
	int	size;

	size = first_gridsize(*tetri_count);
	if (size == 6)
	{
		*tetri_count = *tetri_count + 1;
		return (1);
	}
	if (size >= 7)
		return (0);
	return (1);
}

char			**grid_upgrade_recurse(t_x *ge, t_et *head)
{
	grid_upgrade(ge, head);
	return (solve_plz(ge, head->next, head));
}

char			**rm_recurse(t_x *ge, t_et *current, t_et *head)
{
	if (grid_rm_piece(ge->grid, current->prev->priority) == 1
		&& current->prev != 0)
	{
		current->prev->x_pos = current->prev->x_pos + 1;
		return (solve_plz(ge, current->prev, head));
	}
	else
		return (0);
}

/*
**	printf("TOP\n");
**	printf("current->priority:%c\n", current->priority);
**	printf("current->piece_identifier: %c\n", current->piece_identifier);
**	printf("grid_thing->x_pos:%d\n", grid_thing->x_pos);
**	printf("grid_thing->y_pos:%d\n", grid_thing->y_pos);
**	printf("current->x_pos:%d\n", current->x_pos);
**	printf("current->y_pos:%d\n", current->y_pos);
**	grid_print(grid_thing->grid);
**	printf("\n");
*/

char			**solve_plz(t_x *ge, t_et *current, t_et *head)
{
	if (grid_upgrade_check(ge, current) == 1)
		return (grid_upgrade_recurse(ge, head));
	init_variables(ge, current);
	while (ge->y_pos <= ge->grid_size - 1)
	{
		while (ge->x_pos <= ge->grid_size - 1)
		{
			if (piece_filling(ge) == 1)
			{
				if (current->is_last_piece == 1)
					return (ge->grid);
				else
					return (init_recurse(ge, current, head));
			}
			else if (grids_end_check(ge, current) == 1)
				return (rm_recurse(ge, current, head));
			return (x_upgrade_recurse(ge, current, head));
		}
		return (y_upgrade_recurse(ge, current, head));
	}
	return (0);
}
