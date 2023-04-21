/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:58:51 by marvin            #+#    #+#             */
/*   Updated: 2023/04/21 13:58:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_pixel_get(t_img *texture, int x, int y)
{
	char	*dst;

	dst = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->screen->data + (y * cub->screen->size_line
			+ x * (cub->screen->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game.mmbase->data + (y * cub->game.mmbase->size_line
			+ x * (cub->game.mmbase->bpp / 8));
	*(unsigned int *)dst = color;
}
