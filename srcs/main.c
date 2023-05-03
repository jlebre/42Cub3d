/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:39:49 by mtavares          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:25 by jlebre           ###   ########.fr       */
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

void	init(char **av)
{
	char	**path;

	path = parse(this_cub(), av[1]);
	if (check_map(this_cub(), path))
		exit_free(this_cub(), path, 1, "Error with map");
	if (prep_alg(this_cub()))
		exit_free(this_cub(), path, 1, "Map is open");
	(this_cub())->mlx = mlx_init();
	if (!(this_cub())->mlx)
		exit_free((this_cub()), path, 1, "Failed malloc on mlx_init");
	init_vars((this_cub()));
	init_textutes((this_cub()), path);
	alloc().free_matrix((void **)path);
	init_img((this_cub()));
	init_mini_map((this_cub()));
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_free(NULL, NULL, 1, "Wrong number of arguments");
	if (FOV > 180 || FOV < 0)
		exit_free(NULL, NULL, 1, "FOV must be between 0 and 180");
	init(av);
	(this_cub())->mlx_win = mlx_new_window((this_cub())->mlx, \
		(this_cub())->width, (this_cub())->height, "cub3d");
	if (!(this_cub())->mlx_win)
		exit_free((this_cub()), NULL, 1, "Failed malloc on mlx_new_window");
	render((this_cub()));
	mlx_hook((this_cub())->mlx_win, 2, 1L << 0, &key_press, (this_cub()));
	mlx_mouse_hook((this_cub())->mlx_win, &mouse_hook, (this_cub()));
	mlx_hook((this_cub())->mlx_win, 17, 1L << 17, &ft_exit, (this_cub()));
	mlx_loop((this_cub())->mlx);
}

//mlx_hook((this_cub)()->mlx_win, 3, 1L << 1, &key_release, (this_cub)());

/*
int	mouse_hook(int button, t_cub *cub)
{
	int	x;
	int	y;
	int	half;

	mlx_mouse_get_pos(cub->mlx, cub->mlx_win, &x, &y);
	half = 320;
	if (button == 1)
	{
		if (x >= half && !cub->game.pause)
		{
			cub->game.player_angle = fix_angle(cub->game.player_angle + 5);
			render(cub);
		}
		else if (x < half && !cub->game.pause)
		{
			cub->game.player_angle = fix_angle(cub->game.player_angle - 5);
			render(cub);
		}
	}
	return (0);
}
*/
