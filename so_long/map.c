/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:54 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/18 14:38:31 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tiles(void *mlx, t_tiles *tiles)
{
	if (tiles == NULL)
		return;
	mlx_destroy_image(mlx, tiles->cAG);
	mlx_destroy_image(mlx, tiles->cBD);
	mlx_destroy_image(mlx, tiles->cBG);
	mlx_destroy_image(mlx, tiles->cAD);
	mlx_destroy_image(mlx, tiles->dB);
	mlx_destroy_image(mlx, tiles->dH);
	mlx_destroy_image(mlx, tiles->dD);
	mlx_destroy_image(mlx, tiles->dG);
	mlx_destroy_image(mlx, tiles->plein);
	mlx_destroy_image(mlx, tiles->water);
	free(tiles);
}

char	**load_map(const char *filename)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;
	int		map_size;

	i = 0;
	map_size = 0;
	line = NULL;
	fd  = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return NULL;
	}
	while (get_next_line(fd) != NULL)
	{
		map_size++;
		free(line);
	}
	close (fd);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	map [i] = NULL;
	close(fd);
	return (map);
}

t_tiles	*load_tiles(void *mlx)
{
    t_tiles	*tiles;
	int		width;
	int		height;

	tiles = malloc(sizeof(t_tiles));
	if (tiles == NULL)
	{
		fprintf(stderr, "Erreur: Allocation mémoire pour les tuiles échouée.\n");
		return (NULL);
	}
	tiles->cAG = mlx_png_file_to_image(mlx, "./tiles/coinAG.png", &width, &height);
	tiles->cBD = mlx_png_file_to_image(mlx, "./tiles/coinBD.png", &width, &height);
	tiles->cBG = mlx_png_file_to_image(mlx, "./tiles/coinBG.png", &width, &height);
	tiles->cAD = mlx_png_file_to_image(mlx, "./tiles/coinAD.png", &width, &height);
	tiles->dB = mlx_png_file_to_image(mlx, "./tiles/droiteB.png", &width, &height);
	tiles->dH = mlx_png_file_to_image(mlx, "./tiles/droiteH.png", &width, &height);
	tiles->dD = mlx_png_file_to_image(mlx, "./tiles/droiteD.png", &width, &height);
	tiles->dG = mlx_png_file_to_image(mlx, "./tiles/droiteG.png", &width, &height);
	tiles->plein = mlx_png_file_to_image(mlx, "./tiles/plein.png", &width, &height);
	tiles->water = mlx_png_file_to_image(mlx, "./tiles/Water.png", &width, &height);
	tiles->cailloux = mlx_png_file_to_image(mlx, "./tiles/cailloux.png", &width, &height);
	tiles->exit = mlx_png_file_to_image(mlx, "./tiles/exit.png", &width, &height);
	return (tiles);
}

void	place_tiles(void *mlx, void *window, t_tiles *tiles, char **map)
{
	void	*tile;
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tile = NULL;
			if (map[y][x] == '1')
				tile = tiles->cAG;
			else if (map[y][x] == '2')
				tile = tiles->cAD;
			else if (map[y][x] == '3')
				tile = tiles->cBG;
			else if (map[y][x] == '4')
				tile = tiles->cBD;
			else if (map[y][x] == 'H')
				tile = tiles->dH;
			else if (map[y][x] == 'G')
				tile = tiles->dG;
			else if (map[y][x] == 'D')
				tile = tiles->dD;
			else if (map[y][x] == 'B')
				tile = tiles->dB;
			else if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'A')
				tile = tiles->plein;
			else if (map[y][x] == 'M')
				tile = tiles->water;
			else if (map[y][x] == 'C')
				tile = tiles->cailloux;
			else if (map[y][x] == 'E')
				tile = tiles->exit;
			if (tile != NULL)
			{
				mlx_put_image_to_window(mlx, window, tile, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
