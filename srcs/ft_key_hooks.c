/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:06:17 by aabouibr          #+#    #+#             */
/*   Updated: 2019/09/17 18:11:47 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ft_keyhooks(int key, t_env *e)
{
	if (key == 53)
	{
		mlx_clear_window(e->p.mlx_con, e->p.window);
		mlx_destroy_image(e->p.mlx_con, e->p.img_ptr);
		mlx_destroy_window(e->p.mlx_con, e->p.window);
		exit(0);
	}
	return (0);
}
