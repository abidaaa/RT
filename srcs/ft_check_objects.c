/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:05:40 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 15:06:55 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_bool	ft_check_cam(char **scene, int **i)
{
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	return (true);
}

t_bool	ft_check_light(char **scene, int **i)
{
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_one(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	return (true);
}

t_bool	ft_check_sphere(char **scene, int **i)
{
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_one(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	return (true);
}

t_bool	ft_check_plane(char **scene, int **i)
{
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	return (true);
}

t_bool	ft_check_cylindre_cone(char **scene, int **i)
{
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_one(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	if (ft_check_three(scene, &i) == false)
		return (false);
	return (true);
}
