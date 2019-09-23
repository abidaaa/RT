/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:20:30 by abida             #+#    #+#             */
/*   Updated: 2019/09/17 20:49:02 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_env			*init_cam(t_env *e)
{
	e->camera.fov = (25 * M_PI) / 180;
	e->camera.up = ft_make_vector(0, 1, 0);
	e->distance = RAY_DIS_MAX;
	return (e);
}

t_env			*init_phong_color(t_env *e)
{
	e->phong = (t_color){0, 0, 0};
	e->diffuse = (t_color){0, 0, 0};
	e->specular = (t_color){0, 0, 0};
	e->ambient = (t_color){0, 0, 0};
	return (e);
}

t_env			*final_color(t_env *e)
{
	e->phong.red += (e->diffuse.red + e->specular.red +
			e->ambient.red);
	e->phong.green += (e->diffuse.green + e->specular.green +
			e->ambient.green);
	e->phong.blue += (e->diffuse.blue + e->specular.blue +
			e->ambient.blue);
	return (e);
}
