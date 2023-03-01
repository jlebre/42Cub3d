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
# include "libft/libft.h"

# define BUFFER_SIZE 42
# define PI 3.14159265359
# define PI2 6.28318530718
# define FOV 60
# define FOV2 30
# define SIZE_X 64
# define SIZE_Y 64

typedef struct s_cub		t_cub;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_game		t_game;
typedef struct s_cp			t_cp;
typedef struct s_parse		t_parse;

struct s_cp
{
	char	**map;
	int		height;
};

struct	s_map
{
	char	**map;
	int		num_player;
};

struct	s_img
{
	void	**img;
	int		colors[2];
	char	order[5];
};

struct s_parse
{
	char	**file;
	char	**path_to_img;
	int		num_vars;
};

struct s_game
{
	float   player_angle;
	float   ray_angle;
	void    *white;
	void    *blue;
	void    *black;
	int     map_width;
	int     map_height;
	int     map_position;
	int     depht_of_field;
	int	 	player_speed;
	int		delay;
	t_img_mlx   *mmp;
	t_img_mlx   *mmbase;
};

struct s_cub
{
	void	*mlx;
	void	*mlx_win;
	char	**file;
	int		width;
	int		height;
	char	direction;
	float   px;
	float   py;
	int		num_player;
	t_img	img;
	t_map	map;
	t_game	game;
};

t_cub		*cub(void);

// INIT
void	    init_vars(t_cub *cub);
void	    init_img(t_cub *cub);

// RENDER
int	        render(t_cub *cub);

// MINIMAP
void	    mini_map(t_cub *cub);

// KEYPRESS
int			key_press(int keycode, t_cub *game);
int			key_release(int keycode, t_cub *game);
void		press_w(float pCos, float pSin, t_cub *cub);
void		press_a(t_cub *cub);
void		press_d(t_cub *cub);
void		press_s(float pCos, float pSin, t_cub *cub);
int	        mouse_hook(int button, int x, int y, t_cub *cub);

// RAYCAST
void        raycast(t_cub *cub);

// DRAW
int			draw_vertical_line(int x, int y, int len, t_cub *cub, int color);

// MATH FUNCTIONS
int         ft_abs(int n);

// UTILS
int			ft_exit(t_cub *game);
float   	degrees_to_radians(float degrees);
int			fix_angle(int angle);
float		distance_between_points(float x1, float y1, float x2, float y2);
void		*ft_memset(void *str, int c, size_t n);

// PARSER
void		print_parse(t_cub *data, t_parse *parse);
void		free_parse(t_parse *parse);
void		exit_parse(t_cub *data, int status, char *str, t_parse *parse);
void		load_imgs(t_cub *data, t_parse *parse, char **path);
int			get_vars(t_cub *data, t_parse *parse);
void		parse_file(t_cub *data, t_parse *parse);
//
void		exit_free(t_cub *data, int status, char *str);
char		**parse(t_cub *data, char *name);
int			format_map(t_cub *data);
int			prep_alg(t_cub *data);
int			valid_chars(char c);
int			orientation_player(char c);
int			check_map(t_cub *data, char **path);

// CHECK MAP
int			check_map(t_cub *data, char **path);
int			orientation_player(char c);
int			valid_chars(char c);
int			check_invalid_char(t_cub *data);

// ALGORITHM
int			can_move(t_cp *cp, int x, int y);
int			prep_alg(t_cub *data);
int			do_algorithm(t_cp *cp, int x, int y);

// ALLOCS AND FREES
void		free_matrix(void **matrix);
void		free_array(void *array);
void		*ft_calloc(size_t size);
typedef struct s_allocs		t_allocs;
struct s_allocs
{
	void	*(*calloc)(size_t size);
	void	(*free_matrix)(void **matrix);
	void	(*free_array)(void *array);
};

t_allocs	alloc(void);

// PRINTF_FD
typedef unsigned long		t_lu;
typedef unsigned int		t_ui;
typedef struct s_info		t_info;
# define HEXUP 				"0123456789ABCDEF"
# define HEXLO 				"0123456789abcdef"
# define DEC				"0123456789"
# define STR				0
# define CHAR				1

struct s_info
{
	int			fd;
	int			base;
	size_t		i;
	size_t		counter;
};

int		printf_fd(int fd, const char *str, ...);

#endif