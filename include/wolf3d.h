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

typedef struct		s_a
{
	void			*init;
	void			*wdow;
}					t_a;

#endif
