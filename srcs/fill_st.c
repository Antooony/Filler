/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:55:40 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 19:11:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	update_grid(t_fig *st)
{
	char	**tmp;
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	tmp = (char **)malloc(sizeof(char *) * GYMAX + 1);
	tmp[GYMAX] = NULL;
	get_next_line(0, &s);
	s ? ft_strdel(&s) : NULL;
	while (i < GYMAX && get_next_line(0, &s) > 0)
	{
		tmp[i] = parse_grid(s);
		s ? ft_strdel(&s) : NULL;
		i++;
	}
	i = 0;
	while (i < GYMAX)
	{
		if (ft_strcmp(GRID[i], tmp[i]))
			get_target(st, tmp[i], i);
		i++;
	}
	GRID ? free_tab(GRID) : NULL;
	GRID = tmp;
}

void	get_grid(t_fig *st)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	if (GRID)
	{
		update_grid(st);
		return ;
	}
	GRID = (char **)malloc(sizeof(char *) * GYMAX + 1);
	get_next_line(0, &s);
	s ? ft_strdel(&s) : NULL;
	GRID[GYMAX] = NULL;
	while (i < GYMAX && get_next_line(0, &s) > 0)
	{
		GRID[i] = parse_grid(s);
		s ? ft_strdel(&s) : NULL;
		i++;
	}
}

void	write_ox(t_fig *st)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	y = -1;
	i = 0;
	while (++y < PYMAX)
	{
		x = -1;
		while (++x < PXMAX)
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
	int		count;
	int		x;
	int		y;

	count = 0;
	x = 0;
	y = 0;
	while (FIG[y])
	{
		x = 0;
		while (FIG[y][x])
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
