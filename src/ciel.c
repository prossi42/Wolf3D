/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciel.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:58:57 by prossi            #+#    #+#             */
/*   Updated: 2017/10/19 11:58:59 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	ciel(t_a *a, int x, int y)
{
	y = -1;
	while (++y < a->d.drawstart)
		mlx_pixel_put_to_image(a->c, x, y, 0xFFFFFF + y);
}