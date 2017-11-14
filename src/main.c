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
	t_et	*tetrimino_list;
	t_et	*head;
	t_x		*ge;
	int		fd;
	int		tetri_count;

	head = ft_lstnew(0, 0, 0);
	tetrimino_list = head;
	if (argc != 2)
		return (ft_putstr_ret0());
	fd = open(argv[1], O_RDONLY);
	tetri_count = file_io(tetrimino_list, fd);
	if (tetri_count <= 0)
		return (0);
	close(fd);
	// if (grid_handle(&tetri_count) == 0)
	// 	return (ft_putstr_ret0());
	ge = ge_init(first_gridsize(tetri_count), 0, 0);
	ge->grid = solve_plz(ge, head->next, head);
	grid_print(ge->grid);
	free(ge);
	while (head)
	{
		tetrimino_list = head->next;
		free(head);
		head = tetrimino_list;
		printf("howmanytimes\n");
	}
	return (0);
}
