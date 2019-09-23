/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:16:51 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/16 21:18:37 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				ft_shadow_sphere(t_env *e, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	if (ft_sphere_intersection(sphere, e))
		return (1);
	return (0);
}

int				ft_shadow_plane(t_env *e, t_scene *scene)
{
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	if (ft_plane_intersection(plane, e))
		return (1);
	return (0);
}

int				ft_shadow_cone(t_env *e, t_scene *scene)
{
	t_cone		*cone;

	cone = (t_cone *)scene->object;
	if (ft_cone_intersection(cone, e))
		return (1);
	return (0);
}

int				ft_shadow_cylindre(t_env *e, t_scene *scene)
{
	t_cylindre	*cylindre;

	cylindre = (t_cylindre *)scene->object;
	if (ft_cylindre_intersection(cylindre, e))
		return (1);
	return (0);
}
