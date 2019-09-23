/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:14:11 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 16:51:31 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

t_vector		ft_make_vector(double x, double y, double z);
t_vector		ft_add_vector(t_vector a, t_vector b);
t_vector		ft_add3_vector(t_vector a, t_vector b, t_vector c);
t_vector		ft_sub_vector(t_vector a, t_vector b);
t_vector		ft_mult_vector(t_vector a, t_vector b);
t_vector		ft_mult_const(t_vector a, double b);
t_vector		ft_div_vector(t_vector a, t_vector b);
t_vector		ft_div_const(t_vector a, double b);
t_vector		ft_normalize_vector(t_vector v);
t_vector		ft_cross_product(t_vector a, t_vector b);
double			ft_vector_length(t_vector v);
double			ft_dot_product(t_vector a, t_vector b);
double			ft_dot_product_xz(t_vector a, t_vector b);

#endif
