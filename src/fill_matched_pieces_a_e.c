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

int		fill_matched_a(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;

	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;

	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 4)
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j])
		{
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i + 1][j] == '.' &&
				grid_thing->grid[i + 2][j] == '.' && grid_thing->grid[i + 3][j] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 2][j] = grid_thing->priority;
				grid_thing->grid[i + 3][j] = grid_thing->priority;
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

int		fill_matched_b(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;

	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i])
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;
		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 4)
		{
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i][j + 1] == '.' &&
				grid_thing->grid[i][j + 2] == '.' && grid_thing->grid[i][j + 3] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i][j + 2] = grid_thing->priority;
				grid_thing->grid[i][j + 3] = grid_thing->priority;
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

int		fill_matched_c(grid_struct *grid_thing)
{
	int		i;
	int		j;
	int		first_iteration_flag;


	i = grid_thing->y_pos;
	j = grid_thing->x_pos;
	first_iteration_flag = 1;
	while (grid_thing->grid[i] && (grid_thing->grid_size - i) >= 2 )
	{
		if (first_iteration_flag)
			first_iteration_flag = 0;
		else
			j = 0;

		while (grid_thing->grid[i][j] && (grid_thing->grid_size - j) >= 2)
		{
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i][j + 1] == '.' &&
				grid_thing->grid[i + 1][j] == '.' && grid_thing->grid[i + 1][j + 1] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i][j + 1] = grid_thing->priority;
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

int		fill_matched_d(grid_struct *grid_thing)
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
				grid_thing->grid[i][j + 2] == '.' && grid_thing->grid[i + 1][j + 1] == '.')
 			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i][j + 2] = grid_thing->priority;
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

int		fill_matched_e(grid_struct *grid_thing)
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
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 2][j] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
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
