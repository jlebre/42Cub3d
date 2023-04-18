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
typedef struct s_proj		t_proj;

struct s_cp
{
	char		**map;
	int			height;
};

struct	s_map
{
	char		**map;
	int			num_player;
	int     	width;
	int     	height;
};

struct	s_img
{
	void		**img;
	t_img_mlx	*NO_tex;
	t_img_mlx	*SO_tex;
	t_img_mlx	*WE_tex;
	t_img_mlx	*EA_tex;
	t_img_mlx	*chess;
	t_img_mlx	*floormm;
	t_img_mlx	*heart;
	t_img_mlx	*settings;
	t_img_mlx	*compass[8];
	int			colors[2];
	char		order[5];
};

struct s_parse
{
	char		**file;
	char		**path_to_img;
	int			num_vars;
};

struct s_proj
{
	int 		scale;
	int			widht;
	int			height;
	int 		half_width;
	int 		half_height;
	float 		increment;
};


struct s_game
{
	float   	player_angle;
	float   	ray_angle;
	void    	*white;
	void    	*blue;
	void    	*black;
	int     	map_position;
	int     	depht_of_field;
	int	 		player_speed;
	int			delay;
	int			fov_on;
	int			map_on;
	int			pause;
	int			lights;
	int			textures_on;
	int			lifes;
	t_img_mlx	*fov;
	t_img_mlx   *mmp;
	t_img_mlx   *mmbase;
	t_img_mlx   *mini;
	t_img_mlx   *mpause;
	t_img_mlx   *bordamm;
};

struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	char		**file;
	int			width;
	int			height;
	char		direction;
	float   	px;
	float   	py;
	int			num_player;
	int			side;
	t_img_mlx	*screen;
	t_img		img;
	t_map		map;
	t_game		game;
	t_proj		projection;
};

t_cub		*cub(void);

// INIT
void	    init_vars(t_cub *cub);
void	    init_img(t_cub *cub);
void		init_textutes(t_cub *cub, char **path);

// RENDER
int	        render(t_cub *cub);
void		print_compass(t_cub *cub);

// MINIMAP
void		init_mini_map(t_cub *cub);
void	    mini_map(t_cub *cub);

// FOV
void		init_fov(t_cub *cub);
void		draw_fov(t_cub *cub, int x, int y, int color);
void		clear_fov(t_cub *cub);
void		T_fov(t_cub *cub);

// KEYPRESS
int			key_press(int keycode, t_cub *game);
int			key_release(int keycode, t_cub *game);
void		press_ws(float p_cos, float p_sin, t_cub *cub, int keycode);
void		press_ad(t_cub *cub, int type);
void		rotate(t_cub *cub, int keycode);
int	        mouse_hook(int button, int x, int y, t_cub *cub);
void		switch_map(t_cub *cub);
int			button(int button, int x, int y, t_cub *cub);
void		pause_menu(t_cub *cub);

// RAYCAST
void        raycast(t_cub *cub);
void 		draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y);

// DRAW
void		my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int			my_mlx_pixel_get(t_img_mlx *texture, int x, int y);
void		draw_square(t_cub *cub, int x, int y, int color);
void		draw_vertical_line(float x, float y, float len, t_cub *cub, int color);
void		draw_texture(int x, int y, float len, t_cub *cub, float wall_x, float ray_x, float ray_y);
void		draw_texture2(int x, int y, float len, t_cub *cub, float wall_x, t_img_mlx *texture, float ray_x);
void		draw_texture3(int x, int y, float len, t_cub *cub, float wall_x, t_img_mlx *texture, float ray_x);
void		get_pixel(t_cub *cub, int x, int y);
void		clear_screen(t_cub *cub);
void		draw_pixel(t_cub *cub, int x, int y, int color);

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
void		load_imgs(t_cub *data, char **path);
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