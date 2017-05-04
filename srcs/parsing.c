/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:38:42 by adenis            #+#    #+#             */
/*   Updated: 2017/05/04 18:26:34 by adenis           ###   ########.fr       */
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
	{
		s ? ft_strdel(&s) : NULL;
		return (0);
	}
	while (s[i] && !ft_isdigit(s[i]))
		i++;
	i = s[i] - '0';
	s ? ft_strdel(&s) : NULL;
	return (i);
}

int			get_gsize(t_fig *st, char *s)
{
	if (!ft_strstr(s, "Plateau"))
		return (0);
	st->gx = ft_atoi(ft_strrchr(s, ' ') + 1);
	st->gy = ft_atoi(ft_strchr(s, ' ') + 1);
	return (1);
}

int			get_psize(t_fig *st)
{
	char	*s;

	get_next_line(0, &s);
	if (!ft_strstr(s, "Piece"))
	{
		s ? ft_strdel(&s) : NULL;
		return (0);
	}
	st->px = ft_atoi(ft_strrchr(s, ' ') + 1);
	st->py = ft_atoi(ft_strchr(s, ' ') + 1);
	s ? ft_strdel(&s) : NULL;
	return (1);
}

char		*parse_grid(char *s)
{
	char	*out;

	out = ft_strdup(s + 4);
	return (out);
}
