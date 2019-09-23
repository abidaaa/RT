/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:09:27 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 15:52:24 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_bool	ft_check_three(char **scene, int ***i)
{
	char **tab;

	(***i)++;
	tab = ft_strsplit(scene[***i], ' ');
	if (tablength(tab) < 3)
	{
		free_array(scene);
		return (false);
	}
	if (!ft_str_is_numeric(tab[0]) || !ft_str_is_numeric(tab[1]) ||
	!ft_str_is_numeric(tab[2]))
	{
		free_array(scene);
		return (false);
	}
	free_array(tab);
	return (true);
}

t_bool	ft_check_one(char **scene, int ***i)
{
	char **tab;

	(***i)++;
	tab = ft_strsplit(scene[***i], ' ');
	if (tablength(tab) < 1)
	{
		free_array(scene);
		return (false);
	}
	if (!ft_str_is_numeric(tab[0]))
	{
		free_array(scene);
		return (false);
	}
	free_array(tab);
	return (true);
}

t_bool	ft_check_cam_light(char **scene, int *i, int *flag_cam,
int *flag_light)
{
	if (ft_strcmp(scene[*i], "camera") == 0)
	{
		*flag_cam = 1;
		if (ft_check_cam(scene, &i) == false)
			return (false);
	}
	else if (ft_strcmp(scene[*i], "light") == 0)
	{
		*flag_light = 1;
		if (ft_check_light(scene, &i) == false)
			return (false);
	}
	return (true);
}

t_bool	ft_check_objects(char **scene, int *i)
{
	if (ft_strcmp(scene[*i], "sphere") == 0)
	{
		if (ft_check_sphere(scene, &i) == false)
			return (false);
	}
	else if (ft_strcmp(scene[*i], "plane") == 0)
	{
		if (ft_check_plane(scene, &i) == false)
			return (false);
	}
	else if (ft_strcmp(scene[*i], "cylindre") == 0)
	{
		if (ft_check_cylindre_cone(scene, &i) == false)
			return (false);
	}
	else if (ft_strcmp(scene[*i], "cone") == 0)
	{
		if (ft_check_cylindre_cone(scene, &i) == false)
			return (false);
	}
	return (true);
}
