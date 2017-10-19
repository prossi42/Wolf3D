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
	if (keycode == 126 || keycode == 13)
	{
		if (a->tabi[(int)(a->d.posx + a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
			a->d.posx += a->d.dirx *a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy + a->d.diry * a->d.movespeed)] == 0)
			a->d.posy += a->d.diry * a->d.movespeed;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (a->tabi[(int)(a->d.posx - a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
			a->d.posx -= a->d.dirx * a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy - a->d.diry * a->d.movespeed)] == 0)
			a->d.posy -= a->d.diry * a->d.movespeed;
	}
	if (keycode == 124 || keycode == 2)
	{
		a->d.olddirx = a->d.dirx;
		a->d.dirx = a->d.dirx * cos(-a->d.rotspeed) - a->d.diry * sin(-a->d.rotspeed);
		a->d.diry = a->d.olddirx * sin(-a->d.rotspeed) + a->d.diry * cos(-a->d.rotspeed);
		a->d.oldplanex = a->d.planex;
		a->d.planex = a->d.planex * cos(-a->d.rotspeed) - a->d.planey * sin(-a->d.rotspeed);
		a->d.planey = a->d.oldplanex * sin(-a->d.rotspeed) + a->d.planey * cos(-a->d.rotspeed);
	}
	if (keycode == 123 || keycode == 0)
	{
		a->d.olddirx = a->d.dirx;
		a->d.dirx = a->d.dirx * cos(a->d.rotspeed) - a->d.diry * sin(a->d.rotspeed);
		a->d.diry = a->d.olddirx * sin(a->d.rotspeed) + a->d.diry * cos(a->d.rotspeed);
		a->d.oldplanex = a->d.planex;
		a->d.planex = a->d.planex * cos(a->d.rotspeed) - a->d.planey * sin(a->d.rotspeed);
		a->d.planey = a->d.oldplanex * sin(a->d.rotspeed) + a->d.planey * cos(a->d.rotspeed);
	}
	if (keycode == 53)
	{
		free_all(a);
		exit(1);
	}
	if (keycode == 36)
		ft_init_struct(a, 2);
	if (keycode == 17)
		key_bindings(a);
	if (keycode == 3)
	{
		if (a->e.flag == 0)
			a->e.flag = 1;
		else
			a->e.flag = 0;
	}
	if (keycode == 46)
	{
		if (a->e.mouse == 0)
			a->e.mouse = 1;
		else
			a->e.mouse = 0;
	}
	mlx_destroy_image(a->c.init, a->c.img);
	a->c.img = mlx_new_image(a->c.init, WINSIZE_X, WINSIZE_Y);
	a->c.map = mlx_get_data_addr(a->c.img, &a->c.bpp, \
		&a->c.size_line, &a->c.endian);
	raycaster(a);
	mlx_put_image_to_window(a->c.init, a->c.wdow, a->c.img, 0, 0);
	fps_counter(a);
	return (0);
}
