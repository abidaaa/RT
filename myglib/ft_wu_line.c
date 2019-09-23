/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wu_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:59:44 by aabouibr          #+#    #+#             */
/*   Updated: 2019/02/10 23:02:57 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "myglib.h"
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void drawPixel( int x , int y , float brightness, t_params *p)
{
	int color = rgb_to_int(255*-brightness, 255*-brightness, 255*-brightness);
	if (color == 0)
		color = 0xFFFFFF;
	mlx_pixel_put(p->mlx_con, p->window, x, y, color);
}

void draw_wu_line(int x0 , int y0 , int x1 , int y1, t_params *p)
{
	int steep;
	double integ;
	double fpart;
	float dx;
	float dy;
	float gradient;
	int xpxl1;
	int xpxl2;
	float intersectY;
	int x;

	steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep)
	{
		ft_swap(&x0 , &y0);
		ft_swap(&x1 , &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0 ,&x1);
		ft_swap(&y0 ,&y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	gradient = dy / dx;
	if (dx == 0.0)
		gradient = 1;
	xpxl1 = x0;
	xpxl2 = x1;
	intersectY = y0;
	if (steep)
	{
		x = xpxl1 - 1;
		while (++x <= xpxl2)
		{
			fpart = modf(intersectY, &integ);
			drawPixel(integ, x, 1 - fpart, p);
			drawPixel(integ - 1, x, fpart, p);
			intersectY += gradient;
		}
	}
	else
	{
		x = xpxl1 - 1;
		while (++x <= xpxl2)
		{
			fpart = modf(intersectY, &integ);
			drawPixel(x, integ, 1 - fpart, p);
			drawPixel(x, integ - 1, fpart, p);
			intersectY += gradient;
		}
	}
}
