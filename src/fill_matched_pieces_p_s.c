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

int		fill_matched_p(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;


	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 2)
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 3)
		{
			if (grid_thing->grid[i][j + 1] == '.' && grid_thing->grid[i][j + 2] == '.' &&
				grid_thing->grid[i + 1][j] == '.' && grid_thing->grid[i + 1][j + 1] == '.')
			{
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i][j + 2] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->x_pos = j;
				grid_thing->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_q(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;


	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 3)
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 2)
		{
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i + 1][j] == '.' &&
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 2][j + 1] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 2][j + 1] = grid_thing->priority;
				grid_thing->x_pos = j;
				grid_thing->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_r(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;


	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 2)
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 3)
		{
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i][j + 1] == '.' &&
				grid_thing->grid[i + 1][j +1] == '.' && grid_thing->grid[i + 1][j + 2] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 2] = grid_thing->priority;
				grid_thing->x_pos = j;
				grid_thing->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_s(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;


	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 3)
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 2)
		{
			if (grid_thing->grid[i][j + 1] == '.' && grid_thing->grid[i + 1][j] == '.' &&
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 2][j] == '.')
			{
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 2][j] = grid_thing->priority;
				grid_thing->x_pos = j;
				grid_thing->y_pos = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
