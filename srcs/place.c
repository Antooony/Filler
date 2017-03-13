/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:05:48 by adenis            #+#    #+#             */
/*   Updated: 2017/03/13 16:41:32 by adenis           ###   ########.fr       */
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

void	printox(t_fig *st)
{
	int i = 0;
	ft_fprintf(2, "TARY = %d TARX = %d\n", TARY, TARX);
	ft_fprintf(2, "LASTY = %d LASTX = %d\n", LASTY, LASTX);
	ft_fprintf(2, "   PIECE\n");
	while (FIG[i])
	{
		ft_fprintf(2, "%d  %s\n", i, FIG[i]);
		i++;
	}
	i = 0;
	ft_fprintf(2, "PYMAX = %d PXMAX = %d\n", PYMAX , PXMAX);	
	while (i < N)
	{
		ft_fprintf(2, "y = %d, x = %d\n", OY[i], OX[i]);
		i++;
	}
	ft_fprintf(2, "\\\\ PIECE\n");
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
			sup++;
	}
	if (sup == 1)
		return (1);
	else
		return (0);
}

void	feedback(int x, int y, t_fig *st)
{
	LASTX = x;
	LASTY = y;
	// ft_fprintf(2, "%d %d\n", y, x);
	ft_printf("%d %d\n", y, x);
	clean(st);
}

void	rev_search(t_fig *st)
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
					filler(st);
					return ;
				}
				x--;
			}
			y--;
		}
	feedback(0, 0, st);
}

void	reg_search(t_fig *st)
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
	feedback(0, 0, st);
}

int		check_lines(int i, int y, t_fig *st)
{
	int		x;

	if (TARX - i < 0 || y == 0)
		x = 0;
	else
		x = TARX - i;
	// ft_fprintf(2, "\ni = %d\n", i);
	// ft_fprintf(2, "y = %d x = %d - ", y, x);
	while (x <= TARX + i)
	{
		if (piece_in(x, y, st))
		{
			feedback(x, y, st);
			return (1);
		}
		x++;
	}
	// ft_fprintf(2, "%d\n", x);
	return (0);
}

int		check_border(int i, int y, t_fig *st)
{
	// ft_fprintf(2, "y = %d x = %d\n", y, TARX - i);
	// ft_fprintf(2, "y = %d x = %d\n", y, TARX + i);
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
