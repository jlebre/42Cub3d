/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:50:50 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/26 21:35:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static int	open_file(t_cub *data, char *name, char **path)
{
	int	fd;

	fd = open(name, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		exit_free(data, path, 1, "The argument passed must not be a directory");
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_free(data, path, 1, "The argument passed must exist");
	return (fd);
}

static int	string_unique_char(char *s)
{
	int	checker;
	int	i;

	checker = 0;
	i = -1;
	while (s[++i])
	{
		if (checker & (1 << (s[i] - 'A')))
			return (0);
		checker |= (1 << (s[i] - 'A'));
	}
	return (1);
}

void	verify_paths(t_cub *data, char **path)
{
	int	i;
	int	fd;

	if (!string_unique_char(data->img.order))
		exit_free(data, path, 1, "Has multiple imgs");
	i = -1;
	while (path[++i])
	{
		fd = open_file(data, path[i], path);
		close (fd);
	}
}
