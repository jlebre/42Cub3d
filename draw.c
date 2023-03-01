/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:09:59 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 23:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_vertical_line(int x, int y, int len, t_cub *cub, int color)
{
	int i;
	int limit;

	i = 0;
	if (x < 0 || x >= cub->width)
		return (1);
	limit = cub->height;
	while (i < len && (y + i) < limit)
	{
		mlx_pixel_put(cub->mlx, cub->mlx_win, x, y + i, color);
		i++;
	}
	return (1);
}
