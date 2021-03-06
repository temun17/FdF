/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 22:59:40 by atemunov          #+#    #+#             */
/*   Updated: 2018/05/01 23:00:09 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_sqrt(float nb)
{
	float	x;

	x = 0;
	while (x * x < nb)
		x++;
	return (x);
}
