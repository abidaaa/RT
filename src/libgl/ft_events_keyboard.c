/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_keyboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:27:08 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/06 17:38:23 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

int		mouse_move(int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	return (0);
}

int		no_event_mouse_move(t_data *data)
{
	ft_refresh_image(data);
	ft_multi_thread(data, &ft_ray_trace);
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	return (0);
}

int		key_press(int key_code, t_data *data)
{
	pthread_t	thread_id;

	if (key_code == 53)
	{
		mlx_destroy_image(data->mlx, data->img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		ft_lstdel(&data->scene, &ft_del);
		ft_lstdel(&data->light_list, &ft_del);
		exit(0);
	}
	if (key_code == 1)
		pthread_create(&thread_id, NULL, &ft_screenshot, (void *)data);
	ft_refresh_image(data);
	data->cam.pos.x += (key_code == LEFT_ARROW) ? 1 : 0;
	data->cam.pos.x -= (key_code == RIGHT_ARROW) ? 1 : 0;
	data->cam.pos.z -= (key_code == UP_ARROW) ? 1 : 0;
	data->cam.pos.z += (key_code == DOWN_ARROW) ? 1 : 0;
	data->cam.refl_depth -= (key_code == 27 &&
	data->cam.refl_depth > 0) ? 1 : 0;
	data->cam.refl_depth += (key_code == 24) ? 1 : 0;
	data->cam.f_dist -= (key_code == 78) ? 1 : 0;
	data->cam.f_dist += (key_code == 69) ? 1 : 0;
	ft_multi_thread(data, &ft_ray_trace);
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_data *data)
{
	ft_refresh_image(data);
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		data->cam.pos.y -= 5;
	if (button == RIGHT_CLICK)
		data->cam.pos.y += 5;
	ft_multi_thread(data, &ft_ray_trace);
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	return (0);
}
