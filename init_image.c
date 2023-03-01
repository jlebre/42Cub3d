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
    cub->game.mmp = mlx_new_image(cub->mlx, 5, 5);
    ft_memset(cub->game.mmp->data, 150, cub->game.mmp->width * cub->game.mmp->height * sizeof(int));
    cub->game.mmbase = mlx_new_image(cub->mlx, 128, 128);
    ft_memset(cub->game.mmbase->data, 0, cub->game.mmbase->width * cub->game.mmbase->height * sizeof(int));
}
