/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:36:53 by prossi            #+#    #+#             */
/*   Updated: 2017/10/10 12:36:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		ft_init_struct(t_a *a, int option)
{
	if (option == 0)
	{
		a->b.count = 0;
		a->b.countsp = 0;
		a->b.tmp = 0;
		a->b.tmpsp = 0;
		a->b.i = -1;
		a->b.countnl = 0;
	}
	if (option == 1)
		a->c.bpp = 4;
	if (option == 2)
	{
		if (find_a_place(a) == 1)
			ft_affich(a, 3);
		a->d.dirx = -1;
		a->d.diry = 0;
		a->d.planex = 0;
		a->d.planey = 0.66;
		a->d.time = 0;
		a->d.oldtime = 0;
		a->d.movespeed = 1;
		a->d.rotspeed = 1;
	}
}
