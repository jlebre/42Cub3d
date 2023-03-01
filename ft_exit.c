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

void   destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mmp);
	mlx_destroy_image(game->mlx, game->mmbase);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_img(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_matrix(game->map);
	printf("Game exited sucessfully!\n");
	exit (0);
}
