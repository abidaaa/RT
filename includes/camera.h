/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:47:21 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 16:48:07 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vectors.h"
# include "rays.h"

typedef struct	s_camera
{
	t_vector	eye_point;
	t_vector	look_at_point;
	t_vector	up;
	t_vector	u;
	t_vector	v;
	t_vector	x_vec;
	t_vector	y_vec;
	t_vector	bottom_left;
	double		fov;
	double		aspect_ratio;
}				t_camera;

#endif
