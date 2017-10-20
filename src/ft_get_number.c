/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:21:53 by prossi            #+#    #+#             */
/*   Updated: 2017/10/11 11:21:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	ft_get_number(t_a *a)
{
	char	**tabnl;
	char	**tabsp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tabnl = NULL;
	tabnl = ft_strsplit(a->buf, '\n');
	while (tabnl[i])
	{
		tabsp = ft_strsplit(tabnl[i], ' ');
		while (tabsp[j])
		{
			a->tabtmp[k][j] = ft_atoi(tabsp[j]);
			j++;
		}
		freetabchar(tabsp, a->b.tmp);
		j = 0;
		k++;
		i++;
	}
	freetabchar(tabnl, a->b.countnl);
}
