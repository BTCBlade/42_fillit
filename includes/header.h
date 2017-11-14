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

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct			s_list
{
	void				*content;
	int					content_size;
	char				piece_identifier;
	char				priority;
	struct s_list		*next;
	struct s_list		*prev;
	int					x_pos;
	int					y_pos;
	int					is_last_piece;
}						t_et;

typedef struct			s_struct
{
	char				**grid;
	int					grid_size;
	char				priority;
	char				piece_identifier;
	int					x_pos;
	int					y_pos;
}						t_x;

/*
**	back_track.c
*/
int						grid_handle(int *tetri_count);
int						first_gridsize(int tetri_count);
void					init_variables(t_x *ge, t_et *current);
char					**solve_plz(t_x *ge, t_et *current, t_et *head);

/*
** back_track_helper.c
*/
char					**init_recurse(t_x *ge, t_et *current, t_et *head);
char					**y_upgrade_recurse(t_x *ge, t_et *current, t_et *head);
char					**x_upgrade_recurse(t_x *ge, t_et *current, t_et *head);
int						grid_upgrade_check(t_x *ge, t_et *current);
int						grids_end_check(t_x *ge, t_et *current);

/*
**	file_io.c
*/
int						ft_putstr_ret0(void);
int						valid_buffer_piece(char *str);
char					*ft_strtrim_dot(char const *s);
char					*input_storage_mod(char *buffer);
t_et					*ft_lstnew(void const *content, int size, t_et *prev);
int						file_io(t_et *tmp_list, int fd);

/*
** grid_struct.c
*/
t_x						*ge_init(int grid_size, int x_pos, int y_pos);
int						grid_size(char **grid);
int						is_at_end_of_grid(t_x *ge);

/*
** piece_matching.c
*/
char					piece_matching_1(char *piece);
char					piece_matching_2(char *piece);
char					piece_matching_3(char *piece);
char					piece_matching(char *piece);

/*
** piece_filling.c
*/
int						piece_filling(t_x *ge);
int						piece_filling_extra(t_x *ge);

/*
**	fill_matched_pieces_A_E.c fill_matched_pieces_F_J.c
**	fill_matched_pieces_K_O.c fill_matched_pieces_P_S.c
*/
int						fill_matched_a(t_x *ge);
int						fill_matched_b(t_x *ge);
int						fill_matched_c(t_x *ge);
int						fill_matched_d(t_x *ge);
int						fill_matched_e(t_x *ge);

int						fill_matched_f(t_x *ge);
int						fill_matched_g(t_x *ge);
int						fill_matched_h(t_x *ge);
int						fill_matched_i(t_x *ge);
int						fill_matched_j(t_x *ge);

int						fill_matched_k(t_x *ge);
int						fill_matched_l(t_x *ge);
int						fill_matched_m(t_x *ge);
int						fill_matched_n(t_x *ge);
int						fill_matched_o(t_x *ge);

int						fill_matched_p(t_x *ge);
int						fill_matched_q(t_x *ge);
int						fill_matched_r(t_x *ge);
int						fill_matched_s(t_x *ge);

/*
**	libft......
*/
void					ft_putchar(char c);
int						ft_strlen(const char *str);
void					*ft_memcpy(void *dst, const void *src, int n);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *src);
char					*ft_strcpy(char *dest, const char *src);
void					ft_putstr(char *str);
int						valid_buffer_piece20(char *str);

/*
** grid_file.c
*/
char					**grid_create(int size);
char					**grid_init(char **grid, int size);
int						grid_piece_inside(char **grid, char priority);
void					grid_print(char **grid);
int						grid_rm_piece(char **grid, char priority);

#endif
