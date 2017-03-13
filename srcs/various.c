/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:54:42 by adenis            #+#    #+#             */
/*   Updated: 2017/03/08 16:15:03 by adenis           ###   ########.fr       */
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

void		printp(t_fig *st)
{
	int		i;

	ft_fprintf(2, "Player = %p\n", st->player);
	ft_fprintf(2, "GYMAX  = %p\n", st->gy);
	ft_fprintf(2, "GXMAX  = %p\n", st->gx);
	ft_fprintf(2, "PYMAX  = %p\n", st->py);
	ft_fprintf(2, "PXMAX  = %p\n", st->px);
	i = -1;
	ft_fprintf(2, "GRID \n");
	while (st->grid[++i])
		ft_fprintf(2, "%p\n", st->grid[i]);
	i = -1;
	ft_fprintf(2, "PIECE \n");
	while (st->piece[++i])
		ft_fprintf(2, "%p\n", st->piece[i]);
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