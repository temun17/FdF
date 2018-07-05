/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:15:31 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/30 16:34:31 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	get_map(t_fdf *connect)
{
	if (parser(connect) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	get_wireframe(connect);
}

int		main(int argc, char **argv)
{
	t_fdf	test;

	if (argc == 2)
	{
		test.graph = argv[1];
		test.fd = open(test.graph, O_RDONLY);
		get_map(&test);
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <input filename> ");
		exit(0);
	}
	return (0);
}
