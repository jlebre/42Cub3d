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
	render(game);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	press_w(t_game *game)
{
	game->px += game->delta_x * 5;
	game->py += game->delta_y * 5;
}

void	press_a(t_game *game)
{
	game->player_angle += 5;
	game->player_angle = fix_angle(game->player_angle);
	game->delta_x = cos(degrees_to_radians(game->player_angle));
	game->delta_y = -sin(degrees_to_radians(game->player_angle));
}

void	press_d(t_game *game)
{
	game->player_angle -= 5;
	game->player_angle = fix_angle(game->player_angle);
	game->delta_x = cos(degrees_to_radians(game->player_angle));
	game->delta_y = -sin(degrees_to_radians(game->player_angle));
}

void	press_s(t_game *game)
{
	game->px -= game->delta_x * 5;
	game->py -= game->delta_y * 5;
}

