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

void	fps_counter(t_a *a)
{
	struct timeval tp;
	char			*tmp;

	a->d.oldtime = a->d.time;
	gettimeofday(&tp, NULL);
	a->d.time = tp.tv_usec;
	gettimeofday(&tp, NULL);
	a->d.time = tp.tv_usec;
	a->d.frametime = round((a->d.time - a->d.oldtime) / 1000);
	if (a->d.frametime < 0)
		fps_counter(a);
	tmp = ft_itoa((int)a->d.frametime);
	mlx_string_put(a->c.init, a->c.wdow, WINSIZE_X / 100, WINSIZE_Y / 100, 0xFFFFFF, tmp);
	free(tmp);
	a->d.movespeed = a->d.frametime * 0.003;
	a->d.rotspeed = a->d.frametime * 0.003;
}

void	raycaster(t_a *a)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WINSIZE_X)
	{
		a->d.camerax = 2 * x / (double)WINSIZE_X - 1;
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
		a->d.lineheight = (int)(WINSIZE_Y / a->d.perpwalldist);
		a->d.drawstart = -a->d.lineheight / 2 + WINSIZE_Y / 2;
		if (a->d.drawstart < 0)
			a->d.drawstart = 0;
		a->d.drawend = a->d.lineheight / 2 + WINSIZE_Y / 2;
		if (a->d.drawend >= WINSIZE_Y)
			a->d.drawend = WINSIZE_Y - 1;
		a->d.color = 0x3300FF;
		if (a->d.side == 1)
			a->d.color = 0xFFFFFF;
		// a->d.tmpstart = a->d.drawstart;
		// a->d.tmpend = a->d.drawend;
		y = a->d.drawstart;
		while (y < WINSIZE_Y)
		{
			mlx_pixel_put_to_image(a->c, x, y, a->d.color);
			y++;
		}
		y = a->d.drawend;
		while (y < a->d.drawstart)
		{
			mlx_pixel_put_to_image(a->c, x, y, 0xFFFFFF);
			y++;
		}
	}
	fps_counter(a);
}
