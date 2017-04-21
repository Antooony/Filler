/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 20:44:02 by adenis           ###   ########.fr       */
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

int		contact(t_fig *st)
{
	int		x;
	int		y;

	y = 0;
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			if (GRID[y][x] == LETTER[st->player] 
				&& (GRID[y + 1][x] == LETTER[st->bitch]
					|| GRID[y][x + 1] == LETTER[st->bitch]
						|| GRID[y + 1 ][x + 1] == LETTER[st->bitch]))
			return (1);
			if (GRID[y][x] == LETTER[st->bitch] 
				&& (GRID[y + 1][x] == LETTER[st->player]
					|| GRID[y][x + 1] == LETTER[st->player]
						|| GRID[y + 1 ][x + 1] == LETTER[st->player]))
			return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_first(t_fig *st)
{
	int		x;
	int		y;

	y = 0;
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			if (GRID[y][x] == LETTER[st->player])
			{
				st->borderx = x;
				st->bordery = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int		is_first(t_fig *st)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			if (GRID[y][x] == LETTER[st->player])
				i++;
			x++;
		}
		y++;
	}
	if (i != 1)
		return (0);
	return (1);
}

void	define_border(t_fig *st)
{
	get_first(st);
	if (GYMAX < 20 && st->bordery > 10)
	{
		if (GYMAX - st->bordery >= st->bordery)
			st->bordery = GYMAX- 1;
		else
			st->bordery = 0;
	}
	else
	{
		if (GXMAX - st->borderx >= st->borderx)
			st->borderx = GXMAX - 1;
		else
			st->borderx = 0;
	}
}

int		border_hit(t_fig *st)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (st->borderx != 0 && st->borderx != GXMAX)
	{
		while (x < GXMAX)
		{
			if (GRID[st->bordery][x] == LETTER[st->player])
				return (1);
			x++;
		}
		return (0);
	}
	while (y < GYMAX)
	{
		if (GRID[y][st->borderx] == LETTER[st->player])
			return (1);
		y++;
	}
	return (0);
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
