/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:53:05 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 12:49:21 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "vectors.h"

typedef enum	e_type
{
	sphere1, plane1, cone1, cylindre1
}				t_type;

typedef struct	s_color
{
	double			red;
	double			green;
	double			blue;
}				t_color;

typedef struct	s_scene
{
	t_vector		intersect_point;
	t_vector		normal;
	void			*object;
	t_color			color;
	t_type			type;
	struct s_scene	*next;
}				t_scene;

typedef struct	s_plane
{
	t_vector		position;
	t_vector		rotation;
	t_vector		normal;
	t_vector		translation;
	t_color			color;
}				t_plane;

typedef struct	s_sphere
{
	t_vector		centre;
	t_vector		rotation;
	t_vector		translation;
	t_color			color;
	double			radius;
}				t_sphere;

typedef struct	s_cylindre
{
	t_vector		centre;
	t_vector		rotation;
	t_vector		translation;
	t_vector		normal;
	t_color			color;
	double			radius;
}				t_cylindre;

typedef struct	s_cone
{
	t_vector		position;
	t_vector		rotation;
	t_vector		translation;
	t_vector		normal;
	t_color			color;
	double			angle;
	double			tang;
}				t_cone;

#endif
