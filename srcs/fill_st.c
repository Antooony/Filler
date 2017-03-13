/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:55:40 by adenis            #+#    #+#             */
/*   Updated: 2017/03/08 20:23:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char	*update_line(t_fig *st, char *s2, int y)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(GRID[y]))
	{
		if (GRID[y][i] != s2[i])
		{
			if (s2[i] == LETTER[st->bitch])
			{
				TARX = i;
				TARY = y;
			}
		}
		i++;
	}
	ft_strdel(&GRID[y]);
	return (s2);
}

void	update_grid(t_fig *st)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	get_next_line(0, &st->line);
	ft_strdel(&st->line);
	while(i < GYMAX && get_next_line(0, &st->line) > 0)
	{
		s = parse_grid(st->line);
		if (ft_strcmp(GRID[i],s))
			GRID[i] = update_line(st, s, i);
		ft_strdel(&st->line);
		i++;
	}
}

void	get_grid(t_fig *st)
{
	int 	i;

	i = 0;
	if (GRID)
	{
		update_grid(st);
		return;
	}
	GRID = malloc(sizeof(char *) * GYMAX + 1);
	get_next_line(0, &st->line);
	ft_strdel(&st->line);
	GRID[GYMAX] = NULL;
	while(i < GYMAX && get_next_line(0, &st->line) > 0)
	{
		GRID[i] = parse_grid(st->line);
		ft_strdel(&st->line);
		i++;
	}
}

void	write_ox(t_fig *st)
{
	int		x = -1;
	int		y = -1;
	int		i = 0;

	while (++y < PYMAX)
	{
		x = -1;
		while(++x < PXMAX)
		{
			if (FIG[y][x] == '*')
			{
				OX[i] = x;
				OY[i] = y;
				i++;
			}
		}
	}
}

int		count_stars(t_fig *st)
{
	int		count = 0;
	int		x = 0;
	int		y = 0;
	while (FIG[y])
	{
		x = 0;
		while(FIG[y][x])
		{
			if (FIG[y][x] == '*')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	get_ox(t_fig *st)
{
	int		j;

	j = 0;												
	N = count_stars(st);
	OX = (int *)malloc(sizeof(int) * N);
	OY = (int *)malloc(sizeof(int) * N);
	write_ox(st);
	PYMAX = 0;
	PXMAX = 0;
	while (j < N)
	{
		if (OY[j] > PYMAX)
			PYMAX = OY[j];
		if (OX[j] > PXMAX)
			PXMAX = OX[j];
		j++;
	}
}
