/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:56:11 by adenis            #+#    #+#             */
/*   Updated: 2017/05/04 19:48:11 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		count_score(t_fig *st)
{
	int		x;
	int		y;
	int		score;

	y = 0;
	score = 0;
	while (y < GYMAX)
	{
		x = 0;
		while (x < GXMAX)
		{
			score += TAB[y][x];
			x++;
		}
		y++;
	}
	return (score);
}

int		get_score(t_fig *st)
{
	int		i;

	i = 3;
	while (!is_filled(st, i))
	{
		fill_score(st, i);
		i++;
	}
	return (count_score(st));
}

void	score(t_fig *st, int x, int y)
{
	int		i;

	i = 0;
	init_tab(st);
	place_piece(st, x, y);
	if (!st->score || get_score(st) > st->score)
	{
		BX = x;
		BY = y;
		st->score = get_score(st);
	}
}

int		score_check(t_fig *st)
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
				score(st, x, y);
			x++;
		}
		y++;
	}
	feedback(BX, BY, st);
	if (!in)
		return (0);
	return (1);
}
