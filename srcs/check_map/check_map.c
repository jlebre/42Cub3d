/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:12:57 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/18 22:48:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

int	orientation_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	valid_chars(char c)
{
	return (string().ft_isspace(c) || orientation_player(c) || \
	c == '0' || c == '1');
}

static void	set_player(t_cub *data, int x, int y)
{
	data->direction = data->map.map[y][x];
	data->map.map[y][x] = '0';
	data->px = x * 16 + 5.5;
	data->py = y * 16 + 5.5;
	data->num_player++;
}

static int	check_invalid_char(t_cub *data)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (!valid_chars(data->map.map[y][x]))
				return (1);
			if (orientation_player(data->map.map[y][x]))
				set_player(data, x, y);
		}
			data->map.width = (x * 16) * (data->map.width / 16 < x) + \
			(data->map.width / 16 >= x) * (data->map.width);
	}
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
	verify_paths(data, path);
	return (0);
}
