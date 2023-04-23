/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 64:18:26 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 64:18:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_cub *cub, int keycode)
{
	if (keycode == 65361)
		cub->game.player_angle = fix_angle(cub->game.player_angle - 5);
	else if (keycode == 65363)
		cub->game.player_angle = fix_angle(cub->game.player_angle + 5);
}

void	press_ws(double p_cos, double p_sin, t_cub *cub, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == 13 || keycode == 119)
	{
		new_x = cub->px + p_cos * cub->game.player_speed;
		new_y = cub->py + p_sin * cub->game.player_speed;
	}
	else
	{
		new_x = cub->px - p_cos * cub->game.player_speed;
		new_y = cub->py - p_sin * cub->game.player_speed;
	}
	if (cub->map.map[(int)new_y / 64][(int)new_x / 64] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}

void	press_ad(t_cub *cub, int type)
{
	double	new_dir;
	double	new_x;
	double	new_y;
	double	p_cos;
	double	p_sin;

	if (type == 1)
	{
		new_dir = cub->game.player_angle - 90;
	}
	else
	{
		new_dir = cub->game.player_angle + 90;
	}
	p_cos = cos(degrees_to_radians(new_dir));
	p_sin = sin(degrees_to_radians(new_dir));
	new_x = cub->px + p_cos * cub->game.player_speed;
	new_y = cub->py + p_sin * cub->game.player_speed;
	if (cub->map.map[(int)new_y / 64][(int)new_x / 64] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}
