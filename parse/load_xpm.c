/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:22:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 16:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_imgs(t_cub *data, t_parse *parse, char **path)
{
	int	i;
	int	width;
	int	height;

	data->img.img = alloc().calloc(sizeof(void *) * 5);
	if (!data->img.img)
	{
		free_parse(parse);
		exit_free(data, 1, "Error malloc with imgs");
	}
	width = SIZE_X;
	height = SIZE_Y;
	i = -1;
	while (++i < 4)
	{
		data->img.img[i] = mlx_xpm_file_to_image(data->mlx_win, \
		path[i], &width, &height);
		if (!data->img.img[i])
		{
			free_parse(parse);
			exit_free(data, 1, "Error loading the img");
		}
	}
}
