/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:57:31 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 09:57:33 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		key(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	risingsun(t_a *a)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WINSIZE_X)
	{
		y = -1;
		while (++y < WINSIZE_Y)
			mlx_pixel_put(a->e.init, a->e.wdow, x, y, 0xFFFFFF - y);
	}
}

void	key_bindings(t_a *a)
{
	a->e.init = mlx_init();
	a->e.wdow = mlx_new_window(a->e.init, WINSIZE_X, \
		350, "Key Bindings");
	risingsun(a);
	mlx_string_put(a->e.init, a->e.wdow, 200, 0, 0xFF6633, \
		"Here comes the sun <3");
	mlx_string_put(a->e.init, a->e.wdow, 0, 50, 0xFF9900, \
		"Quitter : Esc or Red Cross");
	mlx_string_put(a->e.init, a->e.wdow, 0, 75, 0xFF9900, \
		"Reset : Return");
	mlx_string_put(a->e.init, a->e.wdow, 0, 100, 0xFF9900, \
		"Deplacement : Fleches Dir. / W-A-S-D");
	mlx_string_put(a->e.init, a->e.wdow, 0, 125, 0xFF9900, \
		"Mode flag : F");
	mlx_string_put(a->e.init, a->e.wdow, 0, 150, 0xFF9900, \
		"Mode souris : M (Gauche/droite: tourner / molette: av./rec.)");
	mlx_string_put(a->e.init, a->e.wdow, 0, 175, 0xFF9900, \
		"Sprint : Shift");
	mlx_hook(a->e.wdow, 2, (1L << 0), key, a);
	mlx_loop(a->e.init);
}
