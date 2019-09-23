/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <arezouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:16:30 by arezouk           #+#    #+#             */
/*   Updated: 2019/08/16 22:06:10 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			sphere_normal(t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	scene->normal = ft_sub_vector(scene->intersect_point, sphere->centre);
	scene->normal = ft_normalize_vector(scene->normal);
}

void			plane_normal(t_scene *scene)
{
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	scene->normal = plane->normal;
}

void			cone_normal(t_scene *scene, t_env *e)
{
	t_cone		*cone;
	double		x;
	double		temp;
	double		m;
	double		a;

	cone = (t_cone *)scene->object;
	cone->tang = tan(cone->angle / 2);
	x = ft_dot_product(ft_sub_vector(e->camera.eye_point, cone->position),
			cone->normal);
	temp = ft_dot_product(e->ray.dir, cone->normal) * e->distance;
	m = x + temp;
	a = m * cone->tang * cone->tang;
	scene->normal = ft_normalize_vector(
			ft_sub_vector(ft_sub_vector(
					ft_sub_vector(scene->intersect_point,
						cone->position), ft_mult_const(cone->normal, m)),
							ft_mult_const(cone->normal, a)));
}

void			cylindre_normal(t_scene *scene, t_env *e)
{
	t_cylindre	*cylindre;
	double		x;
	double		temp;
	double		m;

	cylindre = (t_cylindre *)scene->object;
	x = ft_dot_product(ft_sub_vector(e->camera.eye_point, cylindre->centre),
			cylindre->normal);
	temp = ft_dot_product(e->ray.dir, cylindre->normal) * e->distance;
	m = x + temp;
	scene->normal = ft_normalize_vector(ft_sub_vector(ft_sub_vector(
					scene->intersect_point, cylindre->centre),
						ft_mult_const(cylindre->normal, m)));
}

void			ft_get_normal(t_env *e, t_scene *head)
{
	t_vector	temp;
	t_scene		*scene;

	scene = head;
	temp = ft_mult_const(e->ray.dir, e->distance);
	scene->intersect_point = ft_add_vector(e->ray.start, temp);
	if (scene->type == sphere1)
	{
		sphere_normal(scene);
	}
	else if (scene->type == plane1)
	{
		plane_normal(scene);
	}
	else if (scene->type == cone1)
	{
		cone_normal(scene, e);
	}
	else if (scene->type == cylindre1)
	{
		cylindre_normal(scene, e);
	}
}
