/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:10:20 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 14:07:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	can_move(t_cp *cp, int x, int y)
{
	return (orientation_player(cp->map[y][x]) || cp->map[y][x] == '0');
}

static t_cp	cp_init(t_cub *data)
{
	int		i;
	t_cp	cp;

	cp.height = -1;
	while (data->map.map[++cp.height])
		;
	cp.map = alloc().calloc(sizeof(char *) * (cp.height + 1));
	i = -1;
	while (++i < cp.height)
	{
		cp.map[i] = ft_strdup(data->map.map[i]);
		if (!cp.map)
			return (cp);
	}
	return (cp);
}

int	prep_alg(t_cub *data)
{
	t_cp	cp;
	int		x;
	int		y;

	cp = cp_init(data);
	if (!cp.map)
		return (1);
	y = -1;
	while (cp.map[++y])
	{
		x = -1;
		while (cp.map[y][++x])
		{
			if (do_algorithm(&cp, x, y))
				return (1);
		}
	}
	alloc().free_matrix((void **)cp.map);
	return (0);
}
