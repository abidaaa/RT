/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:05:19 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 12:27:29 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	int		*str;

	i = 0;
	str = (int *)malloc(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
