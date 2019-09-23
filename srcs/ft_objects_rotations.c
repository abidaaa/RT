/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 18:49:33 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/16 22:02:22 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			ft_sphere_rot(t_env *e, t_scene *scene, int *ret)
{
	t_sphere	*sphere;
	t_vector	temp1;
	t_vector	temp2;

	sphere = (t_sphere *)scene->object;
	temp1 = e->ray.start;
	temp2 = e->ray.dir;
	e->ray.start = ft_rot(e->ray.start, 0, 0, 0);
	e->ray.dir = ft_rot(e->ray.dir, 0, 0, 0);
	if (ft_sphere_intersection(sphere, e))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
	e->ray.start = temp1;
	e->ray.dir = temp2;
}

void			ft_cone_rot(t_env *e, t_scene *scene, int *ret)
{
	t_cone		*cone;

	cone = (t_cone *)scene->object;
	if (ft_cone_intersection(cone, e))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void			ft_plane_rot(t_env *e, t_scene *scene, int *ret)
{
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	if (ft_plane_intersection(plane, e))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void			ft_cylindre_rot(t_env *e, t_scene *scene, int *ret)
{
	t_cylindre	*cylindre;

	cylindre = (t_cylindre *)scene->object;
	if (ft_cylindre_intersection(cylindre, e))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}
