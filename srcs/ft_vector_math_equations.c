/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math_equations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:15:49 by arezouk           #+#    #+#             */
/*   Updated: 2019/08/02 18:01:49 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double			ft_vector_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector		ft_normalize_vector(t_vector v)
{
	double		length;

	length = ft_vector_length(v);
	if (length != 0)
	{
		v.x = v.x / length;
		v.y = v.y / length;
		v.z = v.z / length;
	}
	else
	{
		v.x = 0;
		v.y = 0;
		v.z = 0;
	}
	return (v);
}

t_vector		ft_negate_vector(t_vector v)
{
	return (ft_make_vector(-v.x, -v.y, -v.z));
}

t_vector		ft_make_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector		ft_add3_vector(t_vector a, t_vector b, t_vector c)
{
	return (ft_make_vector(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z));
}
