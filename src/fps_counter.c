/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:44:34 by prossi            #+#    #+#             */
/*   Updated: 2017/10/17 12:44:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	fps_counter(t_a *a)
{
	struct timeval	tp;
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
	mlx_string_put(a->c.init, a->c.wdow, WINSIZE_X / 100, WINSIZE_Y / 100, \
		0xFF0000, "FPS:");
	mlx_string_put(a->c.init, a->c.wdow, WINSIZE_X / 100 + 40, \
		WINSIZE_Y / 100, 0xFF0000, tmp);
	free(tmp);
	a->d.movespeed = a->d.frametime * a->e.speed;
	a->d.rotspeed = a->d.frametime * 0.003;
}
