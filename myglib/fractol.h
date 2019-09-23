/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:07:33 by aabouibr          #+#    #+#             */
/*   Updated: 2019/02/10 22:09:09 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "myglib.h"

typedef struct	s_fractal
{
	double		c_re;
	double		c_im;
	double		x;
	double		y;
	double		x_new;
	double		off;
	double		c_re_min;
	double		c_re_max;
	double		c_im_min;
	double		c_im_max;
	double		z;
	int			c;
	double		horizontal;
	double		vertical;
	double		juliax;
	double		juliay;
	int			max_iter;
	int			sier_iter;
	int			fractal;
}				t_fractal;

typedef struct	s_thread
{
	t_params	*p;
	t_fractal	f;
	int			posx;
	int			posy;
	double		mouse_re;
	double		mouse_im;
	int			check;
}				t_thread;

#endif
