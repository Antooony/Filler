/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:36:17 by adenis            #+#    #+#             */
/*   Updated: 2017/05/04 19:48:36 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void		free_score(t_fig *st)
{
	int		i;

	i = 0;
	while (i < GYMAX)
	{
		if (TAB[i])
			free(TAB[i]);
		i++;
	}
	if (TAB)
		free(TAB);
}

void			last_clean(t_fig *st)
{
	if (TAB)
		free_score(st);
	if (FIG)
		free_tab(FIG);
	if (GRID)
		free_tab(GRID);
	if (st->line)
		ft_strdel(&st->line);
	free(st);
}

void			init_tab(t_fig *st)
{
	int		x;
	int		y;

	y = 0;
	while (y < GYMAX)
	{
		x = 0;
		while (x < GXMAX)
		{
			if (GRID[y][x] == LETTER[st->player])
				TAB[y][x] = 2;
			else if (GRID[y][x] == LETTER[st->adv])
				TAB[y][x] = -2;
			else
				TAB[y][x] = 127;
			x++;
		}
		y++;
	}
}

void			create_tab(t_fig *st)
{
	int		i;

	i = 0;
	if (!(TAB = (char **)malloc(sizeof(char *) * GYMAX)))
		exit(0);
	while (i < GYMAX)
	{
		if (!(TAB[i] = (char *)malloc(sizeof(char) * GXMAX)))
			exit(0);
		i++;
	}
}

void			place_piece(t_fig *st, int x, int y)
{
	int		i;

	i = 0;
	while (i < N)
	{
		TAB[y + OY[i]][x + OX[i]] = 2;
		i++;
	}
}
