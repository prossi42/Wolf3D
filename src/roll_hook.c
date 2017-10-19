/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:44:38 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 18:44:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		roll_hook(int button, int x, int y, t_a *a)
{
	if (x >= 0 && x <= WINSIZE_X && y >= 0 && y <= WINSIZE_Y)
	{
		if (button == 4 && a->e.mouse == 1)
		{
			if (a->tabi[(int)(a->d.posx + a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
				a->d.posx += a->d.dirx *a->d.movespeed;
			if (a->tabi[(int)a->d.posx][(int)(a->d.posy + a->d.diry * a->d.movespeed)] == 0)
				a->d.posy += a->d.diry * a->d.movespeed;
		}
		if (button == 5 && a->e.mouse == 1)
		{
			if (a->tabi[(int)(a->d.posx - a->d.dirx * a->d.movespeed)][(int)a->d.posy] == 0)
				a->d.posx -= a->d.dirx * a->d.movespeed;
			if (a->tabi[(int)a->d.posx][(int)(a->d.posy - a->d.diry * a->d.movespeed)] == 0)
				a->d.posy -= a->d.diry * a->d.movespeed;
		}
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
