/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:18:23 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/02 16:57:35 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void		token(int keycode, t_fdf *key)
{
	if ((keycode >= 123 && keycode <= 126))
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx -= 20;
		if (keycode == 124)
			key->dx += 20;
		if (keycode == 125)
			key->dy += 20;
		if (keycode == 126)
			key->dy -= 20;
		init(key);
	}
}

int			keyboard(int keycode, t_fdf *key)
{
	if (keycode == 53)
	{
		exit(0);
		return (0);
	}
	if (keycode == 8)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->check % 10 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 1;
		init(key);
	}
	token(keycode, key);
	return (0);
}

t_2dvector	new_2dvectors(int x, int y)
{
	t_2dvector	point;

	point.x = x;
	point.y = y;
	return (point);
}

int			manage_mouse(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->connect.mouse = new_2dvectors(x, y);
	return (0);
}

void		get_wireframe(t_fdf *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "Whaddduppp Allen!");
	init(key);
	mlx_key_hook(key->win, keyboard, key);
	mlx_loop(key->mlx);
}
