/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:26:00 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 19:17:56 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
