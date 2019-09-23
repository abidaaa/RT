/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_config_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:46:37 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 20:49:16 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		ft_objcmp(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_strcmp(str, "sphere") == 0)
		return (1);
	if (ft_strcmp(str, "plane") == 0)
		return (1);
	if (ft_strcmp(str, "cylindre") == 0)
		return (1);
	if (ft_strcmp(str, "cone") == 0)
		return (1);
	if (ft_strcmp(str, "light") == 0)
		return (1);
	return (0);
}

t_bool			ft_validate_config_file(char *str)
{
	char	**scene;
	int		i;
	int		flag[2];

	i = 0;
	flag[0] = 0;
	flag[1] = 0;
	scene = ft_strsplit(str, '\n');
	while (scene[i])
	{
		if (ft_check_cam_light(scene, &i, &flag[0], &flag[1]) == false)
			return (false);
		else if (ft_check_objects(scene, &i) == false)
			return (false);
		i++;
		if (i > 6 && ft_objcmp(scene[i]) == 0)
		{
			free_array(scene);
			return (0);
		}
	}
	free_array(scene);
	if (flag[0] == 0 || flag[1] == 0 || i == 7)
		return (0);
	return (true);
}

static void		ft_init_lists(t_env **e, t_scene **head,
t_light_list **light_list, t_scene **objects)
{
	(*e)->light_list = (t_light_list *)malloc(sizeof(t_light_list));
	(*light_list) = (*e)->light_list;
	(*head) = (t_scene *)malloc(sizeof(t_scene));
	*objects = *head;
}

static void		ft_free_lists(t_light_list **temp_light, t_scene **tmp,
char **str, char ***scene)
{
	(*temp_light)->next = NULL;
	(*tmp)->next = NULL;
	free(*str);
	free_array(*scene);
}

t_scene			*ft_parse_scene(char *str, t_env *e, t_scene *head)
{
	char				**scene;
	t_scene				*objects[2];
	t_light_list		*light_list[2];
	int					i;

	i = -1;
	ft_init_lists(&e, &head, &light_list[0], &objects[0]);
	scene = ft_strsplit(str, '\n');
	while (scene[++i])
	{
		if (ft_strcmp(scene[i], "camera") == 0)
			e->camera = ft_new_camera(scene, &i);
		if (ft_strcmp(scene[i], "light") == 0)
			ft_add_light(&light_list[0], scene, &i, &light_list[1]);
		if (ft_strcmp(scene[i], "sphere") == 0)
			ft_add_sphere(&objects[0], scene, &i, &objects[1]);
		if (ft_strcmp(scene[i], "plane") == 0)
			ft_add_plane(&objects[0], scene, &i, &objects[1]);
		if (ft_strcmp(scene[i], "cone") == 0)
			ft_add_cone(&objects[0], scene, &i, &objects[1]);
		if (ft_strcmp(scene[i], "cylindre") == 0)
			ft_add_cylindre(&objects[0], scene, &i, &objects[1]);
	}
	ft_free_lists(&light_list[1], &objects[1], &str, &scene);
	return (head);
}
