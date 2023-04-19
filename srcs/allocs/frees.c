/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:25 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/16 20:16:20 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	destroy_img(t_cub *game);

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

static void	free_mlx(t_cub	*data)
{
	destroy_img(data);
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
