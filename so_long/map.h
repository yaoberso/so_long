/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:06 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/19 13:46:15 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "get_next_line.h"
# include "minilibx/mlx.h"
# include "utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 64
# define MAX_LINES 100
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640

typedef struct s_tiles
{
	void	*cag;
	void	*cad;
	void	*cbd;
	void	*cbg;
	void	*db;
	void	*dd;
	void	*dg;
	void	*dh;
	void	*plein;
	void	*water;
	void	*cailloux;
	void	*exit;
}			t_tiles;

void		free_map(char **map);
void		free_tiles(void *mlx, t_tiles *tiles);
char		**load_map(const char *filename);
t_tiles		*load_tiles(void *mlx);
void		place_tiles(void *mlx, void *window, t_tiles *tiles, char **map);

#endif
