/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:05:48 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 18:42:21 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		piece_in(int x, int y, t_fig *st)
{
	int		i;
	int		sup;

	i = -1;
	sup = 0;
	if (x < 0 || y < 0)
		return (0);
	if (y + PYMAX >= GYMAX || x + PXMAX >= GXMAX)
		return (0);
	while (++i < N)
	{
		if (GRID[y + OY[i]][x + OX[i]] == LETTER[st->bitch])
			return (0);
		if (GRID[y + OY[i]][x + OX[i]] == LETTER[st->player])
			sup++;
	}
	if (sup == 1)
		return (1);
	else
		return (0);
}

int		rev_search(t_fig *st)
{
	int		x;
	int		y;

	y = GYMAX - 1;
	while (y)
	{
		x = GXMAX;
		while (x)
		{
			if (piece_in(x, y, st))
			{
				feedback(x, y, st);
				return (1);
			}
			x--;
		}
		y--;
	}
	feedback(0, 0, st);
	return (0);
}

int		reg_search(t_fig *st)
{
	int		x;
	int		y;

	y = 0;
	while (y + PYMAX < GYMAX)
	{
		x = 0;
		while (x + PXMAX < GXMAX)
		{
			if (piece_in(x, y, st))
			{
				feedback(x, y, st);
				return (1);
			}
			x++;
		}
		y++;
	}
	feedback(0, 0, st);
	return (0);
}

int		check_lines(int i, int y, t_fig *st)
{
	int		x;

	if (TARX - i < 0 || y == 0)
		x = 0;
	else
		x = TARX - i;
	while (x <= TARX + i)
	{
		if (piece_in(x, y, st))
		{
			feedback(x, y, st);
			return (1);
		}
		x++;
	}
	return (0);
}
