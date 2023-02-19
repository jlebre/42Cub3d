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

void	init_img(t_game *game)
{
    int	img_width;
	int	img_height;

    game->white = mlx_xpm_file_to_image(game->mlx, "image/white.xpm",
            &img_width, &img_height);
    game->blue = mlx_xpm_file_to_image(game->mlx, "image/blue.xpm",
            &img_width, &img_height);
    game->mmp = mlx_new_image(game->mlx, 5, 5);
    ft_memset(game->mmp->data, 158, game->mmp->width * game->mmp->height * sizeof(int));
}

/*
    img = mlx_new_image(mlx, 128, 128);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
*/