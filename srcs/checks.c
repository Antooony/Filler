/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:38:21 by adenis            #+#    #+#             */
/*   Updated: 2017/05/01 17:13:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		get_adv(int p)
{
	if (p == 1)
		return (2);
	else
		return (1);
}

int		check_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != 'O' && s[i] != 'X')
			return (0);
		i++;
	}
	return (1);
}

int		check_fline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

int		check_fig(t_fig *st)
{
	int	i;

	i = 0;
	while (FIG[i])
	{
		if ((int)ft_strlen(FIG[i]) != PXMAX)
			return (0);
		if (!check_fline(FIG[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_grid(t_fig *st)
{
	int	i;

	i = 0;
	while (GRID[i])
	{
		if ((int)ft_strlen(GRID[i]) != GXMAX)
			return (0);
		if (!check_line(GRID[i]))
			return (0);
		i++;
	}
	return (1);
}
