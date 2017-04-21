/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:32:52 by adenis            #+#    #+#             */
/*   Updated: 2017/04/21 20:55:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int ac ,char **av)
{
	if (ac != 2)
		return (0);
	char *line = NULL;
	int s1 = 0;
	int s2 = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (strstr(line, "=="))
		{
			s1 = ft_atoi(ft_strrchr(line, ' '));
			get_next_line(0, &line);
			s2 = ft_atoi(ft_strrchr(line, ' '));
			break ;
		}
	}
	if (av[1][0] == '1')
	{
		if (s1 > s2)
		{
			ft_printf("\e[32mGAGNÉ\e[0m\n");
			ft_fprintf(2, "\e[32mGAGNÉ\e[0m\n");
		}
		else
		{
			ft_printf("\e[31mPERDU\e[0m\n");
			ft_fprintf(2, "\e[31mPERDU\e[0m\n");
		}
	}
	else
	{
		if (s1 > s2)
		{
			ft_printf("\e[31mPERDU\e[0m\n");
			ft_fprintf(2, "\e[31mPERDU\e[0m\n");
		}
		else
		{
			ft_printf("\e[32mGAGNÉ\e[0m\n");
			ft_fprintf(2, "\e[32mGAGNÉ\e[0m\n");
		}
	}
}