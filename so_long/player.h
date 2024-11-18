/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:29 by yann              #+#    #+#             */
/*   Updated: 2024/11/18 13:39:42 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "minilibx/mlx.h"
#include "get_next_line.h"
#include "map.h"
#include <stdlib.h>
#include "utils.h"

typedef struct s_player {
    int x;
    int y;
    void *image;
    void *mlx;
    void *window;
    char **map;
    t_tiles *tiles;
} t_player;

t_player 	*init_player(void *mlx, int start_x, int start_y, void *window, char **map);
void		move_player(int keycode, t_player *player, char **map);
void		draw_player(void *mlx, void *window, t_player *player);

#endif