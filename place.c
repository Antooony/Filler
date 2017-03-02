/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:05:48 by adenis            #+#    #+#             */
/*   Updated: 2017/03/02 17:09:59 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void		ft_figfree(t_fig st)
// {
// 	if (st->piece)
// 	free(st->piece);
// 	if (st->grid)
// 	free(st->grid);
// 	if (st->line)
// 	free(st->line);
// }

void		get_start(t_fig *st)
{
	int		x;
	int		y;
	int		ret;

	x = GXMAX - 1;
	y = GYMAX - 1;
	ret = 0;

	while (y >= 0)
	{
		x = GXMAX - 1;
		while (x >= 0)
		{
			if (GRID[y][x] == 'O')
			{
				st->starty = y;
				st->startx = x;
				break ;
			}
			x--;
		}
		y--;
	}
}

int		piece_in(int gx, int gy, t_fig *st)
{
	int		x;
	int		y;
	int		sup;

	x = 0;
	sup = 0;
	y = 0;
	if (PYMAX + gy >= GYMAX || PXMAX + gx >= GXMAX)
		return (0);
	while (y < PYMAX)
	{
		x = 0;
		while (x < PXMAX)
		{
			if (FIG[y][x] == '*')
			{
				if (GRID[y + gy][x + gx] == 'X')
					return (0);
				if (GRID[y + gy][x + gx] == 'O')
				{
					if (sup)
						return (0);
					sup = 1;
				}
			}
			x++;
		}
		y++;
	}	
	if (!sup)
		return (0);
	return (1);
}

void	get_pos(t_fig *st)
{
	get_start(st);
	GXMAX = ft_strlen(st->grid[0]);
	int		x = GXMAX - 1;
	int		y = st->starty;
	while (y)
	{
		x = GXMAX - 1;
		while (x)
		{
			if (piece_in(x, y, st))
			{
				ft_printf("%d %d\n", y, x);
				filler(st);
				return ;
			}
			x--;
		}
		y--;
	}
	while (y < GYMAX)
	{
		x = 0;
		while (x < GXMAX)
		{
			if (piece_in(x, y, st))
			{
				ft_printf("%d %d\n", y, x);
				filler(st);
				return ;
			}
			x++;
		}
		y++;
	}
}
