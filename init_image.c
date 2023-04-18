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

void	init_compass(t_cub *cub)
{
	int	img_width;
	int	img_height;
	
	cub->img.compass[0] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B1.xpm",
		&img_width, &img_height);
	cub->img.compass[1] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B2.xpm",
		&img_width, &img_height);
	cub->img.compass[2] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B3.xpm",
		&img_width, &img_height);
	cub->img.compass[3] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B4.xpm",
		&img_width, &img_height);
	cub->img.compass[4] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B5.xpm",
		&img_width, &img_height);
	cub->img.compass[5] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B6.xpm",
		&img_width, &img_height);
	cub->img.compass[6] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B7.xpm",
		&img_width, &img_height);
	cub->img.compass[7] = mlx_xpm_file_to_image(cub->mlx, "image/compass/B8.xpm",
		&img_width, &img_height);
}

void	init_textutes(t_cub *cub, char **path)
{
	int	img_width;
	int	img_height;

	cub->img.NO_tex = mlx_xpm_file_to_image(cub->mlx, path[0],
		&img_width, &img_height);
	cub->img.SO_tex = mlx_xpm_file_to_image(cub->mlx, path[1],
		&img_width, &img_height);
	cub->img.WE_tex = mlx_xpm_file_to_image(cub->mlx, path[2],
		&img_width, &img_height);
	cub->img.EA_tex = mlx_xpm_file_to_image(cub->mlx, path[3],
		&img_width, &img_height);
	cub->img.chess = mlx_xpm_file_to_image(cub->mlx, "textures/chess.xpm",
		&img_width, &img_height);
}

void	init_img(t_cub *cub)
{
	int	img_width;
	int	img_height;

	cub->game.white = mlx_xpm_file_to_image(cub->mlx, "image/white.xpm",
		&img_width, &img_height);
	cub->game.blue = mlx_xpm_file_to_image(cub->mlx, "image/blue.xpm",
		&img_width, &img_height);
	cub->game.black = mlx_xpm_file_to_image(cub->mlx, "image/black.xpm",
		&img_width, &img_height);
	cub->game.mpause = mlx_xpm_file_to_image(cub->mlx, "image/menu_pause.xpm",
		&img_width, &img_height);
	cub->img.heart = mlx_xpm_file_to_image(cub->mlx, "image/heart.xpm",
		&img_width, &img_height);
	cub->game.mmp = mlx_new_image(cub->mlx, 5, 5);
	ft_memset(cub->game.mmp->data, 150, cub->game.mmp->width * cub->game.mmp->height * sizeof(int));
	cub->screen = mlx_new_image(cub->mlx, cub->width, cub->height);
	ft_memset(cub->screen->data, 0, cub->screen->width * cub->screen->height * sizeof(int));
	cub->game.fov = mlx_new_image(cub->mlx, cub->map.width, cub->map.height);
	ft_memset(cub->game.fov->data, 0, cub->game.fov->width * cub->game.fov->height * sizeof(int));
	cub->game.mmbase = mlx_new_image(cub->mlx, cub->map.width - 16, cub->map.height);
	ft_memset(cub->game.mmbase->data, 0, (cub->game.mmbase->width - 16) * (cub->game.mmbase->height) * sizeof(int));
	cub->game.mini = mlx_new_image(cub->mlx, 128, 128);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width * cub->game.mini->height * sizeof(int));
	cub->game.bordamm = mlx_new_image(cub->mlx, 136, 136);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width * cub->game.mini->height * sizeof(int));
	init_compass(cub);
}
