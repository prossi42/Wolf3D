/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:05:03 by prossi            #+#    #+#             */
/*   Updated: 2017/10/10 10:05:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	fill_with_one(t_a *a)
{
	int		y;
	int		x;

	y = -1;
	while (++y < a->b.countnl + 2)
	{
		x = -1;
		while (++x < a->b.tmp + 2)
			a->tabi[y][x] = 1;
	}
}

void	create_walls(t_a *a)
{
	int		y;
	int		x;

	y = 0;
	while (++y < a->b.countnl + 1)
	{
		x = 0;
		while (++x < a->b.tmp + 1)
			a->tabi[y][x] = a->tabtmp[y - 1][x - 1];
	}
}

int		ft_count(t_a *a)
{
	while (a->buf[++a->b.i])
	{
		if (a->buf[a->b.i] >= '0' && a->buf[a->b.i] <= '9')
			a->b.count++;
		if (a->buf[a->b.i] == ' ')
			a->b.countsp++;
		if (a->buf[a->b.i] == '\n')
		{
			if (a->b.countnl != 0)
			{
				if (a->b.count != a->b.tmp)
					return (-1);
				if (a->b.countsp != a->b.tmpsp)
					return (-1);
			}
			a->b.countnl++;
			a->b.tmp = a->b.count;
			a->b.tmpsp = a->b.countsp;
			a->b.count = 0;
			a->b.countsp = 0;
		}
	}
	return (0);
}

int		ft_check(t_a *a)
{
	int		i;

	i = -1;
	if (a->buf[0] == '\0')
		return (-1);
	while (a->buf[++i])
	{
		if ((a->buf[i] < '0' || a->buf[i] > '9') && a->buf[i] != '\n' && \
		a->buf[i] != ' ')
			return (-1);
		if ((a->buf[i] >= '0' && a->buf[i] <= '9') && i > 0 && a->buf[i - 1] \
		!= ' ' && a->buf[i - 1] != '\n')
			return (-1);
		if ((a->buf[i] >= '0' && a->buf[i] <= '9') && a->buf[i + 1] != ' ' \
		&& a->buf[i + 1] != '\n' && a->buf[i + 1] != '\0')
			return (-1);
	}
	return (0);
}

int		ft_parsing(t_a *a)
{
	if (ft_check(a) == -1)
		return (-1);
	ft_init_struct(a, 0);
	if (ft_count(a) == -1)
		return (-1);
	if (!(a->tabtmp = ft_tabint(a->b.tmp, a->b.countnl)))
		return (-1);
	if (!(a->tabi = ft_tabint(a->b.tmp + 2, a->b.countnl + 2)))
		return (-1);
	fill_with_one(a);
	ft_get_number(a);
	create_walls(a);
	a->xmax = a->b.tmp + 2;
	a->ymax = a->b.countnl + 2;
	return (0);
}
