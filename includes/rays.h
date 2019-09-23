/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:14:11 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 16:49:11 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "vectors.h"
# include "shapes.h"
# define RAY_DIS_MIN 0.0001
# define RAY_DIS_MAX 1e30

typedef struct	s_ray
{
	t_vector	dir;
	t_vector	start;
	t_vector	view_direction;
}				t_ray;

#endif
