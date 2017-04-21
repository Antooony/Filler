/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:55:00 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 21:51:55 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define LETTER " OX"
# define GRID st->grid
# define GYMAX st->gy
# define GXMAX st->gx
# define FIG st->piece
# define N st->nb
# define OX st->ox
# define OY st->oy
# define PYMAX st->py
# define PXMAX st->px
# define TARX st->tarx
# define TARY st->tary
# define LASTX st->lastx
# define LASTY st->lasty
# define TESTX st->testx
# define TESTY st->testy
# include "libft/libft.h"

typedef	struct	s_fig
{
	char	**piece;
	char	**grid;
	char	*line;
	int		*ox;
	int		*oy;
	int		gy;
	int		gx;
	int		py;
	int		px;
	int		nb;
	int		lastx;
	int		lasty;
	int		tarx;
	int		tary;
	int		starty;
	int		startx;
	int		borderx;
	int		bordery;
	int		testx;
	int		testy;
	int		player;
	int		bitch;
}				t_fig;

int				border_hit(t_fig *st);
int				contact(t_fig *st);
void			get_first(t_fig *st);
int				is_first(t_fig *st);
void			define_border(t_fig *st);

void			read_line(char **s);
int				reg_search(t_fig *st);
int				rev_search(t_fig *st);

int				filler(t_fig *st);
int				distance(int x, int y, t_fig *st);
void			get_target(t_fig *st, char *s2, int y);
int				test_target(t_fig *st);

void			feedback(int x, int y, t_fig *st);
void			update_grid(t_fig *st);
void			free_tab(char **tab);
t_fig			*st_new(void);
void			write_ox(t_fig *st);
int				count_stars(t_fig *st);
char			*parse_grid(char *s);

int				check_lines(int i, int y, t_fig *st);
void			get_ox(t_fig *st);
void			get_grid(t_fig *st);
int				get_player(void);
void			get_gsize(t_fig *st, char *s);
void			get_psize(t_fig *st);
void			get_start(t_fig *st);
int				piece_in(int gx, int gy, t_fig *st);
void			get_pos2(t_fig *st);
void			get_pos(t_fig *st);

#endif
