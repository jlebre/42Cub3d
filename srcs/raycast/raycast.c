/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:30:54 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 16:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_cub *cub)
{
	int		ray;
	char	wall;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	rayCos;
	double	raySin;
	double	increment;

	ray = 0;
	clear_fov(cub);
	ray_angle = fix_angle(cub->game.player_angle - FOV2);
	increment = (double)FOV / (double)cub->width;
	while (ray < (cub->width))
	{
		ray_x = cub->px;
		ray_y = cub->py;
		raySin = sin(degrees_to_radians(ray_angle)) / 10;
		rayCos = cos(degrees_to_radians(ray_angle)) / 10;
		wall = '0';
		while (wall == '0')
		{
			ray_x += rayCos;
			ray_y += raySin;
			draw_fov(cub, ray_x + 2, ray_y + 2, 0x0000FF00);
			wall = cub->map.map[(int)(ray_y / 16)][(int)(ray_x / 16)];
		}
		draw_walls(cub, ray, ray_angle, ray_x, ray_y);
		ray_angle += increment;
		ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

int check_hit(t_cub *cub, double ray_x, double ray_y)
{
	int	vertical;
	double	a;
	double	b;

	a = ray_x - 0.1;
	b = ray_x + 0.1;

	vertical = 0;
	if (cub->map.map[(int)(ray_y / 16)][(int)(ray_x / 16)] == '1')
	{
		if (cub->map.map[(int)(ray_y / 16)][(int)(a / 16)] == '0'
			|| cub->map.map[(int)(ray_y / 16)][(int)(b / 16)] == '0')
			vertical = 1;
	}
	return (vertical);
}
