/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:54:42 by adenis            #+#    #+#             */
/*   Updated: 2017/03/14 12:12:28 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		print(t_fig *st)
{
	int		i;

	ft_fprintf(2, "Player = %d\n", st->player);
	ft_fprintf(2, "GYMAX  = %d\n", st->gy);
	ft_fprintf(2, "GXMAX  = %d\n", st->gx);
	ft_fprintf(2, "PYMAX  = %d\n", st->py);
	ft_fprintf(2, "PXMAX  = %d\n", st->px);
	i = -1;
	ft_fprintf(2, "GRID \n");
	while (st->grid[++i])
		ft_fprintf(2, "%s\n", st->grid[i]);
	i = -1;
	if (!FIG)
		return ;
	ft_fprintf(2, "PIECE \n");
	while (st->piece[++i])
		ft_fprintf(2, "%s\n", st->piece[i]);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
	{
		if (tab[i])
			ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void		clean(t_fig *st)
{
	st->nb = 0;
	st->px = 0;
	st->py = 0;
	st->starty = 0;
	st->startx = 0;
	free(OX);
	free(OY);
}
void	feedback(int x, int y, t_fig *st)
{
	t_fig	*new;

	new = st_new();
	LASTX = x;
	LASTY = y;
	ft_printf("%d %d\n", y, x);
	clean(st);
}

void	get_target(t_fig *st, char *s2, int y)
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
	new->starty = 0;
	new->startx = 0;
	new->player = 0;
	return (new);
}