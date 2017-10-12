/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:46:24 by prossi            #+#    #+#             */
/*   Updated: 2017/10/11 11:46:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	mlx_pixel_put_to_image(t_c c, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WINSIZE_X * WINSIZE_Y * c.bpp / 8;
	if (x < 0 || y < 0 || y * c.size_line + x * c.bpp / 8 > \
		img_size
		|| x >= c.size_line / (c.bpp / 8) || y >= img_size / \
		c.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = c.bpp / 8;
	c.map[y * c.size_line + x * bit_pix] = color1;
	c.map[y * c.size_line + x * bit_pix + 1] = color2;
	c.map[y * c.size_line + x * bit_pix + 2] = color3;
}

void	ft_mlx(t_a *a)
{
	ft_init_struct(a, 1);
	a->c.init = mlx_init();
	a->c.wdow = mlx_new_window(a->c.init, WINSIZE_X, WINSIZE_Y, \
		"This is the place where I belong");
	a->c.img = mlx_new_image(a->c.init, WINSIZE_X, WINSIZE_Y);
	a->c.map = mlx_get_data_addr(a->c.img, &a->c.bpp, &a->c.size_line, \
		&a->c.endian);
	raycaster(a);
	mlx_put_image_to_window(a->c.init, a->c.wdow, a->c.img, 0, 0);
	mlx_hook(a->c.wdow, 2, (1L << 0), key_hook, a);
	mlx_hook(a->c.wdow, 17, (1L << 17), (int(*)())cross_exit, a);
	mlx_loop(a->c.init);
}
