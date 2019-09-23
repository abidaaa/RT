/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:17:00 by abida             #+#    #+#             */
/*   Updated: 2019/09/16 16:59:22 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char			**tab_split(char **str, int **i)
{
	char		**tab;

	(**i)++;
	tab = ft_strsplit(str[**i], ' ');
	return (tab);
}

t_sphere		*ft_new_sphere(char **str, int **i)
{
	t_sphere	*sphere;
	char		**tab;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	tab = tab_split(str, i);
	sphere->centre = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	sphere->rotation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	sphere->radius = ft_atof(tab[0]);
	free_array(tab);
	tab = tab_split(str, i);
	sphere->color = (t_color){ft_atof(tab[0]), ft_atof(tab[1]),
		ft_atof(tab[2])};
	free_array(tab);
	tab = tab_split(str, i);
	sphere->translation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	sphere->centre = ft_add_vector(sphere->centre, sphere->translation);
	return (sphere);
}

t_cylindre		*ft_new_cylindre(char **str, int **i)
{
	t_cylindre	*cylindre;
	char		**tab;

	cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
	tab = tab_split(str, i);
	cylindre->centre = (t_vector){ft_atof(tab[0]), ft_atof(tab[1]),
		ft_atof(tab[2])};
	free_array(tab);
	tab = tab_split(str, i);
	cylindre->rotation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	cylindre->radius = ft_atof(tab[0]);
	free_array(tab);
	tab = tab_split(str, i);
	cylindre->color = (t_color){ft_atof(tab[0]), ft_atof(tab[1]),
		ft_atof(tab[2])};
	free_array(tab);
	get_cyl_translation_and_normal(cylindre, tab, str, i);
	return (cylindre);
}

t_cone			*ft_new_cone(char **str, int **i)
{
	t_cone		*cone;
	char		**tab;

	cone = (t_cone *)malloc(sizeof(t_cone));
	tab = tab_split(str, i);
	cone->position = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	cone->rotation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	cone->angle = ft_radians(ft_atof(tab[0]));
	free_array(tab);
	tab = tab_split(str, i);
	cone->color = (t_color){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	free_array(tab);
	get_cone_translation_and_normal(cone, tab, str, i);
	return (cone);
}

t_plane			*ft_new_plane(char **str, int **i)
{
	t_plane		*plane;
	char		**tab;

	plane = (t_plane *)malloc(sizeof(t_plane));
	tab = tab_split(str, i);
	plane->normal = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	plane->rotation = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	plane->position = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	tab = tab_split(str, i);
	plane->color = (t_color){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	free_array(tab);
	get_plane_translation_and_normal(plane, tab, str, i);
	return (plane);
}
