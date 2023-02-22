/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:12:57 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/31 19:46:24 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	orientation_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	valid_chars(char c)
{
	return (string().ft_isspace(c) || orientation_player(c) || \
	c == '0' || c == '1');
}

static int	check_invalid_char(t_cub *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (!valid_chars(data->map.map[y][x]))
				return (1);
			if (orientation_player(data->map.map[y][x]))
			{
				data->map.player_orientation = data->map.map[y][x];
				data->map.player_x = x;
				data->map.player_y = y;
				data->map.num_player++;
			}
		}
	}
	return (data->map.num_player != 1);
}

int	check_map(t_cub *data, char **path)
{
	if (check_invalid_char(data))
	{
		alloc().free_matrix((void **)path);
		exit_free(data, 1, "The map must valid chars and one player position");
	}
	return (0);
}
