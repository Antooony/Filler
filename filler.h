/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:55:00 by adenis            #+#    #+#             */
/*   Updated: 2017/03/13 16:40:46 by adenis           ###   ########.fr       */
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
	int		player;
	int		bitch;
}				t_fig;

void		read_line(char **s);
void		reg_search(t_fig *st);
void		rev_search(t_fig *st);

void		test_target2(t_fig *st);
void		test_target(t_fig *st);
void		filler(t_fig *st);
void		printp(t_fig *st);
void		print(t_fig *st);

void		update_grid(t_fig *st);
void		free_tab(char **tab);
t_fig		*st_new(void);
void		write_ox(t_fig *st);
int			count_stars(t_fig *st);
char		*parse_grid(char *s);

void		get_ox(t_fig *st);
void		get_grid(t_fig *st);
int			get_player(void);
void		get_gsize(t_fig *st);
void		get_psize(t_fig *st);
void		get_start(t_fig *st);
int			piece_in(int gx, int gy, t_fig *st);
void		get_pos2(t_fig *st);
void		get_pos(t_fig *st);

#endif