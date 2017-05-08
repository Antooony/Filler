/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:40:15 by adenis            #+#    #+#             */
/*   Updated: 2017/05/08 12:34:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	place_piece(t_fig *st, int x, int y)
{
	int		i;

	i = 0;
	while (i < N)
	{
		TAB[y + OY[i]][x + OX[i]] = 2;
		i++;
	}
}

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

void	fill_one(int x, int y, int i, t_fig *st)
{
	int		xb;
	int		yb;

	yb = !y ? 0 : -1;
	while (yb < 2 && y + yb < GYMAX)
	{
		xb = !x ? 0 : -1;
		while (xb < 2 && x + xb < GXMAX)
		{
			if (!xb && !yb)
				xb++;
			if (TAB[y + yb][x + xb] == -(i - 1))
				xb++;
			else if (TAB[y + yb][x + xb] == 1)
				TAB[y + yb][x + xb] = i;
			else if (TAB[y + yb][x + xb] == -i)
				TAB[y + yb][x + xb] = 0;
			xb++;
		}
		yb++;
	}
}

void	fill_neg(int x, int y, int i, t_fig *st)
{
	int		xb;
	int		yb;

	yb = !y ? 0 : -1;
	while (yb < 2 && y + yb < GYMAX)
	{
		xb = !x ? 0 : -1;
		while (xb < 2 && x + xb < GXMAX)
		{
			if (!xb && !yb)
				xb++;
			if (TAB[y + yb][x + xb] == i - 1)
				xb++;
			else if (TAB[y + yb][x + xb] == 1)
				TAB[y + yb][x + xb] = -i;
			else if (TAB[y + yb][x + xb] == i)
				TAB[y + yb][x + xb] = 0;
			xb++;
		}
		yb++;
	}
}

void	fill_score(t_fig *st, int i)
{
	int		x;
	int		y;

	y = 0;
	st->rot = 0;
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			if (TAB[y][x] == 1)
				st->rot = 1;
			else if (TAB[y][x] == i - 1)
				fill_one(x, y, i, st);
			else if (TAB[y][x] == -(i - 1))
				fill_neg(x, y, i, st);
			x++;
		}
		y++;
	}
}
