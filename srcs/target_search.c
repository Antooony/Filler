/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:58:39 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 16:33:36 by adenis           ###   ########.fr       */
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

int		test_target2(t_fig *st)
{
	int		i;

	i = 1;
	while (i + PYMAX < GYMAX)
	{
		if (target2(st, i))
			return (1);
		i++;
	}
	return (reg_search(st));
}

// int		test_target(t_fig *st)
// {
// 	int		i;

// 	i = 1;
// 	while (i + PYMAX < GYMAX)
// 	{
// 		if (target(st, i))
// 			return (1);
// 		i++;
// 	}
// 	return (reg_search(st));
// }

int		distance(int x, int y, t_fig *st)
{
	// ft_fprintf(2, "min = %d, max = %d res = %d\n", OX[0], PXMAX, (OX[0] + PXMAX) / 2);
	x = x + (OX[0] + OX[PXMAX - 1]) / 2;
	y = y + (OY[0] + OY[PYMAX - 1]) / 2;
	return ((x - TARX) * (x - TARX) + (y - TARY) * (y - TARY));
}

void	test_it(t_fig *st, int x, int y)
{
	if (!piece_in(x, y, st))
		return ;
	if (distance(x, y, st) < distance(TESTX, TESTY, st))
	{
		TESTX = x;
		TESTY = y;
	// ft_fprintf(2, "test_it\nx = %d, y = %d\n", TESTX, TESTY);
	// sleep(2);
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
