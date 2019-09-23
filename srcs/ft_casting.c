/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <arezouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:32:46 by abida             #+#    #+#             */
/*   Updated: 2019/08/16 21:54:38 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				ft_ray_cast(t_env *e, t_scene *head)
{
	int			ret;

	ret = 0;
	e->object = NULL;
	while (head != NULL)
	{
		if (head->type == sphere1)
			ft_sphere_rot(e, head, &ret);
		else if (head->type == plane1)
			ft_plane_rot(e, head, &ret);
		else if (head->type == cone1)
			ft_cone_rot(e, head, &ret);
		else if (head->type == cylindre1)
			ft_cylindre_rot(e, head, &ret);
		head = head->next;
	}
	return (ret);
}

t_bool			ft_shadow_cast(t_env *e, t_scene *head)
{
	while (head != NULL)
	{
		if (head->type == sphere1)
			if (ft_shadow_sphere(e, head))
				return (true);
		if (head->type == plane1)
			if (ft_shadow_plane(e, head))
				return (true);
		if (head->type == cone1)
			if (ft_shadow_cone(e, head))
				return (true);
		if (head->type == cylindre1)
			if (ft_shadow_cylindre(e, head))
				return (true);
		head = head->next;
	}
	return (false);
}
