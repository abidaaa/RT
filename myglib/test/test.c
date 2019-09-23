/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 13:19:34 by aabouibr          #+#    #+#             */
/*   Updated: 2019/02/10 23:01:37 by aabouibr         ###   ########.fr       */
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

void	ft_mlx_line(int x0, int y0, int x1, int y1, t_params *p, int color)
{
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;

    while (x0 != x1 || y0 != y1) {
		mlx_pixel_put(p->mlx_con, p->window, x0, y0, color);
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 <  dy) { err += dx; y0 += sy; }
    }
}

int key_hook(int key, void *params)
{
	t_params *p;

	p = params;
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_con, p->window);
		exit(0);
	}
	return (0);
}

void drawPixel( int x , int y , float brightness, t_params *p) 
{
    int color = rgb_to_int(255*-brightness, 255*-brightness, 255*-brightness);
    if (color == 0)
        color = 0xFFFFFF;
	mlx_pixel_put(p->mlx_con, p->window, x, y, color);
} 
  
void drawAALine(int x0 , int y0 , int x1 , int y1, t_params *p) 
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
int main()
{
	t_params p;

	init(&p, "Wu line");
	mlx_key_hook(p.window, key_hook,(void *)&p);
	drawAALine(80 , 200 , 550, 150, &p);
    ft_mlx_line (90, 210, 560, 160, &p, 0xFFFFFF);
	mlx_loop(p.mlx_con);
	return (0);
}
