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

void	draw_with_tranparency(t_cub *cub, int x, int y, t_img *texture);
void	print_compass(t_cub *cub);

void	write_options(t_cub *cub)
{
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 20, 0x00000000, "P - Pause");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 32, 0x00000000, "M - Mini Map");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 44, 0x00000000, "F - FOV");
	mlx_string_put(cub->mlx, cub->mlx_win, 550, 56, 0x00000000, "ESC - Quit");
}

void	print_hearts(t_cub *cub)
{
	if (cub->game.lifes == 3)
	{
		draw_with_tranparency(cub, 250, 20, cub->img.heart);
		draw_with_tranparency(cub, 318, 20, cub->img.heart);
		draw_with_tranparency(cub, 386, 20, cub->img.heart);
	}
	else if (cub->game.lifes == 2)
	{
		draw_with_tranparency(cub, 250, 20, cub->img.heart);
		draw_with_tranparency(cub, 318, 20, cub->img.heart);
	}
	else if (cub->game.lifes == 1)
		draw_with_tranparency(cub, 250, 20, cub->img.heart);
	else
	{
		mlx_string_put(cub->mlx, cub->mlx_win, 250, 20, 0x00000000, "GAME OVER");
		mlx_string_put(cub->mlx, cub->mlx_win, 250, 32, 0x00000000, "PRESS ESC");
		cub->game.pause = 1;
	}
}

int	render(t_cub *cub)
{
	//clear_screen(cub);
	raycast(cub);
	mini_map(cub);
	print_compass(cub);
	print_hearts(cub);
	draw_with_tranparency(cub, 20, 400, cub->img.settings);
	write_options(cub);
	return (0);
}
