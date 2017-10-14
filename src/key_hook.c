/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:31:34 by prossi            #+#    #+#             */
/*   Updated: 2017/10/11 12:31:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		key_hook(int keycode, t_a *a)
{
	if (keycode == 126)
	{
		// printf("%f\n", a->d.posx);
		// printf("%f\n", a->d.dirx);
		printf("%f\n", a->d.movespeed);
		if (a->tabi[(int)(a->d.posx + a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
			a->d.posx += a->d.dirx *a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy + a->d.diry * a->d.movespeed)] == 0)
			a->d.posy += a->d.diry * a->d.movespeed;
	}
	if (keycode == 125)
	{
		if (a->tabi[(int)(a->d.posx - a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
			a->d.posx -= a->d.dirx * a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy - a->d.diry * a->d.movespeed)] == 0)
			a->d.posy -= a->d.diry * a->d.movespeed;
	}
	if (keycode == 124)
	{
		a->d.olddirx = a->d.dirx;
		a->d.dirx = a->d.dirx * cos(-a->d.rotspeed) - a->d.diry * sin(-a->d.rotspeed);
		a->d.diry = a->d.olddirx * sin(-a->d.rotspeed) + a->d.diry * cos(-a->d.rotspeed);
		a->d.oldplanex = a->d.planex;
		a->d.planex = a->d.planex * cos(-a->d.rotspeed) - a->d.planey * sin(-a->d.rotspeed);
		a->d.planey = a->d.oldplanex * sin(-a->d.rotspeed) + a->d.planey * sin(-a->d.rotspeed);
	}
	if (keycode == 123)
	{
		a->d.olddirx = a->d.dirx;
		a->d.dirx = a->d.dirx * cos(a->d.rotspeed) - a->d.diry * sin(a->d.rotspeed);
		a->d.diry = a->d.olddirx * sin(a->d.rotspeed) + a->d.diry * cos(a->d.rotspeed);
		a->d.oldplanex = a->d.planex;
		a->d.planex = a->d.planex * cos(a->d.rotspeed) - a->d.planey * sin(a->d.rotspeed);
		a->d.planey = a->d.oldplanex * sin(a->d.rotspeed) + a->d.planey * sin(a->d.rotspeed);
	}
	if (keycode == 53)
	{
		free_all(a);
		exit(1);
	}
	mlx_destroy_image(a->c.init, a->c.img);
	a->c.img = mlx_new_image(a->c.init, WINSIZE_X, WINSIZE_Y);
	a->c.map = mlx_get_data_addr(a->c.img, &a->c.bpp, \
		&a->c.size_line, &a->c.endian);
	raycaster(a);
	mlx_put_image_to_window(a->c.init, a->c.wdow, a->c.img, 0, 0);
	return (0);
}
