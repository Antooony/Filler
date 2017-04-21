/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:38:42 by adenis            #+#    #+#             */
/*   Updated: 2017/04/19 20:18:04 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			get_player(void)
{
	int		i;
	char	*s;

	i = 0;
	get_next_line(0, &s);
	if (s[0] != '$')
		return (0);
	while (s[i] && !ft_isdigit(s[i]))
		i++;
	i = s[i] - '0';
	s ? ft_strdel(&s) : NULL;
	return (i);
}

void		get_gsize(t_fig *st, char *s)
{
	st->gx = ft_atoi(ft_strrchr(s, ' ') + 1);
	st->gy = ft_atoi(ft_strchr(s, ' ') + 1);
	TARX = st->gx / 2;
	TARY = st->gy / 2;
}

void		get_psize(t_fig *st)
{
	char	*s;

	get_next_line(0, &s);
	st->px = ft_atoi(ft_strrchr(s, ' ') + 1);
	st->py = ft_atoi(ft_strchr(s, ' ') + 1);
}

char		*parse_grid(char *s)
{
	char	*out;

	out = ft_strdup(s + 4);
	s ? ft_strdel(&s) : NULL;
	return (out);
}
