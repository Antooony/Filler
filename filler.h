/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:55:00 by adenis            #+#    #+#             */
/*   Updated: 2017/05/08 16:01:43 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define LETTER " OX"
# define TAB st->tab
# define GRID st->grid
# define GYMAX st->gy
# define GXMAX st->gx
# define FIG st->piece
# define N st->nb
# define OX st->ox
# define OY st->oy
# define PYMAX st->py
# define PXMAX st->px
# define BX st->bx
# define BY st->by
# define PADV st->padv
# define END st->end
# include "libft/libft.h"

typedef	struct	s_fig
{
	char	**tab;
	char	**piece;
	char	**grid;
	char	*line;
	int		*ox;
	int		*oy;
	int		score;
	int		gy;
	int		gx;
	int		py;
	int		px;
	int		nb;
	int		bx;
	int		by;
	int		player;
	int		adv;
	int		rot;
	int		padv;
	int		end;
}				t_fig;

int				filler(t_fig *st);
int				score_check(t_fig *st);
int				create_tab(t_fig *st);
void			count_padv(t_fig *st);
void			init_tab(t_fig *st);
void			place_piece(t_fig *st, int x, int y);

void			fill_one(int x, int y, int i, t_fig *st);
void			fill_neg(int x, int y, int i, t_fig *st);
void			fill_score(t_fig *st, int i);

int				go_hard(t_fig *st);
void			last_clean(t_fig *st);

void			feedback(int x, int y, t_fig *st);
void			free_tab(char **tab);
t_fig			*st_new(void);
void			write_ox(t_fig *st);
int				count_stars(t_fig *st);
char			*parse_grid(char *s);

int				check_lines(int i, int y, t_fig *st);
int				get_ox(t_fig *st);
int				get_grid(t_fig *st);
int				get_player(void);
int				get_gsize(t_fig *st, char *s);
int				get_psize(t_fig *st);
void			get_start(t_fig *st);
int				piece_in(int gx, int gy, t_fig *st);

int				get_adv(int p);
int				check_line(char *s);
int				check_fline(char *s);
int				check_fig(t_fig *st);
int				check_grid(t_fig *st);

#endif
