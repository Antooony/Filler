/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/03/13 16:45:18 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_line(char **s)
{
	if (get_next_line(0, s) <= 0)
		exit(0);
}

int		get_bitch(int p)
{
	if (p == 1)
		return (2);
	else
		return (1);
}

void	read_in(t_fig *st)
{
	int 	j;
	read_line(&st->line);
	if (!GYMAX)
		get_gsize(st);
	ft_strdel(&st->line);
	get_grid(st);
	read_line(&st->line);
	get_psize(st);
	FIG = malloc(sizeof(char *) * PYMAX + 1);
	FIG[PYMAX] = NULL;
	j = -1;
	while(++j < PYMAX)
		read_line(&FIG[j]);
	get_ox(st);
}

void	filler(t_fig *st)
{
	read_in(st);
	if (!LASTY)
	{
		if (st->player == 1)
			rev_search(st);
		else
			reg_search(st);
	}
	else if (TARY > LASTY)
		test_target(st);
	else
		test_target2(st);
	// get_pos(st);
}

int		main(void)
{
	t_fig	*st;

	st = st_new();
	st->player = get_player();
	st->bitch = get_bitch(st->player);
	filler(st);
}
