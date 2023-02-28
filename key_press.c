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

void	press_w(t_game *game)
{
	printf("map = %d\n", game->map[(int)game->py / 32][(int)game->px / 32]);
	printf("px = %f, py = %f\n", game->px, game->py);
	printf("dir_x = %f, dir_y = %f\n", game->dir_x, game->dir_y);
	if (game->map[(int)game->py / 32][(int)game->px / 32] == 0)
	{
		game->px += game->dir_x * game->player_speed;
		game->py += game->dir_y * game->player_speed;
	}
}

void	press_a(t_game *game)
{
	printf("angle = %f\n", game->player_angle);
	game->player_angle = fix_angle(game->player_angle + 5);
	game->dir_x = cos(degrees_to_radians(game->player_angle));
	game->dir_y = -sin(degrees_to_radians(game->player_angle));
}

void	press_d(t_game *game)
{
	printf("angle = %f\n", game->player_angle);
	game->player_angle = fix_angle(game->player_angle - 5);
	game->dir_x = cos(degrees_to_radians(game->player_angle));
	game->dir_y = -sin(degrees_to_radians(game->player_angle));
}

void	press_s(t_game *game)
{
	printf("map = %d\n", game->map[(int)game->py / 32][(int)game->px / 32]);
	printf("px = %f, py = %f\n", game->px, game->py);
	printf("dir_x = %f, dir_y = %f\n", game->dir_x, game->dir_y);
	if (game->map[(int)game->py / 32][(int)game->px / 32] == 0)
	{
		game->px -= game->dir_x * game->player_speed;
		game->py -= game->dir_y * game->player_speed;
	}
}

