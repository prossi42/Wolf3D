/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:44:46 by prossi            #+#    #+#             */
/*   Updated: 2017/10/09 14:44:53 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		ft_open(t_a *a, char *argv)
{
	if ((a->fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	if (!(a->buf = ft_readfile(a->fd)))
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_a		a;

	if (argc != 2)
	{
		ft_affich(&a, 0);
		return (-1);
	}
	if (ft_open(&a, argv[1]) == -1)
	{
		ft_affich(&a, 1);
		return (-1);
	}
	if (ft_parsing(&a) == -1)
	{
		ft_affich(&a, 2);
		return (-1);
	}
	ft_mlx(&a);
	return (0);
}
