/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:18:46 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/18 13:39:57 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef utils_H
#define utils_H

#include <stdlib.h>

int ft_strcol(char *str);
char *ft_strdup(char *str);
int cherche_py(char **map);
int cherche_px(char **map);
int cherche_collect(char **map);

#endif