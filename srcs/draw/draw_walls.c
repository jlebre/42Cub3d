/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:26:51 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 23:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_hit(t_cub *cub);
void	get_wall_direction(int y, double len, t_cub *cub);

// Get the x position in the wall
// Dir vai ser um valor entre 0 e 15,
	// porque cada parede está dívidida em 64 partes
// Ray corresponde ao ray_x ou ray__y
double	get_pos(double ray)
{
	int		dir;
	double	wall_x;
	double	largura;
	double	x_increment;
	double	unit;

	dir = ((int)ray % 64);
	wall_x = ((int)ray - dir);
	unit = (wall_x / dir);
	largura = (unit * 64);
	x_increment = (64 / largura);
	wall_x = wall_x * x_increment;
	return (wall_x);
}

// Attribute the wall direction
void	get_wall_x(t_cub *cub)
{
	double	wall_x;

	if (cub->ray.vertical)
	{
		wall_x = get_pos(cub->ray.ray_y);
		if (cub->ray.ray_x < cub->px)
			wall_x = 64 - wall_x;
	}
	else
	{
		wall_x = get_pos(cub->ray.ray_x);
		if (cub->ray.ray_y > cub->py)
			wall_x = 64 - wall_x;
	}
	cub->ray.wall_x = wall_x;
}

void	draw_vertical_line(double y, double len, t_cub *cub, int color)
{
	int	i;
	int	limit;

	i = 0;
	if (cub->ray.ray < 0 || cub->ray.ray > cub->width)
		return ;
	limit = cub->height;
	while (i < len && (y + i) < limit)
	{
		if (y + i < cub->height && cub->ray.ray < cub->width
			&& y + i >= 0 && cub->ray.ray >= 0)
			my_mlx_pixel_put(cub, cub->ray.ray, y + i, color);
		i++;
	}
}

void	draw_walls(t_cub *cub)
{
	double	wall_height;
	double	distance;
	double	fish_eye;

	distance = distance_between_points(cub->px, cub->py,
			cub->ray.ray_x, cub->ray.ray_y) / 64;
	fish_eye = distance
		* cos(degrees_to_radians(cub->ray.ray_angle - cub->game.player_angle));
	wall_height = ((cub->height / 2) / fish_eye);
	check_hit(cub);
	get_wall_x(cub);
	if (wall_height >= cub->height / 2)
		get_wall_direction((int)((cub->height / 2) - wall_height),
			2 * wall_height, cub);
	else
	{
		draw_vertical_line(0, (int)((cub->height / 2) - wall_height),
			cub, cub->img.colors[1]);
		get_wall_direction((int)((cub->height / 2) - wall_height),
			2 * wall_height, cub);
		draw_vertical_line((int)((cub->height / 2) + wall_height),
			cub->height, cub, cub->img.colors[0]);
	}
}
