/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:24:52 by prossi            #+#    #+#             */
/*   Updated: 2017/09/05 15:24:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pimp_libft/my_libft.h"

int		**ft_tabint(int x, int y)
{
	int		**tabi;
	int		i;

	i = 0;
	tabi = 0;
	if (!(tabi = (int **)malloc(sizeof(int *) * y)))
		return (NULL);
	while (i < y)
	{
		if (!(tabi[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		i++;
	}
	return (tabi);
}
