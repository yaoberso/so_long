/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:29 by yann              #+#    #+#             */
/*   Updated: 2024/11/19 13:25:43 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "get_next_line.h"
# include "map.h"
# include "minilibx/mlx.h"
# include "utils.h"
# include <stdlib.h>

typedef struct s_player
{
	int		x;
	int		y;
	void	*image;
	void	*mlx;
	void	*window;
	char	**map;
	t_tiles	*tiles;
}			t_player;

t_player	*init_player(int start_x, int start_y, char **map, void *window);
void		move_player(int keycode, t_player *player, char **map);
void		draw_player(void *mlx, void *window, t_player *player);

#endif
