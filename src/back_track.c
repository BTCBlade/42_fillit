#include "header.h"

char		**solve_plz(grid_struct *grid_thing, tetri_list *current, tetri_list *head)
{
	printf("TOP\n");
	printf("current->priority:%c\n", current->priority);
	printf("current->piece_identifier: %c\n", current->piece_identifier);
	printf("grid_thing->x_pos:%d\n", grid_thing->x_pos);
	printf("grid_thing->y_pos:%d\n", grid_thing->y_pos);
	printf("current->x_pos:%d\n", current->x_pos);
	printf("current->y_pos:%d\n", current->y_pos);
	grid_print(grid_thing->grid);
	printf("\n");



	//BASECASE
	if (current == 0 && grid_dot_count(grid_thing->grid) < 4)
		return (grid_thing->grid);

	if (current->priority == 'A' && current->x_pos == grid_thing->grid_size - 1 && current->y_pos == grid_thing->grid_size - 1 )
	{
		grid_thing->priority = 'A';
		grid_thing->grid_size = grid_thing->grid_size + 1;
		grid_thing->x_pos = 0;
		grid_thing->y_pos = 0;
		free(grid_thing->grid);
		grid_thing->grid = grid_init(grid_create(grid_thing->grid_size),grid_thing->grid_size);
		head->next->x_pos = 0;
		head->next->y_pos = 0;
		return solve_plz(grid_thing, head->next, head);
	}

	grid_thing->piece_identifier = current->piece_identifier;
	grid_thing->priority = current->priority;


 	grid_thing->y_pos = current->y_pos;
	grid_thing->x_pos = current->x_pos;

	while (grid_thing->y_pos <= grid_thing->grid_size - 1)
	{
		while (grid_thing->x_pos <= grid_thing->grid_size - 1)
		{
			if (piece_filling(grid_thing) == 1)
			{
				if (current->is_last_piece == 1)
					return (grid_thing->grid);
				else
				{
					current->y_pos = grid_thing->y_pos;
					current->x_pos = grid_thing->x_pos;


					current->next->y_pos = 0;
					current->next->x_pos = 0;


					grid_thing->y_pos = 0;
					grid_thing->x_pos = 0;

					return solve_plz(grid_thing, current->next, head);
				}
			}
			else if (grid_thing->x_pos == grid_thing->grid_size - 1 && grid_thing->y_pos == grid_thing->grid_size - 1 && current->prev->priority != 0)
			{
				if (grid_rm_piece(grid_thing->grid, current->prev->priority) == 1)
				{
					if (current->prev)
					{
						current->prev->x_pos = current->prev->x_pos + 1;
						return solve_plz(grid_thing, current->prev, head);
					}
					else
						return (0);
				}
			}
			else
			{
				current->x_pos = current->x_pos + 1;
				return solve_plz(grid_thing, current, head);
			}

		}
		current->y_pos = current->y_pos + 1;
		current->x_pos = 0;
		return solve_plz(grid_thing, current, head);
	}
	return (0);
}
