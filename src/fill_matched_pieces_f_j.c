/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matched_pieces_f_j.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:40 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:27:41 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_matched_f(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 2)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 3)
		{
			if (ge->grid[i][j + 1] == '.' && ge->grid[i + 1][j] == '.' &&
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 1][j + 2] == '.')
			{
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
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

int		fill_matched_g(t_x *ge)
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
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 2][j + 1] == '.')
			{
				ge->grid[i][j + 1] = ge->priority;
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

int		fill_matched_h(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 3)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 2)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i][j + 1] == '.' &&
				ge->grid[i + 1][j] == '.' && ge->grid[i + 2][j] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
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

int		fill_matched_i(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 2)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 3)
		{
			if (ge->grid[i][j] == '.' && ge->grid[i + 1][j] == '.' &&
				ge->grid[i + 1][j + 1] == '.' && ge->grid[i + 1][j + 2] == '.')
			{
				ge->grid[i][j] = ge->priority;
				ge->grid[i + 1][j] = ge->priority;
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

int		fill_matched_j(t_x *ge)
{
	int		i;
	int		j;

	i = ge->y_pos;
	j = ge->x_pos;
	while (ge->grid[i] && (ge->grid_size - i) >= 3)
	{
		while (ge->grid[i][j] && (ge->grid_size - j) >= 2)
		{
			if (ge->grid[i][j + 1] == '.' && ge->grid[i + 1][j + 1] == '.' &&
				ge->grid[i + 2][j] == '.' && ge->grid[i + 2][j + 1] == '.')
			{
				ge->grid[i][j + 1] = ge->priority;
				ge->grid[i + 1][j + 1] = ge->priority;
				ge->grid[i + 2][j] = ge->priority;
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
