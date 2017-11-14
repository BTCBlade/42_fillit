/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_matching.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:28:56 by tochen            #+#    #+#             */
/*   Updated: 2017/04/19 17:28:57 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**reads modified buffer string and matches to piece_identifier
*/

char	piece_matching_1(char *piece)
{
	if (ft_strcmp(piece, "#....#....#....#") == 0)
		return ('a');
	if (ft_strcmp(piece, "####") == 0)
		return ('b');
	if (ft_strcmp(piece, "##...##") == 0)
		return ('c');
	if (ft_strcmp(piece, "###...#") == 0)
		return ('d');
	if (ft_strcmp(piece, "#....##...#") == 0)
		return ('e');
	if (ft_strcmp(piece, "#...###") == 0)
		return ('f');
	if (ft_strcmp(piece, "#...##....#") == 0)
		return ('g');
	return ('x');
}

char	piece_matching_2(char *piece)
{
	if (ft_strcmp(piece, "##...#....#") == 0)
		return ('h');
	if (ft_strcmp(piece, "#....###") == 0)
		return ('i');
	if (ft_strcmp(piece, "#....#...##") == 0)
		return ('j');
	if (ft_strcmp(piece, "###....#") == 0)
		return ('k');
	if (ft_strcmp(piece, "#....#....##") == 0)
		return ('l');
	if (ft_strcmp(piece, "#..###") == 0)
		return ('m');
	if (ft_strcmp(piece, "##....#....#") == 0)
		return ('n');
	if (ft_strcmp(piece, "###..#") == 0)
		return ('o');
	return ('x');
}

char	piece_matching_3(char *piece)
{
	if (ft_strcmp(piece, "##..##") == 0)
		return ('p');
	if (ft_strcmp(piece, "#....##....#") == 0)
		return ('q');
	if (ft_strcmp(piece, "##....##") == 0)
		return ('r');
	if (ft_strcmp(piece, "#...##...#") == 0)
		return ('s');
	return ('x');
}

char	piece_matching(char *piece)
{
	if (piece_matching_1(piece) != 'x')
		return (piece_matching_1(piece));
	if (piece_matching_2(piece) != 'x')
		return (piece_matching_2(piece));
	if (piece_matching_3(piece) != 'x')
		return (piece_matching_3(piece));
	return ('X');
}
