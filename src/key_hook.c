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
