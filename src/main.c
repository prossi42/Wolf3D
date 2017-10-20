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

int		check_ext(char *argv)
{
	int		c;

	c = ft_strlen(argv) - 1;
	if (argv[c] != 'd')
		return (-1);
	if (argv[c - 1] != '3')
		return (-1);
	if (argv[c - 2] != 'w')
		return (-1);
	if (argv[c - 3] != '.')
		return (-1);
	return (0);
}

int		ft_open(t_a *a, char *argv)
{
	if ((a->fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	a->buf[read(a->fd, a->buf, BUFF_SIZE)] = '\0';
	close(a->fd);
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
	if (check_ext(argv[1]) == -1)
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
