/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:07:05 by tochen            #+#    #+#             */
/*   Updated: 2017/03/22 14:13:39 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	char				piece_identifier;
	char				priority;
	struct s_list		*next;
	struct s_list		*prev;
	int					x_pos;
	int 				y_pos;
	int					is_last_piece;
}						tetri_list;

typedef struct			some_struct
{
	char				**grid;
	size_t				grid_size;
	char				priority;
	char				piece_identifier;
	int					x_pos;
	int					y_pos;
}						grid_struct;


char		**solve_plz(grid_struct *grid_thing, tetri_list *current, tetri_list *head);
/*
**	file_io.c
*/
int			valid_buffer_piece(char *str);
char		*ft_strtrim_dot(char const *s);
char		*input_storage_mod(char *buffer);
tetri_list	*ft_lstnew(void const *content, size_t content_size, tetri_list *prev);
int 		file_io(tetri_list *tmp_list, char **argv);

/*
** grid_validation.c
*/
grid_struct	*grid_thing_init(int grid_size, tetri_list *head, int *x_pos, int *y_pos);

/*
** piece_matching.c
*/
char		piece_matching_1(char *piece);
char		piece_matching_2(char *piece);
char		piece_matching_3(char *piece);
char		piece_matching(char *piece);

/*
** piece_filling.c
*/
int			piece_filling(grid_struct *grid_thing);
int			piece_filling_extra(grid_struct *grid_thing);

/*
**	fill_matched_pieces_A_E.c fill_matched_pieces_F_J.c
	fill_matched_pieces_K_O.c fill_matched_pieces_P_S.c
*/
int			fill_matched_a(grid_struct *grid_thing);
int			fill_matched_b(grid_struct *grid_thing);
int			fill_matched_c(grid_struct *grid_thing);
int			fill_matched_d(grid_struct *grid_thing);
int			fill_matched_e(grid_struct *grid_thing);

int			fill_matched_f(grid_struct *grid_thing);
int			fill_matched_g(grid_struct *grid_thing);
int			fill_matched_h(grid_struct *grid_thing);
int			fill_matched_i(grid_struct *grid_thing);
int			fill_matched_j(grid_struct *grid_thing);

int			fill_matched_k(grid_struct *grid_thing);
int			fill_matched_l(grid_struct *grid_thing);
int			fill_matched_m(grid_struct *grid_thing);
int			fill_matched_n(grid_struct *grid_thing);
int			fill_matched_o(grid_struct *grid_thing);

int			fill_matched_p(grid_struct *grid_thing);
int			fill_matched_q(grid_struct *grid_thing);
int			fill_matched_r(grid_struct *grid_thing);
int			fill_matched_s(grid_struct *grid_thing);

/*
**	ft_libft_one.c
*/
void		ft_putchar(char c);
int			ft_strlen(const char *str);
void		*ft_memcpy(void *dst, const void *src, int n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *src);
char		*ft_strcpy(char *dest, const char *src);
void 		ft_putstr(char *str);


/*
** grid_file.c
*/
char		**grid_create(int size);
char		**grid_init(char **grid, int size);
int 		grid_size(char **grid);
int			grid_piece_inside(char **grid, char priority);
void 		grid_print(char **grid);
int			grid_rm_piece(char **grid, char priority);
int			grid_dot_count(char **grid);

#endif
