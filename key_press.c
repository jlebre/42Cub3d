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

void switch_fov(t_cub *cub)
{
	if (cub->game.fov_on == 0)
		cub->game.fov_on = 1;
	else if (cub->game.fov_on == 1)
		cub->game.fov_on = 0;
}

void light_switch(t_cub *cub)
{
	if (cub->game.lights == 0)
		cub->game.lights = 1;
	else if (cub->game.lights == 1)
		cub->game.lights = 0;
}

void textures_switch(t_cub *cub)
{
	if (cub->game.textures_on == 0)
		cub->game.textures_on = 1;
	else if (cub->game.textures_on == 1)
		cub->game.textures_on = 0;
}

void switch_map(t_cub *cub)
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
	if (button == 1 && cub->game.pause == 1 && x >= 275 && x <= 365 && y >= 260 && y <= 290)
		ft_exit(cub);
	return (0);
}

void pause_menu(t_cub *cub)
{
	if (cub->game.pause == 0)
	{
		cub->game.pause = 1;
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mpause, 170, 140);
    	mlx_mouse_hook(cub->mlx_win, &button, cub);
	}
	else if (cub->game.pause == 1)
		cub->game.pause = 0;
}

int	key_press(int keycode, t_cub *cub)
{
	float	playerCos;
	float	playerSin;

	playerCos = cos(degrees_to_radians(cub->game.player_angle));
	playerSin = sin(degrees_to_radians(cub->game.player_angle));
	if ((keycode == 13 || keycode == 119) && cub->game.pause == 0)
		press_w(playerCos, playerSin, cub);
	else if ((keycode == 0 || keycode == 97
		|| keycode == 123 || keycode == 65361)
		&& cub->game.pause == 0)
		press_a(cub);
	else if ((keycode == 1 || keycode == 100
		|| keycode == 125 || keycode == 65363)
		&& cub->game.pause == 0)
		press_d(cub);
	else if ((keycode == 2 || keycode == 115) && cub->game.pause == 0)
		press_s(playerCos, playerSin, cub);
	else if ((keycode == 53 || keycode == 65307) && cub->game.pause == 0)
		ft_exit(cub);
	else if (keycode == 102 && cub->game.pause == 0)
		switch_fov(cub);
	else if (keycode == 109 && cub->game.pause == 0)
		switch_map(cub);
	else if (keycode == 112)
		pause_menu(cub);
	else if (keycode == 108)
		light_switch(cub);
	else if (keycode == 116)
		textures_switch(cub);
	if (cub->game.pause == 0)
		render(cub);
	return (0);
}

int	key_release(int keycode, t_cub *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	press_w(float pCos, float pSin, t_cub *cub)
{
	float new_x;
	float new_y;

	new_x = cub->px + pCos * cub->game.player_speed;
	new_y = cub->py + pSin * cub->game.player_speed;
	if (cub->map.map[(int)new_y / 16][(int)new_x / 16] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}

void	press_a(t_cub *cub)
{
	cub->game.player_angle = fix_angle(cub->game.player_angle - 5);
}

void	press_d(t_cub *cub)
{
	cub->game.player_angle = fix_angle(cub->game.player_angle + 5);
}

void	press_s(float pCos, float pSin, t_cub *cub)
{
	float new_x;
	float new_y;

	new_x = cub->px - pCos * cub->game.player_speed;
	new_y = cub->py - pSin * cub->game.player_speed;
	if (cub->map.map[(int)new_y / 16][(int)new_x / 16] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}

