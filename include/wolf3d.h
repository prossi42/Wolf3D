/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:35:11 by prossi            #+#    #+#             */
/*   Updated: 2017/10/09 14:36:44 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../mlx/mlx.h"
# include "../libft/include/off_libft/libft.h"
# include "../libft/include/pimp_libft/my_libft.h"
# define WINSIZE_X 600
# define WINSIZE_Y 600

typedef struct		s_b
{
	int				count;
	int				countsp;
	int				countnl;
	int				tmp;
	int				tmpsp;
	int				i;
	int				ct;
}					t_b;

typedef struct		s_a
{
	int				fd;
	char			*buf;
	t_b				b;
}					t_a;

void				ft_affich(t_a *a, int option);
void				ft_init_struct(t_a *a, int option);
int					ft_parsing(t_a *a);
#endif
