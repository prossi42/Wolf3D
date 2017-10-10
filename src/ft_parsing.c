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

// void	ft_get_number(t_first *first)
// {
// 	char	**tabnl;
// 	char	**tabsp;
// 	int		i;
// 	int		j;
// 	int		k;
//
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	tabnl = NULL;
// 	tabnl = ft_strsplit(a->buf, '\n');
// 	while (tabnl[i])
// 	{
// 		tabsp = ft_strsplit(tabnl[i], ' ');
// 		while (tabsp[j])
// 		{
// 			first->pa.tabi[k][j] = ft_atoi(tabsp[j]);
// 			j++;
// 		}
// 		j = 0;
// 		k++;
// 		i++;
// 	}
// 	free(tabnl);
// 	free(tabsp);
// }

void	ft_checksd(t_a *a)
{
	int		i;

	i = -1;
	a->b.count = 0;
	while (a->buf[++i])
	{
		if (a->buf[i] >= 0 && a->buf[i] <= 9)
			a->b.count++;
		if (a->buf[i] == '\n')
			break;
	}
	ft_putnbr(a->b.count);

	LE PUTAIN DE COUNT QUI MARCHE PAS A CAUSE CONDITION IF if (a->buf[i] >= 0 && a->buf[i] <= 9)
}

int		ft_count(t_a *a)
{
	while (a->buf[++a->b.i])
	{
		if (a->buf[a->b.i] >= 0 && a->buf[a->b.i] <= 9)
			a->b.count++;
		if (a->buf[a->b.i] == ' ')
			a->b.countsp++;
		if (a->buf[a->b.i] == '\n')
		{
			a->b.ct = a->b.count;
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
	ft_checksd(a);
	ft_putstr("Nombre de chiffres :");
	ft_putnbr(a->b.count);
	ft_putstr("\nNombre de ligne :");
	ft_putnbr(a->b.countnl);
	return (0);
}
