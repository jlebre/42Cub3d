/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:57:02 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 19:57:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void   destroy_img(t_cub *game)
{
	mlx_destroy_image(game->mlx, game->game.mmp);
	mlx_destroy_image(game->mlx, game->game.mmbase);
	mlx_destroy_image(game->mlx, game->game.black);
	mlx_destroy_image(game->mlx, game->game.blue);
	mlx_destroy_image(game->mlx, game->game.white);
}

int	ft_exit(t_cub *game)
{
	destroy_img(game);
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	alloc().free_matrix((void **)game->map.map);
	printf("Game exited sucessfully!\n");
	exit (0);
}
