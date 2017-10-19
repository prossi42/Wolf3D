/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:51:42 by prossi            #+#    #+#             */
/*   Updated: 2017/10/11 13:51:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		find_a_place(t_a *a)
{
	int		y;
	int		x;

	y = -1;
	a->d.posx = 0;
	a->d.posy = 0;
	while (++y < a->ymax)
	{
		x = -1;
		while (++x < a->xmax)
			if (a->tabi[y][x] == 0)
				if (a->tabi[y][x - 1] == 0 && a->tabi[y][x + 1] == 0 && \
					a->tabi[y - 1][x] == 0 && a->tabi[y + 1][x] == 0 && \
					a->tabi[y - 1][x - 1] == 0 && a->tabi[y + 1][x + 1] == 0 \
					&& a->tabi[y + 1][x - 1] == 0 && a->tabi[y - 1][x + 1] == 0)
				{
					a->d.posx = x;
					a->d.posy = y + 1;
					return (0);
				}
	}
	return (1);
}
