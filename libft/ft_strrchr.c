/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:38:19 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 19:03:38 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str[i])
	{
		if (str[i] == ch)
			j = i;
		i++;
	}
	if (j != -1)
		return (&((char*)str)[j]);
	if (ch == '\0')
		return ((&((char*)str)[i]));
	return (NULL);
}
