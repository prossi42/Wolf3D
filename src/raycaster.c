/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:28:24 by prossi            #+#    #+#             */
/*   Updated: 2017/10/11 13:28:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	raycaster(t_a *a)
{
	int		x;

	x = -1;
	ft_init_struct(a, 2);
	while (++x < WINSIZE_X)
	{
		a->d.camerax = 2 * x / (double)WINSIZE_x - 1;
		a->d.rayposx = a->d.posx;
		a->d.rayposy = a->d.posy;
		a->d.raydirx = a->d.dirx + a->d.planex * a->d.camerax;
		a->d.raydiry = a->d.diry + a->d.planey * a->d.camerax;
		a->d.mapx = (int)a->d.rayposx;
		a->d.mapy = (int)a->d.rayposy;
		a->d.deltadistx = sqrt(1 + (a->d.raydiry * a->d.raydiry) / (a->d.raydirx * a->d.raydirx));
		a->d.deltadisty = sqrt(1 + (a->d.raydirx * a->d.raydirx) / (a->d.raydiry * a->d.raydiry));
		a->d.hit = 0;
		if (a->d.raydirx < 0)
		{
			a->d.stepx = -1;
			a->d.sidedistx = (a->d.rayposx - a->d.mapx) * a->d.deltadistx;
		}
		else
		{
			a->d.stepx = 1;
			a->d.sidedistx = (a->d.mapx + 1.0 - a->d.rayposx) * a->d.deltadistx;
		}
		if (a->d.raydiry < 0)
		{
			a->d.stepy = -1;
			a->d.sidedisty = (a->d.rayposy - a->d.mapy) * a->d.deltadisty;
		}
		else
		{
			a->d.stepy = 1;
			a->d.sidedisty = (a->d.mapy + 1.0 - a->d.rayposy) * a->d.deltadisty;
		}
		while (a->d.hit == 0)
		{
			if (a->d.sidedistx < a->d.sidedisty)
			{
				a->d.sidedistx += a->d.deltadistx;
				a->d.mapx += a->d.stepx;
				a->d.side = 0;
			}
			else
			{
				a->d.sidedisty += a->d.deltadisty;
				a->d.mapy += a->d.stepy;
				a->d.side = 1;
			}
			if (a->tabi[a->d.mapx][a->d.mapy] > 0)
				a->d.hit = 1;
		}
		if (a->d.side == 0)
			a->d.perpwalldist = (a->d.mapx - a->d.rayposx + (1 - a->d.stepx) / 2) / a->d.raydirx;
		else
			a->d.perpwalldist = (a->d.mapy - a->d.rayposy + (1 - a->d.stepy) / 2) / a->d.raydiry;
	}
}
