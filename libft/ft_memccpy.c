/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:49:53 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 15:46:36 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dt;
	unsigned char	*sc;

	dt = (unsigned char *)dst;
	sc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dt[i] = sc[i];
		if (sc[i] == (unsigned char)c)
			return ((void *)&dt[i + 1]);
		i++;
	}
	return (NULL);
}
