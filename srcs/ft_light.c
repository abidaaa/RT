/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:27:01 by abida             #+#    #+#             */
/*   Updated: 2019/09/17 20:49:08 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_light				ft_new_light(char **str, int **i)
{
	t_light			light;
	char			**tab;

	(**i)++;
	tab = ft_strsplit(str[**i], ' ');
	light.position = ft_make_vector(ft_atof(tab[0]), ft_atof(tab[1]),
			ft_atof(tab[2]));
	free_array(tab);
	(**i)++;
	tab = ft_strsplit(str[**i], ' ');
	light.intensity = ft_atof(tab[0]);
	free_array(tab);
	(**i)++;
	tab = ft_strsplit(str[**i], ' ');
	light.color = (t_color){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	free_array(tab);
	return (light);
}

void				ft_diffuse(t_env *e, t_scene *scene, t_light_list *list)
{
	int				c;

	c = 255;
	list->light.light_dot_normal =
		ft_dot_product(list->light.intersect_to_light, scene->normal);
	list->light.light_dot_normal = list->light.light_dot_normal < 0 ?
		0.0 : list->light.light_dot_normal;
	e->diffuse.red = list->light.intensity * (double)(scene->color.red / c) *
		(double)(list->light.color.red / c) * list->light.light_dot_normal;
	e->diffuse.green = list->light.intensity *
		(double)(scene->color.green / c) *
		(double)(list->light.color.green / c) * list->light.light_dot_normal;
	e->diffuse.blue = list->light.intensity * (double)(scene->color.blue / c) *
		(double)(list->light.color.blue / c) * list->light.light_dot_normal;
}

void				ft_specular(t_env *e, t_scene *scene, t_light_list *list,
		t_vector dir)
{
	t_vector		reflection;
	t_vector		direction;
	double			term;
	double			r;
	int				c;

	c = 255;
	r = 2.0 * ft_dot_product(list->light.intersect_to_light, scene->normal);
	reflection = ft_mult_const(scene->normal, r);
	direction = ft_sub_vector(list->light.intersect_to_light, reflection);
	term = pow(fmax(ft_dot_product(direction, dir), 0.0), 60);
	e->specular.red = list->light.intensity *
		(double)(list->light.color.red / c) * term;
	e->specular.green = list->light.intensity *
		(double)(list->light.color.green / c) * term;
	e->specular.blue = list->light.intensity *
		(double)(list->light.color.blue / c) * term;
}

void				ft_ambient(t_env *e, t_scene *scene, t_light_list *list)
{
	int				c;

	c = 255;
	e->ambient.red = 0.1 * list->light.intensity *
		(double)(list->light.color.red / c) * (double)(scene->color.red / c);
	e->ambient.green = 0.1 * list->light.intensity *
		(double)(list->light.color.green / c) *
		(double)(scene->color.green / c);
	e->ambient.blue = 0.1 * list->light.intensity *
		(double)(list->light.color.blue / c) * (double)(scene->color.blue / c);
}

void				ft_light(t_env *e, t_scene *head, t_light_list *li,
		t_scene *head_list)
{
	t_vector		temp;
	t_light_list	*list;

	init_phong_color(e);
	temp = e->ray.dir;
	list = li;
	while (list != NULL)
	{
		list->light.intersect_to_light = ft_sub_vector(list->light.position,
				head->intersect_point);
		e->distance = ft_vector_length(list->light.intersect_to_light);
		list->light.intersect_to_light =
			ft_normalize_vector(list->light.intersect_to_light);
		e->ray.start = head->intersect_point;
		e->ray.dir = list->light.intersect_to_light;
		if (!ft_shadow_cast(e, head_list))
		{
			ft_diffuse(e, head, list);
			ft_specular(e, head, list, temp);
			ft_ambient(e, head, list);
			final_color(e);
		}
		list = list->next;
	}
}
