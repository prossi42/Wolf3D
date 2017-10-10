/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 09:48:19 by prossi            #+#    #+#             */
/*   Updated: 2017/10/10 09:48:21 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		ft_affich(t_a *a, int option)
{
	(void)a;
	if (option == 0)
	{
		ft_putstr("\nusage : ./wolf3d map\n");
		ft_putstr("\t ---> Square map only fill with 0 -> 9 and spaces\n\n");
	}
	if (option == 1)
		ft_putstr("\nError in Open or Read functions\n\n");
	if (option == 2)
		ft_putstr("\nMap error, consult usage --> ./wolf3d\n\n");
}
