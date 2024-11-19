/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:12 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/19 14:02:51 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect.h"
#include "get_next_line.h"
#include "map.h"
#include "player.h"
#include "utils.h"

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_tiles		*tiles;
	t_player	*player;
	char		**map;
}				t_game;

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
	window = mlx_new_window(mlx, (largeur), (hauteur), "Test Window");
	return (window);
}

int	handle_keypress(int keycode, t_player *player)
{
	static int	count = 0;

	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		count++;
		printf("compteur de deplacement: %d\n", count);
	}
	move_player(keycode, player, player->map);
	mlx_clear_window(player->mlx, player->window);
	place_tiles(player->mlx, player->window, player->tiles, player->map);
	draw_collect(player->mlx, player->window, player->map);
	draw_player(player->mlx, player->window, player);
	return (0);
}

int	initialize_game(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		return (1);
	}
	game->mlx = mlx_init();
	game->map = load_map(argv[1]);
	game->window = create_window(game->mlx, game->map);
	game->tiles = load_tiles(game->mlx);
	game->player = init_player(cherche_px(game->map), cherche_py(game->map),
			game->map, game->window);
	if (!game->player)
	{
		free_map(game->map);
		free_tiles(game->mlx, game->tiles);
		return (1);
	}
	game->player->tiles = game->tiles;
	game->player->map = game->map;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (initialize_game(argc, argv, &game))
	{
		return (1);
	}
	mlx_key_hook(game.window, handle_keypress, game.player);
	place_tiles(game.mlx, game.window, game.tiles, game.map);
	draw_collect(game.mlx, game.window, game.map);
	draw_player(game.mlx, game.window, game.player);
	mlx_loop(game.mlx);
	free_map(game.map);
	free_tiles(game.mlx, game.tiles);
	free(game.player);
	mlx_destroy_window(game.mlx, game.window);
	return (0);
}
