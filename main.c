/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/05/05 15:30:38 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		go_hard(t_fig *st)
{
	int		x;
	int		y;
	int		in;

	y = 0;
	BX = 0;
	BY = 0;
	in = 0;
	while (y + PYMAX < GYMAX)
	{
		x = 0;
		while (x + PXMAX < GXMAX)
		{
			if (piece_in(x, y, st) && (in = 1))
			{
				feedback(x, y, st);
				break ;
			}
			x++;
		}
		y++;
	}
	if (!in)
		return (0);
	return (1);
}

int		read_in2(t_fig *st)
{
	int		ret;
	int		j;

	ret = 1;
	if (FIG)
		free_tab(FIG);
	if (!(FIG = (char **)malloc(sizeof(char *) * PYMAX + 1)))
		return (0);
	FIG[PYMAX] = NULL;
	j = -1;
	while (++j < PYMAX)
		get_next_line(0, &FIG[j]);
	if (ret)
		ret = check_fig(st);
	if (ret)
		ret = get_ox(st);
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
	if (!get_grid(st))
		return (0);
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
	st->score = 0;
	if (!read_in(st))
		return (-1);
	if (!TAB)
		create_tab(st);
	count_padv(st);
	if (END)
		return (go_hard(st));
	return (score_check(st));
}

int		main(void)
{
	t_fig	*st;
	int		i;

	i = 0;
	if (!(st = st_new()))
		return (0);
	st->player = get_player();
	if (!st->player)
		return (0);
	st->adv = get_adv(st->player);
	while (42)
	{
		if ((i = filler(st)) != 1)
			break ;
	}
	if (i == -1)
		ft_fprintf(2, "error\n");
	last_clean(st);
}
