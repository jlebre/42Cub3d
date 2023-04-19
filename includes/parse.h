/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:27:19 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/18 22:53:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <get_next_line.h>
# include <cub3d.h>

typedef struct s_parse	t_parse;

struct s_parse
{
	char	**file;
	char	**path_to_img;
	int		num_vars;
};

void	print_parse(t_cub *data, t_parse *parse);
void	free_parse(t_parse *parse);
void	exit_parse(t_cub *data, int status, char *str, t_parse *parse);
void	verify_paths(t_cub *data, char **path);
int		get_vars(t_cub *data, t_parse *parse);
void	parse_file(t_cub *data, t_parse *parse);

#endif
