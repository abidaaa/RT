/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:48:35 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/06 20:12:48 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libgl.h"

void	*ft_ray_trace(void *param)
{
	t_data *data;

	data = (t_data *)param;
	ft_camera(data, data->cam.pos, data->cam.to);
	ft_draw_scene(data);
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid number of config file\n"
		"usage : \n./RTv1 config file", 2);
		return (1);
	}
	if (!ft_window_setup(&data, "RTX", HEIGHT, WIDTH)
			|| !ft_image_setup(&data))
		return (1);
	data.filter = 0;
	data.light_list = NULL;
	data.scene = NULL;
	data.cam.focal_length = 2;
	data.cam.f_dist = 15;
	data.cam.refl_depth = 16;
	ft_get_config(argv[1], &data);
	srand(time(NULL));
	random_jitter(&data, (size_t)JNUM);
	ft_multi_thread(&data, &ft_ray_trace);
	mlx_put_image_to_window(data.mlx, data.win, data.img_ptr, 0, 0);
	ft_mlx_hooks(&data, RED_BUTTON_HOOK | KEY_PRESS_HOOK | MOUSE_PRESS_HOOK);
	mlx_loop(data.mlx);
	return (0);
}

/*
**	macro up : 1;
**	macro down  : 2;
**	macro left : 4;
**	macro right  : 8;
**	(left | up | left | right)
**
** Vec P(x,y,z,w) , Vec C(5,5,5,1)
**
** |P - C|² = r²
** 	P - C² 	= r²
**
** magnitude A =  ||A|| = P-C
** magnitude B =  ||B|| = V = 1
**
** B is normalazed
**
** angle  entre (vec4 A et vec4 B)  ==    dotprod(A , B)
**
** dot(A, B )  =   cos (A , B) * ||A||  * ||1||
** cos (A , B) =   dot(A, B )  / ||A||  * ||1||
*/
