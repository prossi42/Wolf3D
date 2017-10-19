/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:18:09 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 18:18:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		mouse_hook(int x, int y, t_a *a)
{
	if (x >= 0 && x <= WINSIZE_X && y >= 0 && y <= WINSIZE_Y)
	{
		if (a->e.oldx != 0)
		{
			if (x < a->e.oldx && a->e.mouse == 1)
			{
				a->d.olddirx = a->d.dirx;
				a->d.dirx = a->d.dirx * cos(a->d.rotspeed) - a->d.diry * sin(a->d.rotspeed);
				a->d.diry = a->d.olddirx * sin(a->d.rotspeed) + a->d.diry * cos(a->d.rotspeed);
				a->d.oldplanex = a->d.planex;
				a->d.planex = a->d.planex * cos(a->d.rotspeed) - a->d.planey * sin(a->d.rotspeed);
				a->d.planey = a->d.oldplanex * sin(a->d.rotspeed) + a->d.planey * cos(a->d.rotspeed);
			}
			if (x > a->e.oldx && a->e.mouse == 1)
			{
				a->d.olddirx = a->d.dirx;
				a->d.dirx = a->d.dirx * cos(-a->d.rotspeed) - a->d.diry * sin(-a->d.rotspeed);
				a->d.diry = a->d.olddirx * sin(-a->d.rotspeed) + a->d.diry * cos(-a->d.rotspeed);
				a->d.oldplanex = a->d.planex;
				a->d.planex = a->d.planex * cos(-a->d.rotspeed) - a->d.planey * sin(-a->d.rotspeed);
				a->d.planey = a->d.oldplanex * sin(-a->d.rotspeed) + a->d.planey * cos(-a->d.rotspeed);
			}
		}
		a->e.oldx = x;
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
