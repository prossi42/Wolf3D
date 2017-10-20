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

void	mouse_hook_sd(t_a *a)
{
	a->d.olddirx = a->d.dirx;
	a->d.dirx = a->d.dirx * cos(-a->d.rotspeed) - a->d.diry * \
	sin(-a->d.rotspeed);
	a->d.diry = a->d.olddirx * sin(-a->d.rotspeed) + a->d.diry * \
	cos(-a->d.rotspeed);
	a->d.oldplanex = a->d.planex;
	a->d.planex = a->d.planex * cos(-a->d.rotspeed) - a->d.planey * \
	sin(-a->d.rotspeed);
	a->d.planey = a->d.oldplanex * sin(-a->d.rotspeed) + a->d.planey * \
	cos(-a->d.rotspeed);
}

int		mouse_hook(int x, int y, t_a *a)
{
	y = 0;
	if (a->e.oldx != 0)
	{
		if (x < a->e.oldx && a->e.mouse == 1)
		{
			a->d.olddirx = a->d.dirx;
			a->d.dirx = a->d.dirx * cos(a->d.rotspeed) - a->d.diry * \
			sin(a->d.rotspeed);
			a->d.diry = a->d.olddirx * sin(a->d.rotspeed) + a->d.diry * \
			cos(a->d.rotspeed);
			a->d.oldplanex = a->d.planex;
			a->d.planex = a->d.planex * cos(a->d.rotspeed) - a->d.planey * \
			sin(a->d.rotspeed);
			a->d.planey = a->d.oldplanex * sin(a->d.rotspeed) + a->d.planey * \
			cos(a->d.rotspeed);
		}
		if (x > a->e.oldx && a->e.mouse == 1)
			mouse_hook_sd(a);
	}
	a->e.oldx = x;
	return (0);
}
