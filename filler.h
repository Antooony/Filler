/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:55:00 by adenis            #+#    #+#             */
/*   Updated: 2017/03/02 17:09:54 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define LETTER " OX"
# define GRID st->grid
# define GYMAX st->gy
# define GXMAX st->gx
# define FIG st->piece
# define PYMAX st->py
# define PXMAX st->px
# include "libft/libft.h"

typedef	struct	s_fig
{
	char	**piece;
	char	**grid;
	char	*line;
	int		gy;
	int		gx;
	int		py;
	int		px;
	int		starty;
	int		startx;
	int		player;
}				t_fig;

void		free_tab(char **tab);
t_fig		*st_new(void);
void		filler(t_fig *st);
char		*parse_grid(char *s);
int			get_player(void);
void		get_gsize(t_fig *st);
void		get_psize(t_fig *st);
void		get_start(t_fig *st);
int			piece_in(int gx, int gy, t_fig *st);
void		get_pos(t_fig *st);

#endif