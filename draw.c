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

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->screen->data + (y * cub->screen->size_line + x * (cub->screen->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_fov(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line + x * (cub->game.mmbase->bpp / 8));
	if (*(unsigned int*)dst != 0x000000FF)
		*(unsigned int*)dst = color;
}

void	clear_fov(t_cub *cub)
{
	char	*dst;
	int 	x;
	int 	y;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line + x * (cub->game.mmbase->bpp / 8));
			if (*(unsigned int*)dst == 0x0000FF00)
				*(unsigned int*)dst = 0x00FFFFFF;
			x++;
		}
		y++;
	}
}
void	T_fov(t_cub *cub)
{
	char	*dst;
	int 	x;
	int 	y;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line + x * (cub->game.mmbase->bpp / 8));
			if (*(unsigned int*)dst != 0x0000FF00)
				*(unsigned int*)dst = 0xFF000000;
			x++;
		}
		y++;
	}
}

void	draw_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line + x * (cub->game.mmbase->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_fov(t_cub *cub)
{
	char	*dst;
	int 	x;
	int 	y;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			dst = cub->game.fov->data + (y * cub->game.fov->size_line + x * (cub->game.fov->bpp / 8));
			*(unsigned int*)dst = 0xFF000000;
			x++;
		}
		y++;
	}
}

void	draw_square(t_cub *cub, int x, int y, int color)
{
	int		temp;
	int		new_x;
	int		new_y;

	temp = x;
	new_x = x + 16;
	new_y = y + 16;
	while (y < new_y && y < cub->height)
	{
		x = temp;
		while (x < new_x && x < cub->width)
		{
			draw_pixel(cub, x, y, color);
			x++;
		}
		y++;
	}
}

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
		if (y + i < cub->height && x < cub->width && y + i >= 0 && x >= 0)
			my_mlx_pixel_put(cub, x, y + i, color);
		i++;
	}
	return (1);
}
