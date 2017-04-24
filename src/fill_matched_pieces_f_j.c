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

int		fill_matched_f(grid_struct *grid_thing)
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
			if (grid_thing->grid[i][j + 1] == '.' && grid_thing->grid[i + 1][j] == '.' &&
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 1][j + 2] == '.')
			{
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 2] = grid_thing->priority;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_g(grid_struct *grid_thing)
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
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 2][j + 1] == '.')
			{
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 2][j + 1] = grid_thing->priority;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_h(grid_struct *grid_thing)
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
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i][j + 1] == '.' &&
				grid_thing->grid[i + 1][j] == '.' && grid_thing->grid[i + 2][j] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 2][j] = grid_thing->priority;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_i(grid_struct *grid_thing)
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
			if (grid_thing->grid[i][j] == '.' && grid_thing->grid[i + 1][j] == '.' &&
				grid_thing->grid[i + 1][j + 1] == '.' && grid_thing->grid[i + 1][j + 2] == '.')
			{
				grid_thing->grid[i][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 2] = grid_thing->priority;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_matched_j(grid_struct *grid_thing)
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
			if (grid_thing->grid[i][j + 1] == '.' && grid_thing->grid[i + 1][j + 1] == '.' &&
				grid_thing->grid[i + 2][j] == '.' && grid_thing->grid[i + 2][j + 1] == '.')
			{
				grid_thing->grid[i][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 1][j + 1] = grid_thing->priority;
				grid_thing->grid[i + 2][j] = grid_thing->priority;
				grid_thing->grid[i + 2][j + 1] = grid_thing->priority;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
