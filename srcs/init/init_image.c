/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:57:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 01:57:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*texture_init(void *mlx, char *path, char **complete_path);
void	init_compass(t_cub *cub);

void	check_img(t_img *img)
{
	if (!img)
		exit_free(this_cub(), NULL, 1, "Error allocating imgs");
}

void	init_img2(t_cub *cub)
{
	check_img(cub->game.mmp);
	ft_memset(cub->game.mmp->data, 150, cub->game.mmp->width
		* cub->game.mmp->height * sizeof(int));
	cub->screen = mlx_new_image(cub->mlx, cub->width, cub->height);
	check_img(cub->screen);
	ft_memset(cub->screen->data, 0, cub->screen->width
		* cub->screen->height * sizeof(int));
	cub->game.fov = mlx_new_image(cub->mlx, cub->map.width, cub->map.height);
	check_img(cub->game.fov);
	ft_memset(cub->game.fov->data, 0, cub->game.fov->width
		* cub->game.fov->height * sizeof(int));
	cub->game.mmbase = mlx_new_image(cub->mlx,
			(cub->map.width16) - 16, cub->map.height16);
	check_img(cub->game.mmbase);
	ft_memset(cub->game.mmbase->data, 0, (cub->game.mmbase->width)
		* (cub->game.mmbase->height) * sizeof(int));
	cub->game.mini = mlx_new_image(cub->mlx, 128, 128);
	check_img(cub->game.mini);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width
		* cub->game.mini->height * sizeof(int));
	cub->game.bordamm = mlx_new_image(cub->mlx, 136, 136);
	check_img(cub->game.bordamm);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width
		* cub->game.mini->height * sizeof(int));
}

void	init_img(t_cub *cub)
{
	cub->game.white = texture_init(cub->mlx, "image/white.xpm", NULL);
	cub->game.blue = texture_init(cub->mlx, "image/blue.xpm", NULL);
	cub->game.black = texture_init(cub->mlx, "image/black.xpm", NULL);
	cub->game.mpause = texture_init(cub->mlx, "image/menu_pause.xpm", NULL);
	cub->img.heart = texture_init(cub->mlx, "image/heart.xpm", NULL);
	cub->img.settings = texture_init(cub->mlx, "image/settings.xpm", NULL);
	cub->game.mmp = mlx_new_image(cub->mlx, 5, 5);
	init_img2(cub);
	init_compass(cub);
}
