/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matched_pieces_p_s.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:28:07 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:28:07 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_matched_p(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 2)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 3)
		{
			if (ge->grid[i][j + 1] == '.' && ge->grid[i][j + 2] == '.' &&
				ge->grid[i + 1][j] == '.' && ge->grid[i + 1][j + 1] == '.')
			{
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i][j + 2] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
				ge->grid[i + 1][j + 1] = ge->priority;
				ge->x_pos = j;
				ge->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_q(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 3)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 2)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i + 1][j] == '.' &&
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 2][j + 1] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
				ge->grid[i + 1][j + 1] = ge->priority;
				ge->grid[i + 2][j + 1] = ge->priority;
				ge->x_pos = j;
				ge->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_r(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 2)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 3)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i][j + 1] == '.' &&
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 1][j + 2] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i + 1][j + 1] = ge->priority;
				ge->grid[i + 1][j + 2] = ge->priority;
				ge->x_pos = j;
				ge->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_s(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 3)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 2)
		{
			if (ge->grid[i][j + 1] == '.' && ge->grid[i + 1][j] == '.' &&
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 2][j] == '.')
			{
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
				ge->grid[i + 1][j + 1] = ge->priority;
				ge->grid[i + 2][j] = ge->priority;
				ge->x_pos = j;
				ge->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
