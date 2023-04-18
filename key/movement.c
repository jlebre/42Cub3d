/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:18:26 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 16:18:26 by marvin           ###   ########.fr       */
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

void	press_ws(float pCos, float pSin, t_cub *cub, int type)
{
	float new_x;
	float new_y;

    if (type == 1)
    {
        new_x = cub->px + pCos * cub->game.player_speed;
        new_y = cub->py + pSin * cub->game.player_speed;
    }
    else
    {
        new_x = cub->px - pCos * cub->game.player_speed;
        new_y = cub->py - pSin * cub->game.player_speed;
    }
	if (cub->map.map[(int)new_y / 16][(int)new_x / 16] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}

void	press_ad(t_cub *cub, int type)
{
	float new_dir;
	float new_x;
	float new_y;
	float pCos;
	float pSin;

    if (type == 1)
    {
        new_dir = cub->game.player_angle - 90;
    }
    else
    {
        new_dir = cub->game.player_angle + 90;
    }
	pCos = cos(degrees_to_radians(new_dir));
	pSin = sin(degrees_to_radians(new_dir));
	new_x = cub->px + pCos * cub->game.player_speed;
	new_y = cub->py + pSin * cub->game.player_speed;
	if (cub->map.map[(int)new_y / 16][(int)new_x / 16] != '1')
	{
		cub->px = new_x;
		cub->py = new_y;
	}
}
