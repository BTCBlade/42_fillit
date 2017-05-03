/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:28:28 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:28:29 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** mallocs and returns a 2d array grid
*/
char		**grid_create(int size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		ret[i] = (char *)malloc(sizeof(char) * (size + 1 + 1));
		i++;
	}
	return (ret);
}

/*
**	puts '.' in all the slots of a defined size 2d array grid
*/
char		**grid_init(char **grid, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

/*
**	returns the size of a square grid
*/
int 		grid_size(char **grid)
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
**	checks if a priority LETTER is inside of the grid
*/
int			grid_piece_inside(char **grid1, char priority)
{
	int		i;
	int		j;

	i = 0;
	while (grid1[i])
	{
		j = 0;
		while (grid1[i][j])
		{
			if (grid1[i][j] == priority)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** prints a 2d char array grid
*/
void		grid_print(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid[i] != 0)
	{
		j = 0;
		while (grid[i][j] != 0)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
** deletes a prioirty LETTER from 2d array grid
*/
int			grid_rm_piece(char **grid, char priority)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == priority)
			{
				grid[i][j] = '.';
				counter++;
			}
			j++;
		}
		i++;
	}

	if (counter == 4)
		return (1);
	else
		return (0);
}

/*
** checks to see how many '.' grid has
*/
int			grid_dot_count(char **grid)
{
	int		i;
	int		j;
	int		counter;

	counter = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
				counter++;;
			j++;
		}
		i++;
	}
	return (counter);
}
