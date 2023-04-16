/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:22:56 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 01:22:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (y < 128 && x < 128 && (y >= 0 && x >= 0))
	{
		dst = cub->game.mini->data + (y * cub->game.mini->size_line + x * (cub->game.mini->bpp / 8));
		*(unsigned int*)dst = color;
	}
}


void	print_map(t_cub *cub)
{
	int x;
	int y;
	int i;
	int j;

	x = cub->px - 64;
	y = cub->py - 64;

	if (x < 0 || cub->map.width - x < 64)
		x = 0;
	if (y < 0 || cub->map.height - y < 64)
		y = 0;
	if (cub->map.width - x < 144)
		x = cub->map.width - 144;
	if (cub->map.height - y < 128)
		y = cub->map.height - 128;
	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			draw_mini(cub, j, i, my_mlx_pixel_get(cub->game.mmbase, x + j, y + i));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mini, 10, 10);	
	//mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mmp, cub->px, cub->py);
}

void	mini_map(t_cub *cub)
{
	if (cub->game.map_on == 1)
	{
		if (cub->game.fov_on == 0)
			clear_fov(cub);
		print_map(cub);
	}
}

void	init_mini_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == '1')
				draw_square(cub, x * 16, y * 16, 0x000000FF);
			else if (cub->map.map[y][x] == '0' || cub->map.map[y][x] == 'N'
				|| cub->map.map[y][x] == 'S' || cub->map.map[y][x] == 'E'
				|| cub->map.map[y][x] == 'W')
				draw_square(cub, x * 16, y * 16, 0x00FFFFFF);
			else if (cub->map.map[y][x] == ' ')
				draw_square(cub, x * 16, y * 16, 0x00000000);
			else if (cub->map.map[y][x + 1] != '\0')
				draw_square(cub, x * 16, y * 16, 0x00000000);
			x++;
		}
		y++;
	}
}
