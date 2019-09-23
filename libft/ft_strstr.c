/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:10:11 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 13:58:43 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = 0;
	while (to_find[length])
		length++;
	if (length == 0)
		return ((char *)str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
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
