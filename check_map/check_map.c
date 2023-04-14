/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:12:57 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/12 16:19:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	orientation_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	valid_chars(char c)
{
	return (ft_isspace(c) || orientation_player(c) || \
	c == '0' || c == '1');
}

int	check_invalid_char(t_cub *data)
{
	int	y;
	int	x;
	data->num_player = 0;

	x = 0;
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
				data->direction = data->map.map[y][x];
				data->map.map[y][x] = '0';
				data->px = x * 16 + 5.5;
				data->py = y * 16 + 5.5;
				data->num_player++;
			}
		}
	}
	data->map.width = x * 16;
	data->map.height = y * 16;
	return (data->num_player != 1);
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
