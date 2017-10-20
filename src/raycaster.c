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

void	raycaster_fih(t_a *a)
{
	if (a->d.side == 0 || a->d.side == 1)
		a->d.perpwalldist = (a->d.mapx - a->d.rayposx + (1 - a->d.stepx) \
		/ 2) / a->d.raydirx;
	else
		a->d.perpwalldist = (a->d.mapy - a->d.rayposy + (1 - a->d.stepy) \
		/ 2) / a->d.raydiry;
	a->d.lineheight = (int)(WINSIZE_Y / a->d.perpwalldist);
	a->d.drawstart = (-a->d.lineheight / 2) + (WINSIZE_Y / 2);
	if (a->d.drawstart < 0)
		a->d.drawstart = 0;
	a->d.drawend = (a->d.lineheight / 2) + (WINSIZE_Y / 2);
	if (a->d.drawend >= WINSIZE_Y)
		a->d.drawend = WINSIZE_Y - 1;
}

void	raycaster_fh(t_a *a)
{
	while (a->d.hit == 0)
	{
		if (a->d.sidedistx < a->d.sidedisty)
		{
			a->d.sidedistx += a->d.deltadistx;
			a->d.mapx += a->d.stepx;
			if (a->d.stepx == -1)
				a->d.side = 0;
			if (a->d.stepx == 1)
				a->d.side = 1;
		}
		else
		{
			a->d.sidedisty += a->d.deltadisty;
			a->d.mapy += a->d.stepy;
			if (a->d.stepy == -1)
				a->d.side = 2;
			if (a->d.stepy == 1)
				a->d.side = 3;
		}
		if (a->tabi[a->d.mapx][a->d.mapy] > 0)
			a->d.hit = 1;
	}
}

void	raycaster_td(t_a *a)
{
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
}

void	raycaster_sd(t_a *a, int x)
{
	a->d.camerax = 2 * x / (double)WINSIZE_X - 1;
	a->d.rayposx = a->d.posx;
	a->d.rayposy = a->d.posy;
	a->d.raydirx = a->d.dirx + a->d.planex * a->d.camerax;
	a->d.raydiry = a->d.diry + a->d.planey * a->d.camerax;
	a->d.mapx = (int)a->d.rayposx;
	a->d.mapy = (int)a->d.rayposy;
	a->d.deltadistx = sqrt(1 + (a->d.raydiry * a->d.raydiry) / \
	(a->d.raydirx * a->d.raydirx));
	a->d.deltadisty = sqrt(1 + (a->d.raydirx * a->d.raydirx) / \
	(a->d.raydiry * a->d.raydiry));
	a->d.hit = 0;
}

void	raycaster(t_a *a)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (++x < WINSIZE_X)
	{
		raycaster_sd(a, x);
		raycaster_td(a);
		raycaster_fh(a);
		raycaster_fih(a);
		mur(a, x, y);
		sol(a, x, y);
		ciel(a, x, y);
	}
	mlx_put_image_to_window(a->c.init, a->c.wdow, a->c.img, 0, 0);
	fps_counter(a);
}
