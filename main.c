/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:53:51 by adenis            #+#    #+#             */
/*   Updated: 2017/03/08 18:56:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	get_ox(st);
}

void	filler(t_fig *st)
{
	read_in(st);
	if (!LASTY)
		test_target(st);
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
