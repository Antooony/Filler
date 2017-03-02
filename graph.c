/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:13:39 by adenis            #+#    #+#             */
/*   Updated: 2017/03/02 17:28:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
void	aff(char c)
{
	if (c == 'O' || c == 'o')
		ft_printf("\e[31m%c\e[0m", c);
	else if (c == 'X' || c == 'x')
		ft_printf("\e[34m%c\e[0m", c);
	else
		ft_printf("%c", c);
}

int		main(void)
{
	char buff[2];

	buff[1] = '\0';
	while (read(0, buff, 1))
		aff(buff[0]);
}