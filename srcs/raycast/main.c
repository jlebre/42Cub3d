/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:39:49 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/18 22:46:28 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_cub	*this_cub(void)
{
	static t_cub	data;

	return (&data);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	int	half;

	(void)y;
	half = (cub->width / 2);
	if (button == 1 && x >= half && cub->game.pause == 0)
	{
		cub->game.player_angle = fix_angle(cub->game.player_angle + 5);
		render(cub);
	}
	else if (button == 1 && x < half && cub->game.pause == 0)
	{
		cub->game.player_angle = fix_angle(cub->game.player_angle - 5);
		render(cub);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**path;

	(void)ac;
	(void)av;
	if (ac != 2)
		exit_free(NULL, 1, "Wrong number of arguments");
	path = parse(this_cub(), av[1]);
	if (check_map(this_cub(), path))
	{
		alloc().free_matrix((void **)path);
		exit_free(this_cub(), 1, "Error with map");
	}
	if (prep_alg(this_cub()))
	{
		alloc().free_matrix((void **)path);
		exit_free(this_cub(), 1, "Map is open");
	}
	(this_cub)()->mlx = mlx_init();
	if (!(this_cub)()->mlx)
		exit_free((this_cub)(), 1, "Failed malloc on mlx_init");
	init_vars((this_cub)());
	init_img((this_cub)());
	init_textutes((this_cub)(), path);
	init_mini_map((this_cub)());
	alloc().free_matrix((void **)path);
	(this_cub)()->mlx_win = mlx_new_window((this_cub)()->mlx, (this_cub)()->width, (this_cub)()->height, "cub3d");
	if (!(this_cub)()->mlx_win)
		exit_free((this_cub)(), 1, "Failed malloc on mlx_new_window");
	render((this_cub)());
	mlx_hook((this_cub)()->mlx_win, 2, 1L << 0, &key_press, (this_cub)());
	//mlx_hook((this_cub)()->mlx_win, 3, 1L << 1, &key_release, (this_cub)());
	mlx_mouse_hook((this_cub)()->mlx_win, &mouse_hook, (this_cub)());
	mlx_hook((this_cub)()->mlx_win, 17, 1L << 17, &ft_exit, (this_cub)());
	mlx_loop((this_cub)()->mlx);
}
