/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_translation_and_normal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <arezouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:17:00 by abida             #+#    #+#             */
/*   Updated: 2019/09/16 16:47:56 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cylindre		*get_cyl_translation_and_normal(t_cylindre *cylindre,
		char **tab, char **str, int **i)
{
	tab = tab_split(str, i);
	cylindre->translation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	cylindre->normal = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	cylindre->centre = ft_add_vector(cylindre->centre, cylindre->translation);
	cylindre->normal = ft_rot(cylindre->normal, ft_radians(cylindre->rotation.x)
			, 0, ft_radians(cylindre->rotation.z));
	return (cylindre);
}

t_cone			*get_cone_translation_and_normal(t_cone *cone, char **tab,
		char **str, int **i)
{
	tab = tab_split(str, i);
	cone->translation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	cone->normal = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	cone->position = ft_add_vector(cone->position, cone->translation);
	cone->normal = ft_rot(cone->normal, ft_radians(cone->rotation.x), 0,
			ft_radians(cone->rotation.z));
	return (cone);
}

t_plane			*get_plane_translation_and_normal(t_plane *plane, char **tab,
		char **str, int **i)
{
	tab = tab_split(str, i);
	plane->translation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	plane->position = ft_add_vector(plane->position, plane->translation);
	plane->normal = ft_rot(plane->normal, ft_radians(plane->rotation.x), 0,
			ft_radians(plane->rotation.z));
	return (plane);
}
