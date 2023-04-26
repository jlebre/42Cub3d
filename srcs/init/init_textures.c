/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:43:28 by marvin            #+#    #+#             */
/*   Updated: 2023/04/21 15:43:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*texture_init(void *mlx, char *path, char **complete_path)
{
	int		width;
	int		height;
	t_img	*img;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img)
		exit_free(this_cub(), complete_path, 1, "Error loading texture");
	return (img);
}

void	init_compass(t_cub *cub)
{
	cub->img.compass[0] = texture_init(cub->mlx, "image/compass/B1.xpm", NULL);
	cub->img.compass[1] = texture_init(cub->mlx, "image/compass/B2.xpm", NULL);
	cub->img.compass[2] = texture_init(cub->mlx, "image/compass/B3.xpm", NULL);
	cub->img.compass[3] = texture_init(cub->mlx, "image/compass/B4.xpm", NULL);
	cub->img.compass[4] = texture_init(cub->mlx, "image/compass/B5.xpm", NULL);
	cub->img.compass[5] = texture_init(cub->mlx, "image/compass/B6.xpm", NULL);
	cub->img.compass[6] = texture_init(cub->mlx, "image/compass/B7.xpm", NULL);
	cub->img.compass[7] = texture_init(cub->mlx, "image/compass/B8.xpm", NULL);
}

void	init_textutes(t_cub *cub, char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (cub->img.order[i] == 'N')
			cub->img.no_tex = texture_init(cub->mlx, path[i], path);
		else if (cub->img.order[i] == 'S')
			cub->img.so_tex = texture_init(cub->mlx, path[i], path);
		else if (cub->img.order[i] == 'W')
			cub->img.we_tex = texture_init(cub->mlx, path[i], path);
		else if (cub->img.order[i] == 'E')
			cub->img.ea_tex = texture_init(cub->mlx, path[i], path);
	}
	cub->img.chess = texture_init(cub->mlx, "textures/chess.xpm", path);
}
