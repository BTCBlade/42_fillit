#include "header.h"

int		solve_plz(grid_struct *grid_thing, tetri_list *head, tetri_list *current)
{
	grid_struct *grid_pointer;
	while (current)
	{
			grid_thing->piece_identifier = current->piece_identifier;
			//printf("current->piece_identifier: %c\n", current->piece_identifier);
			if (piece_filling(grid_thing) == 1)
			{
				grid_thing->priority = grid_thing->priority + 1;
			}
			else
			{
				grid_thing->priority = 'A';
				grid_thing->grid_size = grid_thing->grid_size + 1;
				free(grid_thing->grid);
				grid_thing->grid = grid_init(grid_create(grid_thing->grid_size),grid_thing->grid_size);
				solve_plz(grid_thing, head, head->next);
				break;
			}
			printf("grid_thing->piece_identifier: %c\n", grid_thing->piece_identifier);
			printf("grid_thing->priority: %c\n", grid_thing->priority);

			grid_print(grid_thing->grid);
			ft_putchar('\n');
			current = current->next;
	}
	return (1);
}
