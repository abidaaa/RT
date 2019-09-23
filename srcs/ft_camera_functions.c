/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:38:32 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 20:48:52 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			ft_perspective(t_env *e)
{
	t_vector	temp;
	t_vector	look_at_point;

	look_at_point = e->camera.look_at_point;
	e->ray.view_direction = ft_normalize_vector(ft_sub_vector(look_at_point,
				e->camera.eye_point));
	e->camera.u = ft_normalize_vector(ft_cross_product(e->ray.view_direction,
				e->camera.up));
	e->camera.v = ft_cross_product(e->ray.view_direction, e->camera.u);
	e->half_height = tan(e->camera.fov / 2);
	e->camera.aspect_ratio = (double)WIDTH / (double)HEIGHT;
	e->half_width = e->camera.aspect_ratio * e->half_height;
	temp = ft_sub_vector(e->camera.eye_point,
			ft_add_vector(ft_mult_const(e->camera.v, e->half_height),
				ft_mult_const(e->camera.u, e->half_width)));
	e->camera.bottom_left = ft_add_vector(temp, e->ray.view_direction);
	e->camera.x_vec = ft_mult_const(e->camera.u, 2.0 * e->half_width);
	e->camera.y_vec = ft_mult_const(e->camera.v, 2.0 * e->half_height);
}

void			ft_make_ray(t_env *e, int x, int y)
{
	t_vector	view_plane_point;

	e->distance = RAY_DIS_MAX;
	view_plane_point = ft_add_vector(ft_add_vector(e->camera.bottom_left,
				ft_mult_const(e->camera.x_vec, (double)x / (double)WIDTH)),
			ft_mult_const(e->camera.y_vec, (double)y / (double)HEIGHT));
	e->ray.start = e->camera.eye_point;
	e->ray.dir = ft_normalize_vector(ft_sub_vector(view_plane_point,
				e->camera.eye_point));
}

t_camera		ft_new_camera(char **str, int *i)
{
	t_camera	camera;
	char		**tab;

	(*i)++;
	tab = ft_strsplit(str[*i], ' ');
	camera.eye_point = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	(*i)++;
	tab = ft_strsplit(str[*i], ' ');
	camera.look_at_point = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	return (camera);
}
