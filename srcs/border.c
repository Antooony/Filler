/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:49:19 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 19:15:59 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		distance(int x, int y, t_fig *st)
{
	x = x + (OX[0] + OX[PXMAX - 1]) / 2;
	y = y + (OY[0] + OY[PYMAX - 1]) / 2;
	return ((x - TARX) * (x - TARX) + (y - TARY) * (y - TARY));
}

void	define_border(t_fig *st)
{
	get_first(st);
	if (GYMAX < 20 && st->bordery > 10)
	{
		if (GYMAX - st->bordery >= st->bordery)
			st->bordery = GYMAX - 1;
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

void	last_clean(t_fig *st)
{
	if (FIG)
		free_tab(FIG);
	if (GRID)
		free_tab(GRID);
	if (st->line)
		ft_strdel(&st->line);
	free(st);
}
