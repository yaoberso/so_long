/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:18:39 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/18 13:39:10 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int ft_strcol(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char *ft_strdup(char *str)
{
	char *dup;
	int i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strcol(str) + 1));
	if (!dup)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int cherche_px(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int cherche_py(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int cherche_collect(char **map)
{
	int y;
	int x;
	int collect;

	y = 0;
	collect = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'A')
				collect++;
			x++;
		}
		y++;
	}
	return (collect);
}