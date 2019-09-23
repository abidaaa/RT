/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myglib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:03:42 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 17:04:16 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYGLIB_H
# define MYGLIB_H
# define WIDTH 1024
# define HEIGHT	768
# include "../libft/libft.h"
# include <math.h>

typedef struct	s_params
{
	void		*window;
	void		*mlx_con;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			nothing;
}				t_params;

typedef struct	s_point
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			color;
}				t_point;

void			ft_mlx_line(t_point point, t_params *p);
void			init(t_params *p, char *window_title);
void			draw_wu_line(int x0, int y0, int x1, int y1, t_params *p);
int				rgb_to_int(int r, int g, int b);
int				**colortab(int **tab);
#endif
