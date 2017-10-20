/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetabint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 12:49:50 by prossi            #+#    #+#             */
/*   Updated: 2017/10/20 12:49:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pimp_libft/my_libft.h"

void	freetabint(int **tab, int ymax)
{
	int		y;

	y = -1;
	while (++y < ymax)
		free(tab[y]);
	free(tab);
	tab = NULL;
}
