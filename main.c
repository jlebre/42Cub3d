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

int main(int argc, char **argv)
{
	char	*str;
	
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	str = argv[1];
	read_map(str);
	check();
	game().mlx = mlx_init();
	if (!game().mlx)
		ft_error("MLX init error!");
	init_img(&game());
	init_vars(&game());
	game().mlx_win = mlx_new_window(game().mlx,
			game().width * 64, game().height * 64, "cub3d");
	mlx_loop_hook(game().mlx, render, &game());
	mlx_hook(game().mlx_win, 2, 1L << 0, &key_press, &game());
	mlx_hook(game().mlx_win, 17, 1L << 17, &ft_exit, &game());
	mlx_loop(game().mlx);
	return (0);
}

/*
int main()
{
	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	game().mlx = mlx_init();
	if (!game().mlx)
		ft_error("MLX init error!");
	game().mlx_win = mlx_new_window(game().mlx,
			screenWidth * 64, screenHeight * 64, "cub3d");
	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
	}
	double	deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
	double	deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
	//which box of the map we're in
	int mapX = int(posX);
	int mapY = int(posY);

	//length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;

	//length of ray from one x or y-side to next x or y-side
	double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
	double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
	double perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

	//calculate step and initial sideDist
	if (rayDirX < 0)
	{
	stepX = -1;
	sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
	stepX = 1;
	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
	stepY = -1;
	sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
	stepY = 1;
	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}

	//perform DDA
	while (hit == 0)
	{
	//jump to next map square, either in x-direction, or in y-direction
	if (sideDistX < sideDistY)
	{
		sideDistX += deltaDistX;
		mapX += stepX;
		side = 0;
	}
	else
	{
		sideDistY += deltaDistY;
		mapY += stepY;
		side = 1;
	}
	//Check if ray has hit a wall
	if (worldMap[mapX][mapY] > 0) hit = 1;
	} 

	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(side == 0) perpWallDist = (sideDistX - deltaDistX);
	else          perpWallDist = (sideDistY - deltaDistY);
}
*/
