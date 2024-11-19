/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:36 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/19 11:39:21 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect.h"

void	draw_collect(void *mlx, void *window, char **map)
{
	int		x;
	int		y;
	int		width;
	int		height;
	void	*collect_image;

	collect_image = mlx_png_file_to_image(mlx, "./tiles/collect.png", &width,
			&height);
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'A')
			{
				mlx_put_image_to_window(mlx, window, collect_image, x
					* TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
