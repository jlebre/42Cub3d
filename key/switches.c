/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:34:03 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 16:34:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_map(t_cub *cub)
{
	if (cub->game.map_on == 0)
		cub->game.map_on = 1;
	else if (cub->game.map_on == 1)
		cub->game.map_on = 0;
}

int	button(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	(void)button;
	(void)cub;
	if (button == 1 && cub->game.pause == 1 && x >= 275
		&& x <= 365 && y >= 260 && y <= 290)
		ft_exit(cub);
	return (0);
}

void	pause_menu(t_cub *cub)
{
	if (cub->game.pause == 0)
	{
		cub->game.pause = 1;
		mlx_put_image_to_window(cub->mlx, cub->mlx_win,
			cub->game.mpause, 170, 140);
		mlx_mouse_hook(cub->mlx_win, &button, cub);
	}
	else if (cub->game.pause == 1)
		cub->game.pause = 0;
}
