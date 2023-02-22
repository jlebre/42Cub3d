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
	if (keycode == 13 || keycode == 119)
		press_w(game);
	else if (keycode == 0 || keycode == 97
		|| keycode == 123 || keycode == 65361)
		press_a(game);
	else if (keycode == 1 || keycode == 100
		|| keycode == 125 || keycode == 65363)
		press_d(game);
	else if (keycode == 2 || keycode == 115)
		press_s(game);
	/*
	else if (keycode == 53 || keycode == 65307)
		ft_exit(game);
	*/
	return (0);
}

void	press_w(t_game *game)
{
	game->px += game->dir_x;
	game->py += game->dir_y;
}

void	press_a(t_game *game)
{
	game->player_angle -= 0.1;
	if (game->player_angle < 0)
		game->player_angle = TWO_PI;
	game->dir_x = cos(game->player_angle) * 5;
	game->dir_y = sin(game->player_angle) * 5;
}

void	press_d(t_game *game)
{
	game->player_angle += 0.1;
	if (game->player_angle > TWO_PI)
		game->player_angle = 0;
	game->dir_x = cos(game->player_angle) * 5;
	game->dir_y = sin(game->player_angle) * 5;
}

void	press_s(t_game *game)
{
	game->px -= game->dir_x;
	game->py -= game->dir_y;
}

