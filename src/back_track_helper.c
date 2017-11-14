/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:02:56 by tochen            #+#    #+#             */
/*   Updated: 2017/05/09 21:02:58 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**y_upgrade_recurse(t_x *ge, t_et *current, t_et *head)
{
	current->y_pos = current->y_pos + 1;
	current->x_pos = 0;
	return (solve_plz(ge, current, head));
}

char		**x_upgrade_recurse(t_x *ge, t_et *current, t_et *head)
{
	current->x_pos = current->x_pos + 1;
	return (solve_plz(ge, current, head));
}

int			grid_upgrade_check(t_x *ge, t_et *current)
{
	if (current->priority == 'A' && current->x_pos == ge->grid_size - 1
		&& current->y_pos == ge->grid_size - 1)
	{
		return (1);
	}
	return (0);
}

int			grids_end_check(t_x *ge, t_et *current)
{
	if (ge->x_pos == ge->grid_size - 1 &&
		ge->y_pos == ge->grid_size - 1 && current->prev->priority != 0)
	{
		return (1);
	}
	return (0);
}

char		**init_recurse(t_x *ge, t_et *current, t_et *head)
{
	current->y_pos = ge->y_pos;
	current->x_pos = ge->x_pos;
	current->next->y_pos = 0;
	current->next->x_pos = 0;
	ge->y_pos = 0;
	ge->x_pos = 0;
	return (solve_plz(ge, current->next, head));
}
