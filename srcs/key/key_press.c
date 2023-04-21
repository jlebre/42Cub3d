/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:00:34 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 20:00:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_ws(double p_cos, double p_sin, t_cub *cub, int keycode);
void	press_ad(t_cub *cub, int type);
void	rotate(t_cub *cub, int keycode);
void	switch_map(t_cub *cub);
int		button(int button, int x, int y, t_cub *cub);
void	pause_menu(t_cub *cub);
int		key_press2(int keycode, t_cub *cub);

int	key_press(int keycode, t_cub *cub)
{
	double	p_cos;
	double	p_sin;

	p_cos = cos(degrees_to_radians(cub->game.player_angle));
	p_sin = sin(degrees_to_radians(cub->game.player_angle));
	if ((keycode == 13 || keycode == 119 || keycode == 2 || keycode == 115)
		&& !cub->game.pause)
		press_ws(p_cos, p_sin, cub, keycode);
	else if ((keycode == 0 || keycode == 97
			|| keycode == 123) && !cub->game.pause)
		press_ad(cub, 1);
	else if ((keycode == 1 || keycode == 100
			|| keycode == 125) && !cub->game.pause)
		press_ad(cub, 2);
	else if ((keycode == 65361 || keycode == 65363) && !cub->game.pause)
		rotate(cub, keycode);
	key_press2(keycode, cub);
	if (!cub->game.pause)
		render(cub);
	return (0);
}

int	key_press2(int keycode, t_cub *cub)
{
	if (keycode == 65453 && cub->game.lifes > 0 && !cub->game.pause)
		cub->game.lifes--;
	else if ((keycode == 53 || keycode == 65307))
		ft_exit(cub);
	else if (keycode == 109 && !cub->game.pause)
		switch_map(cub);
	else if (keycode == 112)
		pause_menu(cub);
	return (0);
}

int	key_release(int keycode, t_cub *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
