/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:00:34 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 20:00:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	float	playerCos;
	float	playerSin;

	playerCos = cos(degrees_to_radians(cub->game.player_angle));
	playerSin = sin(degrees_to_radians(cub->game.player_angle));
	if ((keycode == 13 || keycode == 119) && !cub->game.pause)
		press_ws(playerCos, playerSin, cub, 1);
	else if ((keycode == 0 || keycode == 97
		|| keycode == 123) && !cub->game.pause)
		press_ad(cub, 1);
	else if ((keycode == 1 || keycode == 100
		|| keycode == 125) && !cub->game.pause)
		press_ad(cub, 2);
	else if ((keycode == 2 || keycode == 115) && !cub->game.pause)
		press_ws(playerCos, playerSin, cub, 2);
	else if ((keycode == 65361 || keycode == 65363) && !cub->game.pause)
		rotate(cub, keycode);
	else if ((keycode == 53 || keycode == 65307) && !cub->game.pause)
		ft_exit(cub);
	else if (keycode == 109 && !cub->game.pause)
		switch_map(cub);
	else if (keycode == 112)
		pause_menu(cub);
	if (!cub->game.pause)
		render(cub);
	return (0);
}

int	key_release(int keycode, t_cub *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
