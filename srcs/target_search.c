/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:58:39 by adenis            #+#    #+#             */
/*   Updated: 2017/03/14 12:06:15 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		check_border(int i, int y, t_fig *st)
{
	int		x;

	if (TARX - i < 0)
		x = 0;
	else
		x = TARX - i;
	if (piece_in(TARX - i, y, st))
	{
		feedback(TARX - i, y, st);
		return (1);
	}
	if (TARX + i > GXMAX)
		x = GXMAX - 1;
	else
		x = TARX + i;
	if (piece_in(TARX + i, y, st))
	{
		feedback(TARX + i, y, st);
		return (1);
	}
	return (0);
}

int		target2(t_fig *st, int i)
{
	int		y;

	if (TARY - i < 0)
		y = 0;
	else
		y = TARY - i;
	while (y <= TARY + i && TARY + i < GYMAX)
	{
		if (y == TARY + i || y == TARY - i)
		{
			if (check_lines(i, y, st))
				return (1);
		}
		else if (check_border(i, y, st))
			return (1);
		y++;
	}
	return (0);
}

int		target(t_fig *st, int i)
{
	int		y;

	if (TARY + i >= GYMAX)
		y = GYMAX - 1;
	else
		y = TARY + i;
	while (y >= TARY - i && TARY - i > 0)
	{
		if (y == TARY + i || y == TARY - i)
		{
			if (check_lines(i, y, st))
				return (1);
		}
		else if (check_border(i, y, st))
			return (1);
		y--;
	}
	return (0);
}

void	test_target2(t_fig *st)
{
	int		i;

	i = 1;
	while (i + PYMAX < GYMAX)
	{
		if (target2(st, i))
		{
			filler(st);
			return ;
		}
		i++;
	}
	reg_search(st);
}

void	test_target(t_fig *st)
{
	int		i;

	i = 1;
	while (i + PYMAX < GYMAX)
	{
		if (target(st, i))
		{
			filler(st);
			return ;
		}
		i++;
	}
	reg_search(st);
}
