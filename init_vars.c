/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:20:17 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 20:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**dup_map(int map[8][8])
{
	int	**new_map;
	int	i;
	int	j;

	i = 0;
	new_map = (int **)malloc(sizeof(int *) * 8);
	while (i < 8)
	{
		j = 0;
		new_map[i] = (int *)malloc(sizeof(int) * 8);
		while (j < 8)
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}

void	init_vars(t_game *game)
{
	int	map[8][8] =
	{
		{1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,1},
		{1,0,1,0,0,1,1,1},
		{1,0,0,0,0,1,0,1},
		{1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1},
	};
	game->width = 1024;
	game->height = 768;
	game->map_width = 8;
	game->map_height = 8;
	game->map_x = 128;
	game->map_y = 128;
	game->px = 128;
	game->py = 128;
	game->player_angle = 90;
	//game->delta_x = cos(degrees_to_radians(game->player_angle)) * 5;
	//game->delta_y = sin(degrees_to_radians(game->player_angle)) * 5;
	//game->ray_x = game->delta_x;
	//game->ray_y = game->delta_y;
	game->map = dup_map(map);
	//game->ray = 0;
}
