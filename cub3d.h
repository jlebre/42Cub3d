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
# include "libft/libft.h"

# define BUFFER_SIZE 42
# define PI 3.14159265359
# define TWO_PI 6.28318530718
# define HALF_PI 1.57079632679
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
    int     **map;
    void    *white;
    void    *blue;
    void	*mlx;
	void	*mlx_win;
}            t_game;

int			key_press(int keycode, t_game *game);
int			ft_exit(t_game *game);
void	    init_vars(t_game *game);
int	        render(t_game *game);
void	    mini_map(t_game *game);
void        print_player(t_game *game);
void	    init_img(t_game *game);

#endif