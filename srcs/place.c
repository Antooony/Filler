/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:05:48 by adenis            #+#    #+#             */
/*   Updated: 2017/03/08 20:23:47 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		clean(t_fig *st)
{
	// free_tab(GRID);
	// free_tab(FIG);
	st->nb = 0;
	st->px = 0;
	st->py = 0;
	st->starty = 0;
	st->startx = 0;
	free(OX);
	free(OY);
}

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
		{
			if (sup)
				return (0);
			sup = 1;
		}
	}
	if (!sup)
		return (0);
	return (1);
}

void	feedback(int x, int y, t_fig *st)
{
	LASTX = x;
	LASTY = y;
	ft_printf("%d %d\n", y, x);
	clean(st);
}

void	next_search(t_fig *st)
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
					filler(st);
					return ;
				}
				x++;
			}
			y++;
		}
		ft_printf( "0 0\n");
}

int		target2(t_fig *st, int i)
{
	int		x;
	int		y;

	if (TARY - i < 0)
		y = 0;
	else
		y = TARY - i;

	while (y <= TARY + i)
	{
		if (TARX - i < 0)
			x = 0;
		else
			x = TARX - i;
		if (y == TARY + i || y == TARY - i)
		{
			while (x <= TARX + i && TARX + i < GXMAX)
			{
				if (piece_in(x, y, st))
				{
					feedback(x, y, st);
					return (1);
				}
				x++;
			}
		}
		else
		{
			if (piece_in(TARX - i, y, st))
			{
				feedback(TARX - i, y, st);
				return (1);
			}
			if (piece_in(TARX + i, y, st))
			{
				feedback(TARX + i, y, st);
				return (1);
			}
		}
		y++;
	}
	return (0);
}

int		target(t_fig *st, int i)
{
	int		x;
	int		y;

	if (TARY + i >= GYMAX)
		y = GYMAX - 1;
	else
		y = TARY + i;

	while (y >= TARY - i && TARY - i > 0)
	{
		if (TARX - i < 0)
			x = 0;
		else
			x = TARX - i;
		if (y == TARY + i || y == TARY - i)
		{
			while (x <= TARX + i && TARX + i < GXMAX)
			{
				if (piece_in(x, y, st))
				{
					feedback(x, y, st);
					return (1);
				}
				x++;
			}
		}
		else
		{
			if (piece_in(TARX - i, y, st))
			{
				feedback(x, y, st);
				return (1);
			}
			if (piece_in(TARX + i, y, st))
			{
				feedback(x, y, st);
				return (1);
			}
		}
		y--;
	}
	return (0);
}

void	test_target2(t_fig *st)
{
	int		i;

	i = 1;
	while (i < GYMAX)
	{
		if (target2(st, i))
		{
			filler(st);
			return ;
		}
		i++;
	}
	next_search(st);
}

void	test_target(t_fig *st)
{
	int		i;

	i = 1;
	while (i < GYMAX)
	{
		if (target(st, i))
		{
			filler(st);
			return ;
		}
		i++;
	}
	next_search(st);
}
