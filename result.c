/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:24:02 by adenis            #+#    #+#             */
/*   Updated: 2017/05/05 14:52:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int ac, char **av)
{
	int		x;
	int		y;
	char	*s;

	if (ac == 1)
		return (0);
	s = NULL;
	x = 0;
	y = 0;
	while (get_next_line(0, &s))
	{
		if (!x && ft_strstr(s, "=="))
			x = ft_atoi(s + 10);
		else if (x && ft_strstr(s, "=="))
			y = ft_atoi(s + 10);
		free(s);
	}
	if (av[1][0] == '1')
	{
		if (x == 0)
			ft_printf("PAS JOUÉ\n");
		else if (x > y)
			ft_printf("\e[32mGAGNÉ\e[0m : \e[32m%3d\e[0m - \e[31m%3d\e[0m\n", x, y);
		else if (x < y)
			ft_printf("\e[31mPERDU\e[0m : \e[31m%3d\e[0m - \e[32m%3d\e[0m\n", y, x);
	}
	else
	{
		if (y == 0)
			ft_printf("PAS JOUÉ\n");
		else if (x < y)
			ft_printf("\e[32mGAGNÉ\e[0m : \e[32m%3d\e[0m - \e[31m%3d\e[0m\n", y, x);
		else if (x > y)
			ft_printf("\e[31mPERDU\e[0m : \e[31m%3d\e[0m - \e[32m%3d\e[0m\n", x, y);
	}
}