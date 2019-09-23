/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:15:35 by arezouk           #+#    #+#             */
/*   Updated: 2019/08/02 18:02:13 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	ft_sub_vector(t_vector a, t_vector b)
{
	return (ft_make_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector	ft_mult_vector(t_vector a, t_vector b)
{
	return (ft_make_vector(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vector	ft_mult_const(t_vector v, double b)
{
	return (ft_make_vector(v.x * b, v.y * b, v.z * b));
}

t_vector	ft_div_const(t_vector v, double b)
{
	return (ft_mult_const(v, 1.0 / b));
}

t_vector	ft_add_vector(t_vector a, t_vector b)
{
	return (ft_make_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}
