/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:40:07 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/24 14:14:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <dirent.h>
# include <mlx.h>
# include "mlx_int.h"
# include <printf_fd.h>
# include <allocs.h>
# include <str.h>

# define FOV 60
# define FOV2 30
# define PI 3.14159265358979323846

typedef struct s_cub	t_cub;
typedef struct s_image	t_image;
typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_ray	t_ray;

struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		width16;
	int		height16;
};

struct	s_ray
{
	int		ray;
	int		vertical;
	int		wall;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	wall_x;
};

struct	s_image
{
	t_img	*no_tex;
	t_img	*so_tex;
	t_img	*we_tex;
	t_img	*ea_tex;
	t_img	*chess;
	t_img	*floormm;
	t_img	*heart;
	t_img	*settings;
	t_img	*compass[8];
	t_img	*fire[4];
	int		colors[2];
	char	order[5];
};

struct s_game
{
	double	player_angle;
	void	*white;
	void	*blue;
	void	*black;
	int		player_speed;
	int		map_on;
	int		pause;
	int		lifes;
	t_img	*fov;
	t_img	*mmp;
	t_img	*mmbase;
	t_img	*mini;
	t_img	*mpause;
	t_img	*bordamm;
};

struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	char	**file;
	int		width;
	int		height;
	char	direction;
	double	px;
	double	py;
	int		num_player;
	t_img	*screen;
	t_image	img;
	t_map	map;
	t_game	game;
	t_ray	ray;
};

// INIT
void	init_vars(t_cub *cub);
void	init_img(t_cub *cub);
void	init_textutes(t_cub *cub, char **path);

// RENDER
int		render(t_cub *cub);

// MINIMAP
void	init_mini_map(t_cub *cub);
void	mini_map(t_cub *cub);

// FOV
void	draw_fov(t_cub *cub, int x, int y, int color);
void	clear_fov(t_cub *cub);

// KEYPRESS
int		key_press(int keycode, t_cub *game);
int		key_release(int keycode, t_cub *game);

// RAYCAST
void	raycast(t_cub *cub);
void	draw_walls(t_cub *cub);

// DRAW
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		my_mlx_pixel_get(t_img *texture, int x, int y);
void	draw_square(t_cub *cub, int x, int y, int color);
void	draw_texture(int y, double len, t_cub *cub, t_img *texture);
void	clear_screen(t_cub *cub);
void	draw_pixel(t_cub *cub, int x, int y, int color);

// MATH FUNCTIONS
int		ft_abs(int n);

// UTILS
int		ft_exit(t_cub *game);
float	degrees_to_radians(float degrees);
int		fix_angle(int angle);
float	distance_between_points(float x1, float y1, float x2, float y2);
void	*ft_memset(void *str, int c, size_t n);

t_cub	*this_cub(void);
void	exit_free(t_cub *data, int status, char *str);
char	**parse(t_cub *data, char *name);
int		prep_alg(t_cub *data);
int		valid_chars(char c);
int		orientation_player(char c);
int		check_map(t_cub *data, char **path);

#endif
