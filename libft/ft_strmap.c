/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:57:29 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 19:19:31 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	tmp = ft_strnew(ft_strlen(s));
	if (tmp == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp[i] = (*f)(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
