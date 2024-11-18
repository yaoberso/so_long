/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:06 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/18 14:47:08 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "minilibx/mlx.h"
# include "get_next_line.h"
# include "utils.h"

# define TILE_SIZE 64
# define MAX_LINES 100
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640

typedef struct s_tiles {
	void	*cAG;
	void	*cAD;
	void	*cBD;
	void	*cBG;
	void	*dB;
	void	*dD;
	void	*dG;
	void	*dH;
	void	*plein;
	void	*water;
	void	*cailloux;
	void	*exit;
}	t_tiles;

void	free_map(char **map);
void	free_tiles(void *mlx, t_tiles *tiles);
char	**load_map(const char *filename);
t_tiles	*load_tiles(void *mlx);
void	place_tiles(void *mlx, void *window, t_tiles *tiles, char **map);

#endif
