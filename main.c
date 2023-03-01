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

t_cub	*cub(void)
{
	static t_cub	a;
	return (&a);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	(void)y;
	(void)button;

	if (x > (cub->width / 2))
		press_d(cub);
	else
		press_a(cub);
	return (0);
}

int main(int argc, char **argv)
{
	char	**path;

	(void)argc;
	(void)argv;
	if (argc != 2)
		exit_free(NULL, 1, "Wrong number of arguments");
	path = parse(cub(), argv[1]);
	if (check_map(cub(), path))
	{
		alloc().free_matrix((void **)path);
		exit_free(cub(), 1, "Error with map");
	}
	if (prep_alg(cub()))
	{
		alloc().free_matrix((void **)path);
		exit_free(cub(), 1, "Map is open");
	}
	cub()->mlx = mlx_init();
	if (!cub()->mlx)
		printf("MLX init error!");
	init_img(cub());
	init_vars(cub());
	cub()->mlx_win = mlx_new_window(cub()->mlx,
			cub()->width, cub()->height, "cub3d");
	//mlx_loop_hook(cub()->mlx, render, cub());
    mlx_mouse_hook(cub()->mlx_win, &mouse_hook, cub());
	mlx_hook(cub()->mlx_win, 2, 1L << 0, &key_press, cub());
	mlx_hook(cub()->mlx_win, 3, 1L << 1, &key_release, cub());
	mlx_hook(cub()->mlx_win, 17, 1L << 17, &ft_exit, cub());
	mlx_loop(cub()->mlx);
	alloc().free_matrix((void **)path);
	exit_free(cub(), 0, "Terminated");
	return (0);
}
