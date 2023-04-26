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
	int		i;
	int		j;

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

int	start_angle(char c)
{
	if (c == 'N')
		return (270);
	if (c == 'S')
		return (90);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (180);
	return (0);
}

void	init_vars(t_cub *cub)
{
	cub->width = 640;
	cub->height = 480;
	cub->game.player_angle = start_angle(cub->direction);
	cub->game.player_speed = 4;
	cub->game.map_on = 1;
	cub->game.pause = 0;
	cub->game.lifes = 3;
}