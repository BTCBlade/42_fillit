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

int		piece_filling(t_x *ge)
{
	if (ge->piece_identifier == 'a')
		return (fill_matched_a(ge));
	if (ge->piece_identifier == 'b')
		return (fill_matched_b(ge));
	if (ge->piece_identifier == 'c')
		return (fill_matched_c(ge));
	if (ge->piece_identifier == 'd')
		return (fill_matched_d(ge));
	if (ge->piece_identifier == 'e')
		return (fill_matched_e(ge));
	if (ge->piece_identifier == 'f')
		return (fill_matched_f(ge));
	if (ge->piece_identifier == 'g')
		return (fill_matched_g(ge));
	if (ge->piece_identifier == 'h')
		return (fill_matched_h(ge));
	if (ge->piece_identifier == 'i')
		return (fill_matched_i(ge));
	if (ge->piece_identifier == 'j')
		return (fill_matched_j(ge));
	return (piece_filling_extra(ge));
}

int		piece_filling_extra(t_x *ge)
{
	if (ge->piece_identifier == 'k')
		return (fill_matched_k(ge));
	if (ge->piece_identifier == 'l')
		return (fill_matched_l(ge));
	if (ge->piece_identifier == 'm')
		return (fill_matched_m(ge));
	if (ge->piece_identifier == 'n')
		return (fill_matched_n(ge));
	if (ge->piece_identifier == 'o')
		return (fill_matched_o(ge));
	if (ge->piece_identifier == 'p')
		return (fill_matched_p(ge));
	if (ge->piece_identifier == 'q')
		return (fill_matched_q(ge));
	if (ge->piece_identifier == 'r')
		return (fill_matched_r(ge));
	if (ge->piece_identifier == 's')
		return (fill_matched_s(ge));
	return (0);
}
