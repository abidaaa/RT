/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:01:29 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 21:09:06 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	long	chnb;
	char	*nb;

	nb = ft_strnew(ft_count(n));
	if (nb == NULL)
		return (NULL);
	chnb = n;
	if (chnb < 0)
		chnb = -chnb;
	i = 0;
	if (chnb == 0)
		nb[i++] = '0';
	while (chnb > 0)
	{
		nb[i] = chnb % 10 + '0';
		chnb /= 10;
		i++;
	}
	if (n < 0)
		nb[i++] = '-';
	nb[i] = '\0';
	ft_strrev(nb);
	return (nb);
}
