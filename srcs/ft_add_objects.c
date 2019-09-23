/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:52:00 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/16 17:01:52 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_add_sphere(t_scene **objects, char **scene,
int *i, t_scene **tmp)
{
	t_sphere			*sphere;

	sphere = ft_new_sphere(scene, &i);
	(*objects)->type = sphere1;
	(*objects)->object = (void *)sphere;
	(*objects)->color = sphere->color;
	(*objects)->next = (t_scene *)malloc(sizeof(t_scene));
	*tmp = *objects;
	(*objects) = (*objects)->next;
}

void		ft_add_plane(t_scene **objects, char **scene,
int *i, t_scene **tmp)
{
	t_plane			*plane;

	plane = ft_new_plane(scene, &i);
	(*objects)->type = plane1;
	(*objects)->object = (void *)plane;
	(*objects)->color = plane->color;
	(*objects)->next = (t_scene *)malloc(sizeof(t_scene));
	*tmp = *objects;
	(*objects) = (*objects)->next;
}

void		ft_add_cone(t_scene **objects, char **scene,
int *i, t_scene **tmp)
{
	t_cone			*cone;

	cone = ft_new_cone(scene, &i);
	(*objects)->type = cone1;
	(*objects)->object = (void *)cone;
	(*objects)->color = cone->color;
	(*objects)->next = (t_scene *)malloc(sizeof(t_scene));
	*tmp = *objects;
	(*objects) = (*objects)->next;
}

void		ft_add_cylindre(t_scene **objects, char **scene,
int *i, t_scene **tmp)
{
	t_cylindre			*cylindre;

	cylindre = ft_new_cylindre(scene, &i);
	(*objects)->type = cylindre1;
	(*objects)->object = (void *)cylindre;
	(*objects)->color = cylindre->color;
	(*objects)->next = (t_scene *)malloc(sizeof(t_scene));
	*tmp = *objects;
	(*objects) = (*objects)->next;
}

void		ft_add_light(t_light_list **light_list, char **scene,
int *i, t_light_list **temp_light)
{
	(*light_list)->light = ft_new_light(scene, &i);
	(*light_list)->next = (t_light_list *)malloc(sizeof(t_light_list));
	*temp_light = *light_list;
	(*light_list) = (*light_list)->next;
}
