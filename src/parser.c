/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:16:14 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/02 13:53:19 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int			alloc_pos_all(t_fdf *connect, char *line)
{
	int		x;
	char	**pos;

	x = 0;
	pos = ft_strsplit(line, ' ');
	while (pos[x])
	{
		free(pos[x]);
		x++;
	}
	if (connect->length == 0)
		connect->width = x;
	else if (x != connect->width)
		return (-1);
	free(line);
	free(pos);
	connect->length++;
	return (0);
}

int			alloc_pos(t_fdf *connect)
{
	char	*line;
	int		ret;

	line = NULL;
	connect->length = 0;
	connect->width = 0;
	while ((ret = get_next_line(connect->fd, &line)) > 0)
	{
		if (alloc_pos_all(connect, line) == -1)
			return (-1);
	}
	connect->chart = malloc(sizeof(int*) * connect->length);
	close(connect->fd);
	connect->fd = open(connect->graph, O_RDONLY);
	return (0);
}

int			parser(t_fdf *connect)
{
	char	*line;
	char	**pos;
	int		xypos[3];

	xypos[1] = 0;
	if (alloc_pos(connect) == -1)
		return (-1);
	while ((xypos[2] = get_next_line(connect->fd, &line)) > 0)
	{
		xypos[0] = 0;
		pos = ft_strsplit(line, ' ');
		connect->chart[xypos[1]] = (int *)malloc(sizeof(int) * connect->width);
		while (pos[xypos[0]])
		{
			connect->chart[xypos[1]][xypos[0]] = ft_atoi(pos[xypos[0]]);
			free(pos[xypos[0]]);
			xypos[0]++;
		}
		free(pos);
		xypos[1]++;
	}
	return (0);
}
