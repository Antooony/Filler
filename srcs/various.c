/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:54:42 by adenis            #+#    #+#             */
/*   Updated: 2017/05/05 18:37:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			piece_in(int x, int y, t_fig *st)
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
		if (GRID[y + OY[i]][x + OX[i]] == LETTER[st->adv])
			return (0);
		if (GRID[y + OY[i]][x + OX[i]] == LETTER[st->player])
			sup++;
	}
	if (sup == 1)
		return (1);
	else
		return (0);
}

void		free_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	while (i <= j)
	{
		if (tab[i])
			ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

void		clean(t_fig *st)
{
	st->nb = 0;
	st->px = 0;
	st->py = 0;
	BX = 0;
	BY = 0;
	OX ? free(OX) : NULL;
	OY ? free(OY) : NULL;
}

void		feedback(int x, int y, t_fig *st)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	clean(st);
	ft_fprintf(2, "\nMERCADI\n");
}

t_fig		*st_new(void)
{
	t_fig	*new;

	new = (t_fig*)malloc(sizeof(t_fig));
	new->tab = NULL;
	new->piece = NULL;
	new->grid = NULL;
	new->line = NULL;
	new->nb = 0;
	new->gx = 0;
	new->px = 0;
	new->gy = 0;
	new->py = 0;
	new->ox = NULL;
	new->oy = NULL;
	new->player = 0;
	new->bx = 0;
	new->by = 0;
	new->score = 0;
	new->padv = 0;
	new->end = 0;
	return (new);
}
