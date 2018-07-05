/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:14:52 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/02 16:27:33 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	draw_graph(t_fdf *draw, int *posxy, int x1, int y1)
{
	int		posx[2];
	int		posy[2];
	int		a[2];
	int		x0;
	int		y0;

	x0 = posxy[0];
	y0 = posxy[1];
	posx[0] = abs(x1 - x0);
	posx[1] = x0 < x1 ? 1 : -1;
	posy[0] = abs(y1 - y0);
	posy[1] = y0 < y1 ? 1 : -1;
	a[0] = (posx[0] > posy[0] ? posx[0] : -posy[0]) / 4;
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(draw->mlx, draw->win, x0, y0, draw->color);
		a[1] = a[0];
		a[1] > -posx[0] ? a[0] -= posy[0] : 1;
		a[1] > -posx[0] ? x0 += posx[1] : 1;
		a[1] < posy[0] ? a[0] += posx[0] : 1;
		a[1] < posy[0] ? y0 += posy[1] : 1;
	}
}

/*
** check_draw function allows to change the height and width of graph
*/

void	check_draw(t_fdf *draw)
{
	if (draw->check == 0)
	{
		draw->z = -3;
		draw->dx = (600 * 0.3);
		draw->dy = 0;
		draw->sx = (600 * 0.6) / (draw->width);
		draw->sy = (600 * 0.3) / (draw->length);
		draw->color = 0x0016a60c;
	}
	draw->check++;
}

void	draw_lines(t_fdf *draw, int x, int y)
{
	int		posxy[2];

	posxy[0] = (x - y) + draw->dx;
	posxy[1] = draw->chart[y / draw->sy][x / draw->sx] * draw->z
		+ x + y + draw->dy;
	if (y / draw->sy < draw->length && x / draw->sx < draw->width - 1)
		draw_graph(draw, posxy, draw->dx + ((x + draw->sx) - y),
		draw->dy + draw->chart[y / draw->sy][x / draw->sx + 1] * draw->z +
		(x + draw->sx) + y);
	if (x / draw->sx < draw->width && y / draw->sy < draw->length - 1)
		draw_graph(draw, posxy, draw->dx + (x - (y + draw->sy)),
		draw->dy + draw->chart[y / draw->sy + 1][x / draw->sx] * draw->z +
		x + (y + draw->sy));
}

void	init(t_fdf *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_draw(draw);
	while (x / draw->sx < draw->width || y / draw->sy < draw->length - 1)
	{
		if (x / 20 == draw->width)
		{
			x = 0;
			y += draw->sy;
		}
		draw_lines(draw, x, y);
		x += draw->sx;
	}
}
