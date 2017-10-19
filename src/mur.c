/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:27:17 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 16:27:18 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	mur(t_a *a, int x, int y)
{
	if (a->e.flag == 0)
	{
		y = a->d.drawstart - 1;
		while (++y < a->d.drawend)
		{
			if (a->d.side == 0)
				mlx_pixel_put_to_image(a->c, x, y, 0x33CCFF);
			if (a->d.side == 1)
				mlx_pixel_put_to_image(a->c, x, y, 0xFF99FF);
			if (a->d.side == 2)
				mlx_pixel_put_to_image(a->c, x, y, 0x33FF66);
			if (a->d.side == 3)
				mlx_pixel_put_to_image(a->c, x, y, 0xCC9966);
		}
	}
	else
		flag(a, x, y);
}
