/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:54:42 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 16:51:09 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

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
	TESTX = 0;
	TESTY = 0;
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
}

void		get_target(t_fig *st, char *s2, int y)
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
				return ;
			}
		}
		i++;
	}
}

t_fig		*st_new(void)
{
	t_fig	*new;

	new = (t_fig*)malloc(sizeof(t_fig));
	new->piece = NULL;
	new->grid = NULL;
	new->line = NULL;
	new->tarx = 0;
	new->tary = 0;
	new->nb = 0;
	new->gx = 0;
	new->px = 0;
	new->gy = 0;
	new->py = 0;
	new->ox = NULL;
	new->oy = NULL;
	new->testx = 0;
	new->testy = 0;
	new->borderx = 0;
	new->bordery = 0;
	new->starty = 0;
	new->startx = 0;
	new->player = 0;
	new->bx = 0;
	new->by = 0;
	return (new);
}
