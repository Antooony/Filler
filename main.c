/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/03/02 17:32:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print(t_fig *st)
{
	int		i;

	ft_putstr_fd("PLAYER ", 2);
	ft_putendl_fd(ft_itoa(st->player), 2);
	ft_putstr_fd("st->gy = ", 2);
	ft_putendl_fd(ft_itoa(st->gy), 2);
	ft_putstr_fd("st->gx = ", 2);
	ft_putendl_fd(ft_itoa(st->gx), 2);
	ft_putstr_fd("st->py = ", 2);
	ft_putendl_fd(ft_itoa(st->py), 2);
	ft_putstr_fd("PX = ", 2);
	ft_putendl_fd(ft_itoa(st->px), 2);
	i = -1;
	ft_putendl_fd("st->grid", 2);
	while (st->grid[++i])
		ft_putendl_fd(st->grid[i], 2);
	i = -1;
	ft_putendl_fd("PIECE", 2);
	while (st->piece[++i])
		ft_putendl_fd(st->piece[i], 2);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

t_fig		*st_new(void)
{
	t_fig	*new;

	new = (t_fig*)malloc(sizeof(t_fig));
	new->piece = NULL;
	new->grid = NULL;
	new->line = NULL;
	new->gx = 0;
	new->px = 0;
	new->gy = 0;
	new->py = 0;
	new->starty = 0;
	new->startx = 0;
	new->player = 0;
	return (new);
}

void	get_grid(t_fig *st)
{
	int 	i;

	i = -2;
	if (GRID)
		free_tab(GRID);
	GRID = malloc(sizeof(char *) * GYMAX + 1);
	GRID[GYMAX] = NULL;
	ft_putendl_fd("////////////////////////", 2);
	while(++i < GYMAX && get_next_line(0, &st->line) > 0)
	{
		ft_putendl_fd(st->line, 2);
		if (i != -1)
		GRID[i] = parse_grid(st->line);
		// ft_strdel(&st->line);
	}
}

void	read_in(t_fig *st)
{
	int 	j;

	get_next_line(0, &st->line);
	if (!GYMAX)
		get_gsize(st);
	ft_strdel(&st->line);
	get_grid(st);
	get_next_line(0, &st->line);
	get_psize(st);
	FIG = malloc(sizeof(char *) * PYMAX + 1);
	FIG[PYMAX] = NULL;
	j = -1;
	while(++j < PYMAX)
		get_next_line(0, &FIG[j]);
}

void	filler(t_fig *st)
{
	read_in(st);
	// print(st);
	get_pos(st);
}

int		main(void)
{
	t_fig	*st;

	st = st_new();
	st->player = get_player();
	if (st->player == 2)
		return (0);
	filler(st);
}
