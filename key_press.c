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

int	key_press(int keycode, t_game *game)
{
	float	playerCos;
	float	playerSin;

	playerCos = cos(degrees_to_radians(game->player_angle));
	playerSin = sin(degrees_to_radians(game->player_angle));
	if (keycode == 13 || keycode == 119)
		press_w(playerCos, playerSin, game);
	else if (keycode == 0 || keycode == 97
		|| keycode == 123 || keycode == 65361)
		press_a(game);
	else if (keycode == 1 || keycode == 100
		|| keycode == 125 || keycode == 65363)
		press_d(game);
	else if (keycode == 2 || keycode == 115)
		press_s(playerCos, playerSin, game);
	else if (keycode == 53 || keycode == 65307)
		ft_exit(game);
	render(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	press_w(float pCos, float pSin, t_game *game)
{
	float new_x;
	float new_y;

	new_x = game->px + pCos * game->player_speed;
	new_y = game->py + pSin * game->player_speed;
	if (game->map[(int)new_y / 16][(int)new_x / 16] == 0)
	{
		game->px = new_x;
		game->py = new_y;
	}
}

void	press_a(t_game *game)
{
	game->player_angle = fix_angle(game->player_angle - 5);
}

void	press_d(t_game *game)
{
	game->player_angle = fix_angle(game->player_angle + 5);
}

void	press_s(float pCos, float pSin, t_game *game)
{
	float new_x;
	float new_y;

	new_x = game->px - pCos * game->player_speed;
	new_y = game->py - pSin * game->player_speed;
	if (game->map[(int)new_y / 16][(int)new_x / 16] == 0)
	{
		game->px = new_x;
		game->py = new_y;
	}
}

