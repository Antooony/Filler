/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:13:39 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 20:14:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	aff(char c)
{
	if (c == 'O')
		ft_printf("\e[38;5;0m\e[41m%c\e[0m", c);
	else if (c == 'o')
		ft_printf("\e[38;5;0m\e[48;5;9m%c\e[0m", c);
	else if (c == 'x')
		ft_printf("\e[48;5;14m\e[38;5;0m%c\e[0m", c);
	else if (c == 'X')
		ft_printf("\e[48;5;21m\e[38;5;0m%c\e[0m", c);
	else
		ft_printf("%c", c);
}

void	disp(char *line)
{
	int 	i;

	i = 0;
	while (line[i])
	{
		aff(line[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(void)
{
	char 	buff[2];
	char 	*line = NULL;

	buff[1] = '\0';
	while (get_next_line(0, &line))
	{
		if (ft_isdigit(line[0]))
			disp(line);
		if (line[0] == '<')
			ft_putchar('\n');
		if (line[0] == '=' || line[0] == ' ')
			ft_putendl(line);
	}
}