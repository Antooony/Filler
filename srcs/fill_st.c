/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:55:40 by adenis            #+#    #+#             */
/*   Updated: 2017/03/13 17:22:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	update_line(t_fig *st, char *s2, int y)
{
	int		i;

	i = 0;
	// ft_fprintf(2, "UPDATE LINE\n");
	while (i < (int)ft_strlen(GRID[y]))
	{
		if (GRID[y][i] != s2[i])
		{
			if (s2[i] == LETTER[st->bitch])
			{
				TARX = i;
				TARY = y;
				return ;
			}
		}
		i++;
	}
	// if (&GRID[y])
		// ft_strdel(&GRID[y]);
		// ft_fprintf(2, "LINE UPDATED\n");
}

void	update_grid(t_fig *st)
{
	char	**tmp;
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	tmp = malloc(sizeof(char *) * GYMAX + 1);
	tmp[GYMAX] = NULL;
	read_line(&st->line);
	// ft_strdel(&st->line);
	// ft_fprintf(2, "TMP\n");
	while(i < GYMAX && get_next_line(0, &st->line) > 0)
	{
		tmp[i] = parse_grid(st->line);
		// ft_fprintf(2, "%s\n", tmp[i]);
		// ft_strdel(&st->line);
		i++;
	}
	i = 0;
	while(i < GYMAX)
	{
		if (ft_strcmp(GRID[i],tmp[i]))
			update_line(st, tmp[i], i);
		i++;
	}
	GRID = tmp;
	// ft_fprintf(2, "GRID UPDATED\n");
}

// void	update_grid(t_fig *st)
// {
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	s = NULL;
// 	read_line(&st->line);
// 	if (st->line)
// 		ft_strdel(&st->line);
// 	while(i < GYMAX && get_next_line(0, &st->line) > 0)
// 	{
// 		s = parse_grid(st->line);
// 		if (ft_strcmp(GRID[i],s))
// 			GRID[i] = update_line(st, s, i);
// 		if (st->line)
// 			ft_strdel(&st->line);
// 		i++;
// 	}
// 	// ft_fprintf(2, "GRID UPDATED\n");
// }

void	get_grid(t_fig *st)
{
	int 	i;

	i = 0;
	// ft_fprintf(2, "GET_GRID\n");
	if (GRID)
	{
		// ft_fprintf(2, "GRID EXISTS\n");
		update_grid(st);
		return;
	}
	// ft_fprintf(2, "!GRID\n");
	GRID = malloc(sizeof(char *) * GYMAX + 1);
	read_line(&st->line);
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
