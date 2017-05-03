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

int	ft_lstlen(tetri_list *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

char		*tetri_to_str(tetri_list *tetrimino_list)
{
	int		i;
	char	*ret;
	int		lst_len = ft_lstlen(tetrimino_list);
	ret = (char *)malloc(sizeof(char) * (lst_len + 1));
	ret[0] = 'Z';
	i = 1;
	while (tetrimino_list)
	{
		ret[i] = tetrimino_list->piece_identifier;
		tetrimino_list = tetrimino_list->next;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int			main(int argc, char **argv)
{
	char		**grid;
	tetri_list	*tetrimino_list;
	tetri_list	*head;
	grid_struct	*grid_thing;
	char		*tetri_str;

	int			grid_size;
	int			x_pos;
	int			y_pos;

	grid_size = 2;
	x_pos = 0;
	y_pos = 0;

	head = ft_lstnew(0, 0, 0);
	tetrimino_list = head;

	if (argc != 2)
		return (-1);
	//file IO .fillit to tetri_list 21 char piece at a time
	if (file_io(tetrimino_list, argv) == 0)
		return (0);
	// tetri_str = tetri_to_str(tetrimino_list);
	// printf("%s\n", tetri_str);
	// while (tetrimino_list != 0)
	// {
	// 	printf("%c\n", tetrimino_list->piece_identifier);
	// 	tetrimino_list = tetrimino_list->next;
	// }

	grid_thing = grid_thing_init(grid_size, head, &x_pos, &y_pos);
	//
	// while (tetrimino_list)
	// {
	// 	printf("%s\n", (char *)tetrimino_list->content);
	// 	printf("priroity%c\n", tetrimino_list->priority);
	// 	printf("%c\n", tetrimino_list->piece_identifier);
	// 	tetrimino_list = tetrimino_list->next;
	// }
	//loop add each piece to grid for now
	// printf("pre_init: %s\n", (char *)tetrimino_list->content);
	// printf("pre_init piece_identifier: %c\n", tetrimino_list->piece_identifier);
	// tetrimino_list = tetrimino_list->next;
	// while (tetrimino_list)
	// {
	// 	grid_thing->piece_identifier = head->piece_identifier;
	// 	if (piece_filling(grid_thing) == 1)
	// 		grid_thing->priority = grid_thing->priority + 1;
	// 	tetrimino_list = tetrimino_list->next;
	// }


	grid_thing->grid = solve_plz(grid_thing, head->next, head);
	grid_print(grid_thing->grid);
	return (0);
}
