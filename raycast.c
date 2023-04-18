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
	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	rayCos;
	float	raySin;
	float	increment;

	ray = 0;
	clear_fov(cub);
	ray_angle = fix_angle(cub->game.player_angle - FOV2);
	increment = (float)FOV / (float)cub->width;
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

int check_hit(t_cub *cub, float ray_x, float ray_y)
{
	int	vertical;
	float	a;
	float	b;

	a = ray_x - 1;
	b = ray_x + 1;

	vertical = 0;
	if (cub->map.map[(int)(ray_y / 16)][(int)(ray_x / 16)] == '1')
	{
		if (cub->map.map[(int)(ray_y / 16)][(int)(a / 16)] == '0'
			|| cub->map.map[(int)(ray_y / 16)][(int)(b / 16)] == '0')
			vertical = 1;
	}
	return (vertical);
}

int	get_Pos( float ray)
{
	float	unit_dist;
	float	largura;
	float	x_increment;
	float	dir;
	float	wall_x;

	dir = ((int)ray % 16);
	wall_x = (ray - dir);
	unit_dist = (wall_x / dir);
	largura = (unit_dist * 16);
	x_increment = (64 / largura);
	wall_x = wall_x * x_increment;
	return (wall_x);
}

int	get_WalX(t_cub *cub, float ray_x, float ray_y)
{
	float	wall_x;

	if (check_hit(cub, ray_x, ray_y))
	{
		wall_x = get_Pos(ray_y);
		if (ray_x < cub->px)
			wall_x = 64 - wall_x;	
	}
	else
	{
		wall_x = get_Pos(ray_x);
		if (ray_y > cub->py)
			wall_x = 64 - wall_x;	
	}
	return (wall_x);
}

void draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y)
{
	float	wall_height;
	float	distance;
	float	fish_eye;

	distance = distance_between_points(cub->px, cub->py, ray_x, ray_y);
	fish_eye = (distance / 16) * cos(degrees_to_radians(ray_angle - cub->game.player_angle));
	wall_height = floor((cub->height / 2) / fish_eye);
	float	wall_x;
	
	wall_x = get_WalX(cub, ray_x, ray_y);
	if (wall_height >= cub->height)
		draw_texture(ray, 0, cub->height, cub, wall_x, ray_x, ray_y);
	else
	{
		draw_vertical_line(ray, 0, floor((cub->height / 2) - wall_height), cub, cub->img.colors[1]);
		draw_texture(ray, floor((cub->height / 2) - wall_height), 2 * wall_height, cub, wall_x, ray_x, ray_y);
		draw_vertical_line(ray, floor((cub->height / 2) + wall_height), cub->height, cub, cub->img.colors[0]);
	}
}

void	draw_texture(int x, int y, float len, t_cub *cub, float wall_x, float ray_x, float ray_y)
{
	if (check_hit(cub, ray_x, ray_y))
	{
		if (ray_x < cub->px)
			draw_texture2(x, y, len, cub, wall_x, cub->img.WE_tex, ray_x);
		else
			draw_texture2(x, y, len, cub, wall_x, cub->img.EA_tex, ray_x);
	}
	else
	{
		if (ray_y < cub->py)
			draw_texture2(x, y, len, cub, wall_x, cub->img.NO_tex, ray_x);
		else
			draw_texture2(x, y, len, cub, wall_x, cub->img.SO_tex, ray_x);
	}
}

void	draw_texture2(int x, int y, float len, t_cub *cub, float wall_x, t_img_mlx *texture, float ray_x)
{
	int 	i;
	float	tex_x;
	float	tex_y;
	float	increment;

	(void)(ray_x);
	tex_x = wall_x;
	increment = texture->height / len;
	i = 0;
	tex_y = 0;
	while (i < len && i < cub->height)
	{
		if (y < cub->height && x < cub->width && (y >= 0 && x >= 0 && tex_y <= texture->height && tex_x <= texture->width))
			my_mlx_pixel_put(cub, x, y,
			my_mlx_pixel_get(texture, tex_x, tex_y));
		tex_y += increment;
		y++;
		i++;
	}
}
