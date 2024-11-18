/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:12 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/18 14:25:54 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"
#include "collect.h"
#include "get_next_line.h"
#include "utils.h"

void	*create_window(void *mlx, char **map)
{
	int		hauteur;
	int		largeur;
	void	*window;

	hauteur = 0;
	while (map[hauteur] != NULL)
	{
		hauteur++;
	}
	largeur = (ft_strcol(map[0]) - 1);
	hauteur *= TILE_SIZE;
	largeur *= TILE_SIZE;

	window = mlx_new_window(mlx, (largeur ), (hauteur), "Test Window");
	return (window);
}
int	handle_keypress(int keycode, t_player *player)
{
	move_player(keycode, player, player->map);
	mlx_clear_window(player->mlx, player->window);
	place_tiles(player->mlx, player->window, player->tiles, player->map);
	draw_collect(player->mlx, player->window, player->map);
	draw_player(player->mlx, player->window, player);
	return (0);
}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (1);
	}
	void		*mlx;
	void		*window;
	t_tiles		*tiles;
	char		**map;
	t_player	*player;

	mlx = mlx_init();
	map = load_map(argv[1]);
	window = create_window(mlx, map);
	tiles = load_tiles(mlx);
	player = init_player(mlx, cherche_px(map), cherche_py(map), window, map);
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
	draw_collect(mlx, window, map);
	draw_player(mlx, window, player);
	mlx_loop(mlx);
	free_map(map);
	free_tiles(mlx, tiles);
	free(player);
	mlx_destroy_window(mlx, window);
	return (0);
}
