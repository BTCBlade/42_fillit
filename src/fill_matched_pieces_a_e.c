/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matched_pieces_a_e.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:17 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:27:19 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_matched_a(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 4)
	{
		while (ge->grid[i][j])
		{
			if (ge->grid[i][j] == '.' && ge->grid[i + 1][j] == '.' &&
				ge->grid[i + 2][j] == '.' && ge->grid[i + 3][j] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
				ge->grid[i + 2][j] = ge->priority;
				ge->grid[i + 3][j] = ge->priority;
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

int		fill_matched_b(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i])
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 4)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i][j + 1] == '.' &&
				ge->grid[i][j + 2] == '.' && ge->grid[i][j + 3] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i][j + 2] = ge->priority;
				ge->grid[i][j + 3] = ge->priority;
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

int		fill_matched_c(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 2)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 2)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i][j + 1] == '.' &&
				ge->grid[i + 1][j] == '.' && ge->grid[i + 1][j + 1] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i][j + 1] = ge->priority;
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

int		fill_matched_d(t_x *ge)
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
				ge->grid[i][j + 2] == '.' && ge->grid[i + 1][j + 1] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i][j + 2] = ge->priority;
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

int		fill_matched_e(t_x *ge)
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
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 2][j] == '.')
			{
				ge->grid[i][j] = ge->priority;
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
