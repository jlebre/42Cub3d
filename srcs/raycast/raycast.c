/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 64:30:54 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 64:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_loop(double ray_cos, double ray_sin, t_cub *cub)
{
	cub->ray.ray_x += ray_cos;
	cub->ray.ray_y += ray_sin;
	draw_fov(cub, (cub->ray.ray_x / 4) + 2,
		(cub->ray.ray_y / 4) + 2, 0x0000FF00);
	cub->ray.wall = cub->map.map[(int)(cub->ray.ray_y / 64)]
	[(int)(cub->ray.ray_x / 64)];
}

void	raycast(t_cub *cub)
{
	double	ray_cos;
	double	ray_sin;
	double	increment;

	cub->ray.ray = 0;
	clear_fov(cub);
	cub->ray.ray_angle = fix_angle(cub->game.player_angle - FOV2);
	increment = (double)FOV / (double)cub->width;
	while (cub->ray.ray < (cub->width))
	{
		cub->ray.ray_x = cub->px;
		cub->ray.ray_y = cub->py;
		ray_sin = sin(degrees_to_radians(cub->ray.ray_angle)) / 10;
		ray_cos = cos(degrees_to_radians(cub->ray.ray_angle)) / 10;
		cub->ray.wall = '0';
		while (cub->ray.wall == '0')
			ray_loop(ray_cos, ray_sin, cub);
		draw_walls(cub);
		cub->ray.ray_angle += increment;
		cub->ray.ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

void	check_hit(t_cub *cub)
{
	int		vertical;
	double	a;
	double	b;

	a = cub->ray.ray_x - 0.1;
	b = cub->ray.ray_x + 0.1;
	vertical = 0;
	if (cub->map.map[(int)(cub->ray.ray_y / 64)]
		[(int)(cub->ray.ray_x / 64)] == '1')
	{
		if (cub->map.map[(int)(cub->ray.ray_y / 64)][(int)(a / 64)] == '0'
			|| cub->map.map[(int)(cub->ray.ray_y / 64)][(int)(b / 64)] == '0')
			vertical = 1;
	}
	cub->ray.vertical = vertical;
}
