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

void	destroy_img(t_cub *game)
{
	if (game->game.mmp)
		mlx_destroy_image(game->mlx, game->game.mmp);
	if (game->game.black)
		mlx_destroy_image(game->mlx, game->game.black);
	if (game->game.blue)
		mlx_destroy_image(game->mlx, game->game.blue);
	if (game->game.white)
		mlx_destroy_image(game->mlx, game->game.white);
	if (game->screen)
		mlx_destroy_image(game->mlx, game->screen);
	if (game->game.fov)
		mlx_destroy_image(game->mlx, game->game.fov);
	if (game->game.mmbase)
		mlx_destroy_image(game->mlx, game->game.mmbase);
	if (game->game.mini)
		mlx_destroy_image(game->mlx, game->game.mini);
	if (game->game.mpause)
		mlx_destroy_image(game->mlx, game->game.mpause);
	if (game->img.no_tex)
		mlx_destroy_image(game->mlx, game->img.no_tex);
	if (game->img.so_tex)
		mlx_destroy_image(game->mlx, game->img.so_tex);
	if (game->img.we_tex)
		mlx_destroy_image(game->mlx, game->img.we_tex);
	if (game->img.ea_tex)
		mlx_destroy_image(game->mlx, game->img.ea_tex);
	if (game->img.chess)
		mlx_destroy_image(game->mlx, game->img.chess);
}

int	ft_exit(t_cub *game)
{
	exit_free(game, 0, "Game exited sucessfully!");
	return (0);
}
