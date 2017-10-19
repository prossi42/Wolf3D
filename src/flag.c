/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:35:07 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 17:35:09 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	flagsd(t_a *a, int x, int y)
{
	if (a->d.side == 2)
	{
		if (x <= (WINSIZE_X / 3))
			mlx_pixel_put_to_image(a->c, x, y, 0xFFFFFF);
		if (x > (WINSIZE_X / 3) && x <= ((WINSIZE_X / 3) * 2))
			mlx_pixel_put_to_image(a->c, x, y, 0x339900);
		if (x > ((WINSIZE_X / 3) * 2))
			mlx_pixel_put_to_image(a->c, x, y, 0xCC0000);
	}
	if (a->d.side == 3)
	{
		if (x <= (WINSIZE_X / 3))
			mlx_pixel_put_to_image(a->c, x, y, 0x0000FF);
		if (x > (WINSIZE_X / 3) && x <= ((WINSIZE_X / 3) * 2))
			mlx_pixel_put_to_image(a->c, x, y, 0xFFFFFF);
		if (x > ((WINSIZE_X / 3) * 2))
			mlx_pixel_put_to_image(a->c, x, y, 0xFF0000);
	}
}

void	flag(t_a *a, int x, int y)
{
	y = a->d.drawstart - 1;
	while (++y < a->d.drawend)
	{
		if (a->d.side == 0)
		{
			if (x <= (WINSIZE_X / 3))
				mlx_pixel_put_to_image(a->c, x, y, 0x000000);
			if (x > (WINSIZE_X / 3) && x <= ((WINSIZE_X / 3) * 2))
				mlx_pixel_put_to_image(a->c, x, y, 0xFFCC00);
			if (x > ((WINSIZE_X / 3) * 2))
				mlx_pixel_put_to_image(a->c, x, y, 0xCC0000);
		}
		if (a->d.side == 1)
		{
			if (x <= (WINSIZE_X / 3))
				mlx_pixel_put_to_image(a->c, x, y, 0x0000CC);
			if (x > (WINSIZE_X / 3) && x <= ((WINSIZE_X / 3) * 2))
				mlx_pixel_put_to_image(a->c, x, y, 0xFFCC00);
			if (x > ((WINSIZE_X / 3) * 2))
				mlx_pixel_put_to_image(a->c, x, y, 0xCC0000);
		}
		flagsd(a, x, y);
	}
}
