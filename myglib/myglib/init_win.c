/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:35:01 by aabouibr          #+#    #+#             */
/*   Updated: 2019/08/02 17:02:48 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib.h"

void	init(t_params *p, char *window_title)
{
	p->mlx_con = mlx_init();
	p->window = mlx_new_window(p->mlx_con, WIDTH, HEIGHT, window_title);
	p->img_ptr = mlx_new_image(p->mlx_con, WIDTH, HEIGHT);
	p->img_data = (int *)mlx_get_data_addr(p->img_ptr, &(p->bpp),
			&(p->size_line), &(p->endian));
}
