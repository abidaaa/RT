/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:00:57 by arezouk           #+#    #+#             */
/*   Updated: 2019/09/17 20:49:28 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		free_objects(t_scene *objects)
{
	t_scene *tmp;

	while (objects)
	{
		tmp = objects;
		free(objects->object);
		objects = objects->next;
		free(tmp);
	}
}

static void		free_lights(t_light_list *light_list)
{
	t_light_list *tmp;

	while (light_list)
	{
		tmp = light_list;
		light_list = light_list->next;
		free(tmp);
	}
}

void			ft_raytrace(t_params *p, t_env *e, t_scene *head)
{
	int			x;
	int			y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			e->x = x;
			e->y = y;
			ft_make_ray(e, x, y);
			if (ft_ray_cast(e, head))
			{
				ft_light(e, e->object, e->light_list, head);
				p->img_data[(y * WIDTH) + x] =
					rgb_to_int(fmin(e->phong.red * 255, 255),
							fmin(e->phong.green * 255, 255),
								fmin(e->phong.blue * 255, 255));
			}
		}
	}
	free_objects(e->scene_head);
	free_lights(e->light_list);
	mlx_put_image_to_window(p->mlx_con, p->window, p->img_ptr, 0, 0);
}

static void		ft_print_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				main(int argc, char **argv)
{
	t_env		e;
	t_scene		*scene_head;
	char		*str;
	int			fd;

	if (argc == 2)
	{
		str = NULL;
		scene_head = NULL;
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		str = read_file(str, fd);
		if (!ft_validate_config_file(str))
			ft_print_exit("Wrong format in config file");
		e.scene_head = ft_parse_scene(str, &e, scene_head);
		init_cam(&e);
		init(&e.p, "Rtv1 : Ayoub & Abida");
		ft_perspective(&e);
		ft_raytrace(&e.p, &e, e.scene_head);
		mlx_hook(e.p.window, 2, 1, ft_keyhooks, &e);
		mlx_loop(e.p.mlx_con);
	}
	return (0);
}
