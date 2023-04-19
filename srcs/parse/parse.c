/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:16:51 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/18 22:53:11 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	**read_file(char **map, int fd, int counter)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		map = read_file(map, fd, 1 + counter);
	else if (!map && counter != 0)
		map = alloc().calloc((counter + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	map[counter] = str;
	return (map);
}

static int	open_file(t_cub *data, char *name)
{
	int	fd;

	fd = open(name, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		exit_free(data, 1, "The argument passed must not be a directory");
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_free(data, 1, "The argument passed must exist");
	return (fd);
}

char	**parse(t_cub *data, char *name)
{
	char	**path;
	t_parse	parse;
	int		fd;
	int		i;

	parse.file = NULL;
	parse.path_to_img = NULL;
	parse.num_vars = -1;
	i = -1;
	while (++i < 4)
		data->img.order[i] = 0;
	if (string().strncmp(string().strrchr(name, '.'), ".cub", 5))
		exit_free(data, 1, "The argument must end with .cub");
	fd = open_file(data, name);
	parse.file = read_file(NULL, fd, 0);
	close(fd);
	if (!parse.file)
		exit_free(data, 1, "The file must not be empty");
	parse_file(data, &parse);
	path = parse.path_to_img;
	parse.path_to_img = NULL;
	free_parse(&parse);
	return (path);
}
