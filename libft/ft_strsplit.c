/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:01:15 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 19:16:32 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char *s, char c)
{
	int		i;
	int		count;
	int		word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (word == 0 && s[i] != c)
		{
			word = 1;
			count++;
		}
		else if (word == 1 && s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static int	ft_letters(char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nbwords;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nbwords = ft_words((char *)s, c);
	tab = (char **)malloc((nbwords + 1) * sizeof(char*));
	i = 0;
	if (!tab)
		return (NULL);
	while (nbwords)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_letters((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_letters((char *)s, c);
		i++;
		nbwords--;
	}
	tab[i] = NULL;
	return (tab);
}
