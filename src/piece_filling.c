/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:28:48 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:28:49 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	takes piece_identifer and attempts to fill grid
*/

int		piece_filling(grid_struct *grid_thing)
{
	// printf("PIECEFILLING\n");

	if (grid_thing->piece_identifier == 'X')
	{
		write(2, "X", 1);
		return (0);
	}
	if (grid_thing->piece_identifier == 'a')
		return (fill_matched_a(grid_thing));
	if (grid_thing->piece_identifier == 'b')
		return (fill_matched_b(grid_thing));
	if (grid_thing->piece_identifier == 'c')
		return (fill_matched_c(grid_thing));
	if (grid_thing->piece_identifier == 'd')
		return (fill_matched_d(grid_thing));
	if (grid_thing->piece_identifier == 'e')
		return (fill_matched_e(grid_thing));
	if (grid_thing->piece_identifier == 'f')
		return (fill_matched_f(grid_thing));
	if (grid_thing->piece_identifier == 'g')
		return (fill_matched_g(grid_thing));
	if (grid_thing->piece_identifier == 'h')
		return (fill_matched_h(grid_thing));
	if (grid_thing->piece_identifier == 'i')
		return (fill_matched_i(grid_thing));
	if (grid_thing->piece_identifier == 'j')
		return (fill_matched_j(grid_thing));
	return (piece_filling_extra(grid_thing));
}

int		piece_filling_extra(grid_struct *grid_thing)
{
	if (grid_thing->piece_identifier == 'k')
		return (fill_matched_k(grid_thing));
	if (grid_thing->piece_identifier == 'l')
		return (fill_matched_l(grid_thing));
	if (grid_thing->piece_identifier == 'm')
		return (fill_matched_m(grid_thing));
	if (grid_thing->piece_identifier == 'n')
		return (fill_matched_n(grid_thing));
	if (grid_thing->piece_identifier == 'o')
		return (fill_matched_o(grid_thing));
	if (grid_thing->piece_identifier == 'p')
		return (fill_matched_p(grid_thing));
	if (grid_thing->piece_identifier == 'q')
		return (fill_matched_q(grid_thing));
	if (grid_thing->piece_identifier == 'r')
		return (fill_matched_r(grid_thing));
	if (grid_thing->piece_identifier == 's')
		return (fill_matched_s(grid_thing));
	return (0);
}
