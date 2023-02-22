/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:40:07 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/31 21:15:25 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>
# include <printf_fd.h>
# include <allocs.h>
# include <str.h>

# define SIZE_X 64
# define SIZE_Y 64

typedef struct s_cub	t_cub;
typedef struct s_img	t_img;
typedef struct s_map	t_map;

struct	s_map
{
	char	**map;
	int		player_x;
	int		player_y;
	int		player_orientation;
	int		num_player;
};

struct	s_img
{
	void	**img;
	int		colors[2];
	char	order[5];
};

struct s_cub
{
	void	*mlx;
	void	*win;
	char	**file;
	t_img	img;
	t_map	map;
};

t_cub	*this_cub(void);
void	exit_free(t_cub *data, int status, char *str);
char	**parse(t_cub *data, char *name);
int		format_map(t_cub *data);
int		prep_alg(t_cub *data);
int		valid_chars(char c);
int		orientation_player(char c);
int		check_map(t_cub *data, char **path);

#endif
