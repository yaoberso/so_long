/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:26 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/19 13:45:05 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#define TILE_SIZE 64

t_player	*init_player(int start_x, int start_y, char **map, void *window)
{
	int			width;
	int			height;
	t_player	*player;
	void		*mlx;

	mlx = mlx_init();
	player = malloc(sizeof(t_player));
	if (!player)
	{
		return (NULL);
	}
	player->x = start_x;
	player->y = start_y;
	player->mlx = mlx;
	player->window = window;
	player->map = map;
	player->image = mlx_png_file_to_image(mlx, "./tiles/player.png", &width,
			&height);
	if (!player->image)
	{
		free(player);
		return (NULL);
	}
	return (player);
}

void	check_new_coord(int keycode, int *new_x, int *new_y, t_player *player)
{
	if (keycode == 13)
	{
		(*new_y)--;
	}
	else if (keycode == 0)
	{
		(*new_x)--;
	}
	else if (keycode == 1)
	{
		(*new_y)++;
	}
	else if (keycode == 2)
	{
		(*new_x)++;
	}
	else if (keycode == 53)
	{
		free(player);
		mlx_destroy_window(player->mlx, player->window);
		exit(0);
	}
}

void	check_exit_condition(t_player *player, char **map)
{
	if (cherche_collect(map) == 0)
	{
		free(player);
		mlx_destroy_window(player->mlx, player->window);
		exit(0);
	}
}

void	move_player(int keycode, t_player *player, char **map)
{
	int	new_x;
	int	new_y;
	int	i;
	int	jsp;

	new_x = player->x;
	new_y = player->y;
	i = 0;
	jsp = ft_strlen(map[0]);
	check_new_coord(keycode, &new_x, &new_y, player);
	while (map[i] != NULL)
		i++;
	if (new_x >= 0 && new_x < jsp && new_y >= 0 && new_y < i)
	{
		if (map[new_y][new_x] == 'A')
			map[new_y][new_x] = '0';
		if (map[new_y][new_x] != 'M' && map[new_y][new_x] != 'C')
		{
			player->x = new_x;
			player->y = new_y;
		}
		if (map[new_y][new_x] == 'E')
			check_exit_condition(player, map);
	}
}

void	draw_player(void *mlx, void *window, t_player *player)
{
	mlx_put_image_to_window(mlx, window, player->image, player->x * TILE_SIZE,
		player->y * TILE_SIZE);
}
