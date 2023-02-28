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

char	**dup_map(char map[8][8])
{
	char	**new_map;
	int	i;
	int	j;

	i = 0;
	new_map = malloc(sizeof(char *) * 9);
	while (i < 8)
	{
		j = 0;
		new_map[i] = malloc(sizeof(char) * 9);
		while (j < 8)
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	init_vars(t_game *game)
{
	char	map[8][8] =
	{
		{1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1},
	};
	game->width = 768;
	game->height = 512;
	game->map_width = 8;
	game->map_height = 8;
	game->px = 128;
	game->py = 128;
	game->dir_x = -1;
	game->dir_y = 0;
	game->player_angle = 90;
	game->map = dup_map(map);
	game->player_speed = 5;
}
