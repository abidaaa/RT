/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abida <abida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:25:02 by abida             #+#    #+#             */
/*   Updated: 2019/08/02 16:48:37 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

typedef struct	s_light
{
	t_vector	position;
	t_vector	intersect_to_light;
	t_color		color;
	double		intensity;
	double		light_dot_normal;
}				t_light;

typedef	struct	s_light_list
{
	t_light				light;
	struct s_light_list	*next;
}				t_light_list;

#endif
