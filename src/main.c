/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:26:13 by tochen            #+#    #+#             */
/*   Updated: 2017/03/24 16:08:12 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	char		**grid;
	tetri_list	*tetrimino_list;
	tetri_list	*head;
	grid_struct	*grid_thing;

	int			grid_size;
	int			x_pos;
	int			y_pos;

	grid_size = 2;
	x_pos = 0;
	y_pos = 0;

	head = ft_lstnew(0, 0);
	tetrimino_list = head;

	if (argc != 2)
		return (-1);

	//file IO .fillit to tetri_list 21 char piece at a time
	if (file_io(tetrimino_list, argv) == 0)
		return (0);

	grid_thing = grid_thing_init(grid_size, head, &x_pos, &y_pos);

	solve_plz(grid_thing, head, tetrimino_list->next);
	grid_print(grid_thing->grid);
	return (0);
}
