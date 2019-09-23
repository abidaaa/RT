/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:21:02 by aabouibr          #+#    #+#             */
/*   Updated: 2018/10/15 19:34:53 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int a;
	int i;
	int n;

	a = 0;
	i = 0;
	n = 1;
	while (str[i] <= ' ' && str[i] != 27 && str[i] != '\200')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			break ;
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (n * a);
}
