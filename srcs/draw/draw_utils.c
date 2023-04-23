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

void	draw_with_tranparency(t_cub *cub, int x, int y, t_img *texture)
{
	int	i;
	int	j;
	int	color;
	int	pink;

	i = 0;
	pink = my_mlx_pixel_get(texture, 0, 0);
	while (i < texture->height)
	{
		j = 0;
		while (j < texture->width)
		{
			color = my_mlx_pixel_get(texture, j, i);
			if (color != pink)
				my_mlx_pixel_put(cub, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_fov(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line
			+ x * (cub->game.mmbase->bpp / 8));
	if (*(unsigned int *)dst != 0x000000FF)
		*(unsigned int *)dst = color;
}

void	clear_fov(t_cub *cub)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (y < cub->map.height16)
	{
		x = 0;
		while (x < cub->map.width16)
		{
			dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line
					+ x * (cub->game.mmbase->bpp / 8));
			if (*(unsigned int *)dst == 0x0000FF00)
				*(unsigned int *)dst = 0x00FFFFFF;
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

void	clear_screen(t_cub *cub)
{
	int		x;
	int		y;

	y = 0;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
		{
			my_mlx_pixel_put(cub, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
