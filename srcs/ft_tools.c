/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:20:30 by abida             #+#    #+#             */
/*   Updated: 2019/09/17 16:26:14 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		free_array(char **a)
{
	int		i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

char		*read_file(char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	if (read(fd, buff, 0) < 0)
		exit(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int			ft_linelen(char *str, int i)
{
	int		k;

	k = 0;
	while (str[i] != '\n')
	{
		i++;
		k++;
	}
	return (k);
}

double		signez(const char *c, int i)
{
	double	signe;

	i = 0;
	if (c[i] == '-')
	{
		signe = -1;
		i++;
	}
	else
		signe = 1;
	return (signe);
}

double		ft_atof(const char *c)
{
	double	result;
	double	signe;
	double	decimal;
	int		point;
	int		i;

	i = -1;
	result = 0;
	point = 0;
	signe = signez(c, i);
	while (c[++i])
	{
		if (c[i] == '.')
		{
			point = 1;
			i++;
		}
		decimal = c[i] - '0';
		if (decimal >= 0 && decimal <= 9)
		{
			point == 1 ? signe /= 10.0f : 0;
			result = result * 10.0f + decimal;
		}
	}
	return (result * signe);
}
