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
	x = 0;
	y = 0;
	if (button == 4 && a->e.mouse == 1)
	{
		if (a->tabi[(int)(a->d.posx + a->d.dirx * a->d.movespeed)]\
		[(int)a->d.posy] == 0)
			a->d.posx += a->d.dirx * a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy + a->d.diry * \
			a->d.movespeed)] == 0)
			a->d.posy += a->d.diry * a->d.movespeed;
	}
	if (button == 5 && a->e.mouse == 1)
	{
		if (a->tabi[(int)(a->d.posx - a->d.dirx * a->d.movespeed)]\
		[(int)a->d.posy] == 0)
			a->d.posx -= a->d.dirx * a->d.movespeed;
		if (a->tabi[(int)a->d.posx][(int)(a->d.posy - a->d.diry * \
			a->d.movespeed)] == 0)
			a->d.posy -= a->d.diry * a->d.movespeed;
	}
	return (0);
}
