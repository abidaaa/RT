/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math_equations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:52:34 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 18:01:20 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double			ft_dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double			ft_dot_product_xz(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.z * b.z));
}

t_vector		ft_cross_product(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = (a.y * b.z) - (b.y * a.z);
	v.y = (a.z * b.x) - (b.z * a.x);
	v.z = (a.x * b.y) - (b.x * a.y);
	return (v);
}
