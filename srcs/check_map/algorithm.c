/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:10:20 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/26 20:02:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <algorithm.h>

int	can_move(t_cp *cp, int x, int y)
{
	return (orientation_player(cp->map[y][x]) || cp->map[y][x] == '0');
}

static int	cp_init(t_cub *data, t_cp *cp)
{
	int		i;

	cp->height = -1;
	while (data->map.map[++cp->height])
		;
	cp->map = alloc().calloc(sizeof(char *) * (cp->height + 1));
	if (!cp->map)
		return (1);
	i = -1;
	while (++i < cp->height)
	{
		cp->map[i] = string().strdup(data->map.map[i]);
		if (!cp->map)
			return (1);
	}
	return (0);
}

int	prep_alg(t_cub *data)
{
	t_cp	cp;
	int		x;
	int		y;

	if (cp_init(data, &cp))
	{
		alloc().free_matrix((void **)cp.map);
		return (1);
	}
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
