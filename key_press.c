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

int	key_press2(int keycode, t_game *game)
{
	if (keycode == 123 || keycode == 65361)
	{
		printf("LEFT key pressed\n");
	}
	else if (keycode == 125 || keycode == 65363)
	{
		printf("RIGHT key pressed\n");
	}
	else if (keycode == 53 || keycode == 65307)
		ft_exit(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 119)
	{
		printf("W key pressed\n");
	}
	else if (keycode == 0 || keycode == 97)
	{
		printf("A key pressed\n");
	}
	else if (keycode == 1 || keycode == 100)
	{
		printf("D key pressed\n");
	}
	else if (keycode == 2 || keycode == 115)
	{
		printf("S key pressed\n");
	}	
	else 
		key_press2(keycode, game);
	return (0);
}
