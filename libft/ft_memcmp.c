/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:48:06 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/08 10:55:46 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			break ;
		i++;
	}
	if (i == len)
		return (0);
	else
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
