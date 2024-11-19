/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:40 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/19 11:39:55 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECT_H
# define COLLECT_H

# include "get_next_line.h"
# include "map.h"
# include "minilibx/mlx.h"
# include <stdlib.h>

typedef struct s_collect
{
	int		x;
	int		y;
	void	*image;
	void	*mlx;
	void	*window;
	char	**map;
	t_tiles	*tiles;
}			t_collect;

void		draw_collect(void *mlx, void *window, char **map);

#endif
