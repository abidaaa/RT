/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:39:35 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/11 12:41:49 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (tmp == NULL)
		return (NULL);
	while (s1[i] != '\0')
		tmp[c++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		tmp[c++] = s2[i++];
	tmp[c] = '\0';
	return (tmp);
}
