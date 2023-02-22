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
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "libft/libft.h"

# define BUFFER_SIZE 42
# define PI 3.14159265359
# define PI2 6.28318530718
# define PI3 4.71238898038
# define HALF_PI 1.57079632679
# define RADIAN 0.01745329251
# define FOV_ANGLE (60 * (PI / 180))
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
    float   dir_x;
    float   dir_y;
    float   player_angle;
    float   ray_angle;
    int     **map;
    void    *white;
    void    *blue;
    void	*mlx;
	void	*mlx_win;
    float   ray_x;
    float   ray_y;
    float   x_offset;
    float   y_offset;
    float   aTan;
    float   nTan;
    float   distance_H;
    float   distance_V;
    float   hx;
    float   hy;
    float   vx;
    float   vy;
    int     ray;
    int     map_x;
    int     map_y;
    int     map_position;
    int     depht_of_field;
    t_img   *mmp;
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
void	    print_fov(int x0, int y0, t_game *game);

// KEYPRESS
int			key_press(int keycode, t_game *game);
void		press_w(t_game *game);
void		press_a(t_game *game);
void		press_d(t_game *game);
void		press_s(t_game *game);

// RAYCAST
void        raycast(t_game *game);

// MATH FUNCTIONS
int         ft_abs(int n);

// UTILS
int			ft_exit(t_game *game);

#endif