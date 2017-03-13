/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:38:42 by adenis            #+#    #+#             */
/*   Updated: 2017/03/13 12:04:50 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		get_player(void)
{
	int		i;
	char	*s;

	i = 0;
	read_line(&s);
	while (s[i] && !ft_isdigit(s[i]))
		i++;
	i = s[i] - '0';
	ft_strdel(&s);
	return (i);
}

void		get_gsize(t_fig *st)
{
	char	*cut;
	char	*y;
	char	*x;

	cut = ft_strchr(st->line, ' ') + 1;
	x = ft_strsub(cut, ft_strchr(cut, ' ') - cut, ft_strchr(cut, ':') - cut - 1);
	y = ft_strsub(cut, 0, ft_strchr(cut, ' ') - cut);
	st->gx = ft_atoi(x);
	st->gy = ft_atoi(y);
	TARX = st->gx / 2;
	TARY = st->gy / 2;
	ft_strdel(&y);
	ft_strdel(&x);
}

void		get_psize(t_fig *st)
{
	char	*cut;
	char	*y;
	char	*x;
	
	cut = ft_strchr(st->line, ' ') + 1;
	y = ft_strsub(cut, 0, ft_strchr(cut, ' ') - cut);
	cut = ft_strchr(cut, ' ');
	x = ft_strsub(cut, 1, ft_strchr(cut, ':') - cut - 1);
	st->px = ft_atoi(x);
	st->py = ft_atoi(y);
	ft_strdel(&y);
	ft_strdel(&x);
	if (st->line)
		ft_strdel(&st->line);
}

char	*parse_grid(char *s)
{
	char	*out;

	out = ft_strsub(s, 4, ft_strlen(s) - 4);
	return (out);
}
