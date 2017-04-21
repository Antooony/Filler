/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 21:53:07 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clean_end(t_fig *st)
{
	free_tab(FIG);
	free_tab(GRID);
	if (st->line)
		ft_strdel(&st->line);
	free(st);
}

int		get_bitch(int p)
{
	if (p == 1)
		return (2);
	else
		return (1);
}

void	read_in(t_fig *st)
{
	int		j;
	char	*s;

	s = NULL;
	get_next_line(0, &s);
	if (!GYMAX)
		get_gsize(st, s);
	s ? ft_strdel(&s) : NULL;
	get_grid(st);
	get_psize(st);
	if (FIG)
		free_tab(FIG);
	FIG = (char **)malloc(sizeof(char *) * PYMAX + 1);
	FIG[PYMAX] = NULL;
	j = -1;
	while (++j < PYMAX)
		get_next_line(0, &FIG[j]);
	get_ox(st);
}

int		filler(t_fig *st)
{
	read_in(st);
	if (is_first(st))
		define_border(st);
	if (!contact(st) && !border_hit(st))
	{
		TARX = st->borderx;
		TARY = st->bordery;
	}
	return (test_target(st));
}

int		main(void)
{
	t_fig	*st;

	st = st_new();
	st->player = get_player();
	st->bitch = get_bitch(st->player);
	while (42)
	{
		if (!filler(st))
			break ;
	}
}
