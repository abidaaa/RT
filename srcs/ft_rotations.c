/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <arezouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:32:42 by arezouk           #+#    #+#             */
/*   Updated: 2019/08/16 21:20:10 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector		ft_rot_x(t_vector v, double angle)
{
	t_vector	res;

	res.x = v.x;
	res.y = (v.y * cos(angle)) - (v.z * sin(angle));
	res.z = (v.y * sin(angle)) + (v.z * cos(angle));
	return (res);
}

t_vector		ft_rot_y(t_vector v, double angle)
{
	t_vector	res;

	res.x = (v.x * cos(angle)) + (v.z * sin(angle));
	res.y = v.y;
	res.z = (-v.x * sin(angle)) + (v.z * cos(angle));
	return (res);
}

t_vector		ft_rot_z(t_vector v, double angle)
{
	t_vector	res;

	res.x = (v.x * cos(angle)) - (v.y * sin(angle));
	res.y = (v.x * sin(angle)) + (v.y * cos(angle));
	res.z = v.z;
	return (res);
}

double			ft_radians(double degrees)
{
	double		radians;

	radians = degrees * M_PI / 180.0;
	return (radians);
}

t_vector		ft_rot(t_vector v, double x, double y, double z)
{
	t_vector res;

	res.x = (v.x * cos(y) * cos(z)) - (v.y * sin(z) * cos(y)) + (v.z * sin(y));
	res.y = (v.x * (sin(x) * sin(y) * cos(z) + cos(x) * sin(z)) -
			(v.y * (sin(z) * sin(y) * sin(x) - cos(x) * cos(z))) -
			(v.z * sin(x) * cos(y)));
	res.z = (v.x * (-sin(y) * cos(x) * cos(z) + sin(x) * sin(z)) +
			(v.y * (sin(y) * cos(x) * sin(z) + sin(x) * cos(z))) +
			(v.z * cos(y) * cos(x)));
	return (res);
}
