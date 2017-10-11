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

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/include/off_libft/libft.h"
# include "../libft/include/pimp_libft/my_libft.h"
# define WINSIZE_X 600
# define WINSIZE_Y 600

typedef struct		s_d
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
}					t_d;

typedef struct		s_c
{
	void			*init;
	void			*wdow;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
}					t_c;

typedef struct		s_b
{
	int				count;
	int				countsp;
	int				countnl;
	int				tmp;
	int				tmpsp;
	int				i;
}					t_b;

typedef struct		s_a
{
	int				fd;
	char			*buf;
	int				**tabi;
	int				**tabtmp;
	int				xmax;
	int				ymax;
	t_b				b;
	t_c				c;
	t_d				d;
}					t_a;

void				ft_affich(t_a *a, int option);
void				ft_init_struct(t_a *a, int option);
int					ft_parsing(t_a *a);
void				ft_get_number(t_a *a);
void				ft_mlx(t_a *a);
int					key_hook(int keycode, t_a *a);
void				free_all(t_a *a);
void				cross_exit(t_a *a);
int					find_a_place(t_a *a);
void				raycaster(t_a *a);
#endif
