/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:26:34 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 18:47:01 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (&((char*)str)[i]);
		i++;
	}
	if (ch == '\0')
		return ((&((char*)str)[i]));
	return (NULL);
}
