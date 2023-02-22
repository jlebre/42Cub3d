/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:22:59 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/31 19:09:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	load_imgs(t_cub *data, char **path)
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
		data->img.img[i] = mlx_xpm_file_to_image(data->win, \
		path[i], &width, &height);
		if (!data->img.img[i])
		{
			free_parse(parse);
			exit_free(data, 1, "Error loading the img");
		}
	}
}
