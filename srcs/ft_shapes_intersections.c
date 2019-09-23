/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_intersections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:32:09 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/16 21:15:51 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_bool			check_min_distance(t_env *e)
{
	if (((e->d1 < e->d0 || e->d0 < RAY_DIS_MIN) && e->d1 > RAY_DIS_MIN)
			&& (e->d1 < e->distance))
	{
		e->distance = e->d1;
		return (true);
	}
	else if (((e->d0 < e->d1 || e->d1 < RAY_DIS_MIN) && e->d0 > RAY_DIS_MIN)
			&& (e->d0 < e->distance))
	{
		e->distance = e->d0;
		return (true);
	}
	else
		return (false);
}

t_bool			ft_sphere_intersection(t_sphere *sphere, t_env *e)
{
	t_vector	origin;

	origin = ft_sub_vector(e->ray.start, sphere->centre);
	e->a = ft_dot_product(e->ray.dir, e->ray.dir);
	e->b = ft_dot_product(origin, e->ray.dir) * 2;
	e->c = ft_dot_product(origin, origin) - sphere->radius * sphere->radius;
	e->disc = (e->b * e->b) - (4 * e->a * e->c);
	if (e->disc < 0)
		return (false);
	e->d0 = (-e->b - sqrtf(e->disc)) / (2 * e->a);
	e->d1 = (-e->b + sqrtf(e->disc)) / (2 * e->a);
	return (check_min_distance(e));
}

t_bool			ft_cone_intersection(t_cone *cone, t_env *e)
{
	t_vector	origin;
	double		tang;

	tang = (cone->angle / 2);
	origin = ft_sub_vector(e->ray.start, cone->position);
	e->a = ft_dot_product(e->ray.dir, e->ray.dir) - (1 + tang * tang) *
		(ft_dot_product(e->ray.dir, cone->normal) *
			ft_dot_product(e->ray.dir, cone->normal));
	e->b = 2 * (ft_dot_product(e->ray.dir, origin) - (1 + tang * tang) *
		ft_dot_product(e->ray.dir, cone->normal) *
			ft_dot_product(origin, cone->normal));
	e->c = ft_dot_product(origin, origin) - (1 + tang * tang) *
		(ft_dot_product(origin, cone->normal) *
			ft_dot_product(origin, cone->normal));
	e->disc = (e->b * e->b) - (4 * e->a * e->c);
	if (e->disc < 0)
		return (false);
	e->d0 = (-e->b - sqrt(e->disc)) / (2 * e->a);
	e->d1 = (-e->b + sqrt(e->disc)) / (2 * e->a);
	return (check_min_distance(e));
}

t_bool			ft_cylindre_intersection(t_cylindre *cylindre, t_env *e)
{
	t_vector	origin;

	origin = ft_sub_vector(e->ray.start, cylindre->centre);
	e->a = ft_dot_product(e->ray.dir, e->ray.dir) -
		ft_dot_product(e->ray.dir, cylindre->normal) *
			ft_dot_product(e->ray.dir, cylindre->normal);
	e->b = 2 * (ft_dot_product(e->ray.dir, origin) -
		ft_dot_product(e->ray.dir, cylindre->normal) *
			ft_dot_product(origin, cylindre->normal));
	e->c = ft_dot_product(origin, origin) -
		(ft_dot_product(origin, cylindre->normal) *
			ft_dot_product(origin, cylindre->normal)) -
				cylindre->radius * cylindre->radius;
	e->disc = (e->b * e->b) - (4 * e->a * e->c);
	if (e->disc < 0)
		return (false);
	e->d0 = (-e->b - sqrtf(e->disc)) / (2 * e->a);
	e->d1 = (-e->b + sqrtf(e->disc)) / (2 * e->a);
	return (check_min_distance(e));
}

t_bool			ft_plane_intersection(t_plane *plane, t_env *e)
{
	t_vector	temp;
	double		dir_norm;
	double		distance;

	dir_norm = ft_dot_product(e->ray.dir, plane->normal);
	if (fabs(dir_norm) > RAY_DIS_MIN)
	{
		temp = ft_sub_vector(plane->position, e->ray.start);
		distance = ft_dot_product(temp, plane->normal) / dir_norm;
		if (distance < e->distance && distance > RAY_DIS_MIN)
		{
			e->distance = distance;
			return (true);
		}
	}
	return (false);
}
