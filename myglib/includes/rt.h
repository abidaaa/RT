/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <arezouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:43:47 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/16 22:13:14 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../myglib/myglib.h"
# include "vectors.h"
# include "shapes.h"
# include "rays.h"
# include "camera.h"
# include "lights.h"
# include <stdio.h>

typedef struct	s_env
{
	t_params		p;
	t_scene			*scene_head;
	t_scene			*object;
	t_light_list	*light_list;
	t_camera		camera;
	t_ray			ray;
	t_color			diffuse;
	t_color			specular;
	t_color			ambient;
	t_color			phong;
	int				x;
	int				y;
	double			distance;
	double			pixelwitdh;
	double			pixelheight;
	double			half_width;
	double			half_height;
	double			a;
	double			b;
	double			c;
	double			d0;
	double			d1;
	double			disc;
	double			ancos;
	double			ansin;
	int				status;
}				t_env;

t_vector		ft_rot_x(t_vector v, double angle);
t_vector		ft_rot_y(t_vector v, double angle);
t_vector		ft_rot_z(t_vector v, double angle);
t_vector		ft_rot(t_vector v, double x, double y, double z);
double			ft_radians(double degrees);
t_bool			ft_sphere_intersection(t_sphere *sphere, t_env *e);
t_bool			ft_plane_intersection(t_plane *plane, t_env *e);
t_bool			ft_cone_intersection(t_cone *cone, t_env *e);
t_bool			ft_cylindre_intersection(t_cylindre *cylindre, t_env *e);
t_bool			check_min_distance(t_env *e);
void			ft_perspective(t_env *e);
void			ft_make_ray(t_env *e, int x, int y);
void			ft_get_normal(t_env *e, t_scene *head);
t_sphere		*ft_new_sphere(char **str, int *i);
t_cylindre		*ft_new_cylindre(char **str, int *i);
t_cone			*ft_new_cone(char **str, int *i);
t_plane			*ft_new_plane(char **str, int *i);
void			free_array(char **a);
char			*read_file(char *str, int fd);
int				ft_linelen(char *str, int i);
double			ft_atof(const char *str);
t_camera		ft_new_camera(char **str, int *i);
t_light			ft_new_light(char **str, int *i);
void			ft_diffuse(t_env *e, t_scene *scene, t_light_list *list);
void			ft_specular(t_env *e, t_scene *scene, t_light_list *list,
		t_vector dir);
void			ft_ambient(t_env *e, t_scene *scene, t_light_list *list);
void			ft_light(t_env *e, t_scene *head, t_light_list *li,
		t_scene *head_list);
int				ft_ray_cast(t_env *e, t_scene *head);
t_bool			ft_shadow_cast(t_env *e, t_scene *head);
t_scene			*ft_parse_scene(char *str, t_env *e, t_scene *head);
int				ft_keyhooks(int key, t_env *p);
t_bool			ft_validate_config_file(char *str);
void			ft_raytrace(t_params *p, t_env *e, t_scene *head);
void			ft_sphere_rot(t_env *e, t_scene *scene, int *ret);
void			ft_cone_rot(t_env *e, t_scene *scene, int *ret);
void			ft_plane_rot(t_env *e, t_scene *scene, int *ret);
void			ft_cylindre_rot(t_env *e, t_scene *scene, int *ret);
int				ft_shadow_sphere(t_env *e, t_scene *scene);
int				ft_shadow_plane(t_env *e, t_scene *scene);
int				ft_shadow_cone(t_env *e, t_scene *scene);
int				ft_shadow_cylindre(t_env *e, t_scene *scene);
void			sphere_normal(t_scene *scene);
void			plane_normal(t_scene *scene);
void			cone_normal(t_scene *scene, t_env *e);
void			cylindre_normal(t_scene *scene, t_env *e);
t_env			*init_cam(t_env *e);
t_env			*init_phong_color(t_env *e);
t_env			*final_color(t_env *e);

#endif
