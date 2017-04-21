/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:58:39 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 21:54:16 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	test_it(t_fig *st, int x, int y)
{
	if (!piece_in(x, y, st))
		return ;
	if (distance(x, y, st) < distance(TESTX, TESTY, st))
	{
		TESTX = x;
		TESTY = y;
	}
}

int		test_target(t_fig *st)
{
	int		x;
	int		y;

	y = 0;
	while (y < GYMAX - 1)
	{
		x = 0;
		while (x < GXMAX - 1)
		{
			test_it(st, x, y);
			x++;
		}
		y++;
	}
	if (piece_in(TESTX, TESTY, st))
	{
		feedback(TESTX, TESTY, st);
		return (1);
	}
	return (reg_search(st));
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
						|| GRID[y + 1][x + 1] == LETTER[st->bitch]))
				return (1);
			if (GRID[y][x] == LETTER[st->bitch]
				&& (GRID[y + 1][x] == LETTER[st->player]
					|| GRID[y][x + 1] == LETTER[st->player]
						|| GRID[y + 1][x + 1] == LETTER[st->player]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
