/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:27:39 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 19:15:31 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	char	*tmp;
	int		ed;

	if (!s)
		return (NULL);
	st = 0;
	tmp = ft_strnew(ft_strlen(s));
	if (tmp == NULL)
		return (NULL);
	ed = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\t' || s[st] == '\n')
	{
		st++;
	}
	if (st == ed + 1)
		return (ft_strnew(0));
	while (ed >= 0 && (s[ed] == ' ' || s[ed] == '\t' || s[ed] == '\n'))
	{
		ed--;
	}
	tmp = ft_strsub(s, st, (ed - st) + 1);
	return (tmp);
}
