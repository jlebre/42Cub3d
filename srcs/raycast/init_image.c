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

void	check_img(t_img *img)
{
	if (!img)
		exit_free(this_cub(), 1, "Error allocating imgs");
}

t_img	*texture_init(void *mlx, char *path)
{
	int		width;
	int		height;
	t_img	*img;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img)
		exit_free(this_cub(), 1, "Error loading texture");
	return (img);
}

void	init_compass(t_cub *cub)
{
	cub->img.compass[0] = texture_init(cub->mlx, "image/compass/B1.xpm");
	cub->img.compass[1] = texture_init(cub->mlx, "image/compass/B2.xpm");
	cub->img.compass[2] = texture_init(cub->mlx, "image/compass/B3.xpm");
	cub->img.compass[3] = texture_init(cub->mlx, "image/compass/B4.xpm");
	cub->img.compass[4] = texture_init(cub->mlx, "image/compass/B5.xpm");
	cub->img.compass[5] = texture_init(cub->mlx, "image/compass/B6.xpm");
	cub->img.compass[6] = texture_init(cub->mlx, "image/compass/B7.xpm");
	cub->img.compass[7] = texture_init(cub->mlx, "image/compass/B8.xpm");
}

void	init_textutes(t_cub *cub, char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (cub->img.order[i] == 'N')
			cub->img.no_tex = texture_init(cub->mlx, path[i]);
		else if (cub->img.order[i] == 'S')
			cub->img.so_tex = texture_init(cub->mlx, path[i]);
		else if (cub->img.order[i] == 'W')
			cub->img.we_tex = texture_init(cub->mlx, path[i]);
		else if (cub->img.order[i] == 'E')
			cub->img.ea_tex = texture_init(cub->mlx, path[i]);
	}
	cub->img.chess = texture_init(cub->mlx, "textures/chess.xpm");
}

void	init_img(t_cub *cub)
{
	cub->game.white = texture_init(cub->mlx, "image/white.xpm");
	cub->game.blue = texture_init(cub->mlx, "image/blue.xpm");
	cub->game.black = texture_init(cub->mlx, "image/black.xpm");
	cub->game.mpause = texture_init(cub->mlx, "image/menu_pause.xpm");
	cub->img.heart = texture_init(cub->mlx, "image/heart.xpm");
	cub->img.settings = texture_init(cub->mlx, "image/settings.xpm");
	cub->game.mmp = mlx_new_image(cub->mlx, 5, 5);
	ft_memset(cub->game.mmp->data, 150, cub->game.mmp->width * cub->game.mmp->height * sizeof(int));
	check_img(cub->game.mmp);
	cub->screen = mlx_new_image(cub->mlx, cub->width, cub->height);
	check_img(cub->screen);
	ft_memset(cub->screen->data, 0, cub->screen->width * cub->screen->height * sizeof(int));
	cub->game.fov = mlx_new_image(cub->mlx, cub->map.width, cub->map.height);
	check_img(cub->game.fov);
	ft_memset(cub->game.fov->data, 0, cub->game.fov->width * cub->game.fov->height * sizeof(int));
	cub->game.mmbase = mlx_new_image(cub->mlx, cub->map.width - 16, cub->map.height);
	check_img(cub->game.mmbase);
	ft_memset(cub->game.mmbase->data, 0, (cub->game.mmbase->width - 16) * (cub->game.mmbase->height) * sizeof(int));
	cub->game.mini = mlx_new_image(cub->mlx, 128, 128);
	check_img(cub->game.mini);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width * cub->game.mini->height * sizeof(int));
	cub->game.bordamm = mlx_new_image(cub->mlx, 136, 136);
	ft_memset(cub->game.mini->data, 0, cub->game.mini->width * cub->game.mini->height * sizeof(int));
	check_img(cub->game.bordamm);
	init_compass(cub);
}
