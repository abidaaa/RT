/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:42:17 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 20:06:13 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	while (to_find[length])
		length++;
	if (length == 0)
		return ((char*)str);
	while (i < n && str[i])
	{
		while (to_find[j] == str[i + j] && (i + j) <= n)
		{
			if (j == length - 1)
				return ((char *)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
