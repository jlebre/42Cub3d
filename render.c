/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:17:45 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 01:17:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_options(t_cub *cub)
{
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 20, 0x00000000, "P - Pause");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 32, 0x00000000, "M - Mini Map");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 44, 0x00000000, "F - FOV");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 56, 0x00000000, "ESC - Quit");
}

void	draw_heart(t_cub *cub, int x, int y, t_img_mlx *texture)
{
	int		i;
	int		j;
	int 	color;
	int 	pink;

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

void	print_hearts(t_cub *cub)
{
	if (cub->game.lifes == 3)
	{
		draw_heart(cub, 250, 20, cub->img.heart);
		draw_heart(cub, 318, 20, cub->img.heart);
		draw_heart(cub, 386, 20, cub->img.heart);
	}
	else if (cub->game.lifes == 2)
	{
		draw_heart(cub, 250, 20, cub->img.heart);
		draw_heart(cub, 318, 20, cub->img.heart);
	}
	else if (cub->game.lifes == 1)
		draw_heart(cub, 250, 20, cub->img.heart);
	else
	{
		mlx_string_put(cub->mlx, cub->mlx_win, 250, 20, 0x00000000, "GAME OVER");
		mlx_string_put(cub->mlx, cub->mlx_win, 250, 32, 0x00000000, "PRESS ESC");
		cub->game.pause = 1;
	}
}

int	render(t_cub *cub)
{
	clear_screen(cub);
    raycast(cub);
	mini_map(cub);
	print_compass(cub);
	print_hearts(cub);
	draw_heart(cub, 20, 400, cub->img.settings);
	write_options(cub);
	return (0);
}
