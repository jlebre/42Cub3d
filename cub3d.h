/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:55:22 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 17:55:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* 
// MAC KEYS:
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_D					1
# define KEY_S					2
# define UP 					126
# define DOWN 					124
# define LEFT					123
# define RIGHT 					125
*/

// LINUX KEYS:
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_D					100
# define KEY_S					115
# define UP 					65362
# define DOWN 					65364
# define LEFT					65361
# define RIGHT 					65363

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <dirent.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "libft.h"

# define BUFFER_SIZE 42
# define PI 3.14159265359
# define PI2 6.28318530718
# define PI3 4.71238898038
# define HALF_PI 1.57079632679
# define RADIAN 0.01745329251
# define FOV_ANGLE (60 * (PI / 180))
# define FOV 60
# define FOV2 30
# define NUM_RAYS 1200
# define MINIMAP_SCALE_FACTOR 0.1
# define TILE_SIZE 64
# define TILE_SIZE_SCALE (TILE_SIZE * MINIMAP_SCALE_FACTOR)
# define NUM_TEXTURES 5
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TEXTURE_SCALE_FACTOR 0.5
# define TEXTURE_WIDTH_SCALE (TEXTURE_WIDTH * TEXTURE_SCALE_FACTOR)
# define TEXTURE_HEIGHT_SCALE (TEXTURE_HEIGHT * TEXTURE_SCALE_FACTOR)

typedef struct s_game
{
	int     width;
	int     height;
	int     map_width;
	int     map_height;
	float   px;
	float   py;
	float   player_angle;
	float   ray_angle;
	char	**map;
	void    *white;
	void    *blue;
	void	*mlx;
	void	*mlx_win;
	float   x_offset;
	float   y_offset;
	int     map_position;
	int     depht_of_field;
	int	 	player_speed;
	char	direction;
	int		delay;
	t_img   *mmp;
	t_img   *mmbase;
}            t_game;

// PARSER

// INIT
void	    init_vars(t_game *game);
void	    init_img(t_game *game);

// RENDER
int	        render(t_game *game);

// MINIMAP
void	    mini_map(t_game *game);
void        print_player(t_game *game);
void	    print_fov(int x0, int y0, t_game *game, int color);
void		draw_ray(int x0, int y0, int x1, int y1, t_game *game);

// KEYPRESS
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
void		press_w(float pCos, float pSin, t_game *game);
void		press_a(t_game *game);
void		press_d(t_game *game);
void		press_s(float pCos, float pSin, t_game *game);
int	        mouse_hook(int button, int x, int y, t_game *game);

// RAYCAST
void        raycast(t_game *game);

// DRAW
int			draw_vertical_line(int x, int y, int len, t_game *game, int color);
void		draw_a_line(t_game *game);
void		draw_wall(int x, int y, int len, int angle, t_game *game);

// MATH FUNCTIONS
int         ft_abs(int n);

// UTILS
int			ft_exit(t_game *game);
float   	degrees_to_radians(float degrees);
int			fix_angle(int angle);
float		distance_between_points(float x1, float y1, float x2, float y2);
void		free_matrix(char **matrix);
void		*ft_memset(void *str, int c, size_t n);

#endif