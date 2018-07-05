/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 10:51:30 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/02 16:32:52 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**------------------------------ External Headers ------------------------------
*/

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
**----------------------------- Macros Definition -----------------------------
*/

# define WIDTH 	800
# define HEIGHT 600

/*
**---------------------------- Structure Definition ---------------------------
*/

typedef struct		s_2dvector
{
	int				x;
	int				y;
}					t_2dvector;

typedef struct		s_connect
{
	t_2dvector		mouse;
}					t_connect;

typedef struct		s_fdf
{
	int				fd;
	char			*graph;
	void			*mlx;
	void			*win;
	int				**chart;
	int				length;
	int				check;
	int				width;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	t_connect		connect;
	unsigned long	color;
}					t_fdf;

/*
**----------------------------- Helping Functions ----------------------------
*/

void				init(t_fdf *draw);
void				draw_lines(t_fdf *draw, int x, int y);
void				draw_graph(t_fdf *draw, int *tabxy, int x, int y);
void				get_wireframe(t_fdf *key);
int					keyboard(int keycode, t_fdf *key);
void				get_map(t_fdf *connect);
int					parser(t_fdf *connect);
#endif
