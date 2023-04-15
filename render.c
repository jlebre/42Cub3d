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
	if (cub->game.lights == 1)
	{
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 20, 0x00000000, "P - Pause");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 32, 0x00000000, "M - Mini Map");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 44, 0x00000000, "F - FOV");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 56, 0x00000000, "ESC - Quit");
	}
	else
	{
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 20, 0xFFFFFFFF, "P - Pause");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 32, 0xFFFFFFFF, "M - Mini Map");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 44, 0xFFFFFFFF, "F - FOV");
		mlx_string_put(cub->mlx, cub->mlx_win, 550, 56, 0xFFFFFFFF, "ESC - Quit");
	}
}

int	render(t_cub *cub)
{
	clear_screen(cub);
    raycast(cub);
	mini_map(cub);
	write_options(cub);
	usleep(cub->game.delay);
	return (0);
}
