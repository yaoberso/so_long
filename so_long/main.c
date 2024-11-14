/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:12 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/14 14:51:26 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"

int handle_keypress(int keycode, t_player *player)
{
    printf("Key pressed: %d\n", keycode);
    move_player(keycode, player, player->map);
    mlx_clear_window(player->mlx, player->window);
    place_tiles(player->mlx, player->window, player->tiles, player->map);
    draw_player(player->mlx, player->window, player);
    return (0);
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return (1);
    }
    void *mlx;
    void *window;
    t_tiles *tiles;
    char **map;
    t_player *player;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 640, 640, "Test Window");
    map = load_map(argv[1]);
    tiles = load_tiles(mlx);
    player = init_player(mlx, 5, 5, window, map);
    if (!player)
    {
        free_map(map);
        free_tiles(mlx, tiles);
        return (1);
    }
    player->tiles = tiles;
    player->map = map;
    mlx_key_hook(window, handle_keypress, player);
    place_tiles(mlx, window, tiles, map);
    draw_player(mlx, window, player);
    mlx_loop(mlx);
    free_map(map);
    free_tiles(mlx, tiles);
    free(player);
    mlx_destroy_window(mlx, window);
    return (0);
}