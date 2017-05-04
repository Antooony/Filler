/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:40:15 by adenis            #+#    #+#             */
/*   Updated: 2017/05/04 19:47:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

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
			else if (TAB[y + yb][x + xb] == 127)
				TAB[y + yb][x + xb] = i;
			else if (TAB[y + yb][x + xb] < -1)
				TAB[y + yb][x + xb] += i;
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
			else if (TAB[y + yb][x + xb] == 127)
				TAB[y + yb][x + xb] = -i;
			else if (TAB[y + yb][x + xb] > 1)
				TAB[y + yb][x + xb] -= i;
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
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			if (TAB[y][x] == i - 1)
				fill_one(x, y, i, st);
			if (TAB[y][x] == -(i - 1))
				fill_neg(x, y, i, st);
			x++;
		}
		y++;
	}
}

int		is_filled(t_fig *st, int i)
{
	int		x;
	int		y;

	y = 0;
	while (y < GYMAX)
	{
		x = 0;
		while (x < GXMAX)
		{
			if (TAB[y][x] == i - 1)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
