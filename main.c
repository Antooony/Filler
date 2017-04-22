/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 19:17:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_in2(t_fig *st)
{
	int		ret;
	int		j;

	ret = 1;
	if (FIG)
		free_tab(FIG);
	FIG = (char **)malloc(sizeof(char *) * PYMAX + 1);
	FIG[PYMAX] = NULL;
	j = -1;
	while (++j < PYMAX)
		get_next_line(0, &FIG[j]);
	if (ret)
		ret = check_fig(st);
	if (ret)
		get_ox(st);
	return (ret);
}

int		read_in(t_fig *st)
{
	int		ret;
	char	*s;

	s = NULL;
	ret = 1;
	get_next_line(0, &s);
	if (!GYMAX)
		ret = get_gsize(st, s);
	s ? ft_strdel(&s) : NULL;
	get_grid(st);
	if (ret)
		ret = check_grid(st);
	if (ret)
		ret = get_psize(st);
	if (ret)
		return (read_in2(st));
	return (ret);
}

int		filler(t_fig *st)
{
	if (!read_in(st))
		return (-1);
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
	int		i;

	i = 0;
	st = st_new();
	st->player = get_player();
	st->bitch = get_bitch(st->player);
	while (42)
	{
		if ((i = filler(st)) != 1)
			break ;
	}
	if (i == -1)
		ft_fprintf(2, "error\n");
	last_clean(st);
}
