/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:42:51 by adenis            #+#    #+#             */
/*   Updated: 2017/04/22 18:45:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		distanceb(int x, int y, t_fig *st)
{
	x = x + (OX[0] + OX[PXMAX - 1]) / 2;
	y = y + (OY[0] + OY[PYMAX - 1]) / 2;
	return ((x - BX) * (x - BX) + (y - BY) * (y - BY));
}

void	define_tarb(t_fig *st)
{
	BY = TARY;
	if (distance(0, TARY, st) < distance(TARX, GYMAX, st))
		BX = 0;
	else if (distance(GXMAX, TARY, st) < distance(TARX, GYMAX, st))
		BX = GXMAX;
}
