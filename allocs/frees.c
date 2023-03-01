/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:25 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 16:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parse(t_parse *parse)
{
	if (parse->file)
		alloc().free_matrix((void **)parse->file);
	if (parse->path_to_img)
		alloc().free_matrix((void **)parse->path_to_img);
}

void	exit_parse(t_cub *data, int status, char *str, t_parse *parse)
{
	free_parse(parse);
	exit_free(data, status, str);
}

static void	free_imgs(t_cub *data)
{
	int	i;

	if (data->img.img)
	{
		i = -1;
		while (data->img.img[++i])
			mlx_destroy_image(data->mlx_win, data->img.img[i]);
		alloc().free_array((void *)data->img.img);
	}
}

static void	free_mlx(t_cub	*data)
{
	free_imgs(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx_win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	exit_free(t_cub *data, int status, char *str)
{
	if (status)
		printf_fd(2, "Error: %s\n", str);
	else
		printf_fd(1, "%s\n", str);
	if (data)
	{
		if (data->map.map)
			alloc().free_matrix((void **)data->map.map);
		free_mlx(data);
	}
	exit(status);
}
