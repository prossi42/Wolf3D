/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetabchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 13:05:29 by prossi            #+#    #+#             */
/*   Updated: 2017/10/20 13:05:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pimp_libft/my_libft.h"

void	freetabchar(char **tab, int ymax)
{
	int		y;

	y = -1;
	while (++y < ymax)
		ft_strdel(&tab[y]);
	free(tab);
	tab = NULL;
}
