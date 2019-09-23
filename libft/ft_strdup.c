/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:20:15 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 13:50:49 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dest;

	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
