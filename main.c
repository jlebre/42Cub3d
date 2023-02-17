/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:53:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 17:53:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*game(void)
{
	static t_game	a;
	return (&a);
}

int	render(t_game *game)
{
	(void)game;

	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//char	*str;
	
	/*
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	*/
	//str = argv[1];
	//read_map(str);
	//check();
	game()->mlx = mlx_init();
	if (!game()->mlx)
		printf("MLX init error!");
	//init_img(game());
	init_vars(game());
	game()->mlx_win = mlx_new_window(game()->mlx,
			game()->width * 60, game()->height * 60, "cub3d");
	mlx_loop_hook(game()->mlx, render, game());
	mlx_hook(game()->mlx_win, 2, 1L << 0, &key_press, game());
	mlx_hook(game()->mlx_win, 17, 1L << 17, &ft_exit, game());
	mlx_loop(game()->mlx);
	return (0);
}
