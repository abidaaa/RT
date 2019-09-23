/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:14:35 by aabouibr          #+#    #+#             */
/*   Updated: 2019/02/12 13:14:21 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib.h"

void	ft_mlx_line(t_point point, t_params *p)
{
	int dx = abs(point.x1 - point.x0), sx = point.x0 < point.x1 ? 1 : -1;
	int dy = abs(point.y1 - point.y0), sy = point.y0 < point.y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;

	while (point.x0 != point.x1 || point.y0 != point.y1)
	{
		mlx_pixel_put(p->mlx_con, p->window, point.x0, point.y0, point.color);
		int e2 = err;
		if (e2 > -dx) 
		{
			err -= dy;
			point.x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			point.y0 += sy;
		}
	}
}
