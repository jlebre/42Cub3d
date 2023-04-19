/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:41:36 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/02 16:20:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static int	valid_line(char *s)
{
	int	i;

	if (string().len(s, -1) < 2)
		return (1);
	i = -1;
	while (s[++i] != '\n')
		if (s[i] > 8 && s[i] < 14)
			return (0);
	return (1);
}

static int	counting_lines(t_parse *parse, int y)
{
	int	count_lines;

	count_lines = 0;
	while (parse->file[y])
	{
		if (!valid_line(parse->file[y]))
			return (-1);
		count_lines++;
		y++;
	}
	return (count_lines);
}

void	get_map(t_cub *data, t_parse *parse, int y)
{
	int	i;
	int	num_lines;

	while (parse->file[y])
	{
		if (string().len(parse->file[y], -1) > 1)
			break ;
		y++;
	}
	num_lines = counting_lines(parse, y);
	if (num_lines == -1)
		exit_parse(data, 1, "Invalid map", parse);
	data->map.map = alloc().calloc(sizeof(char *) * (num_lines + 1));
	if (!data->map.map)
		exit_parse(data, 1, "Error malloc with map", parse);
	i = -1;
	while (parse->file[y] && valid_line(parse->file[y]))
	{
		data->map.map[++i] = string().strdup(parse->file[y]);
		if (!data->map.map[i])
			exit_parse(data, 1, "Error malloc with map", parse);
		y++;
	}
}

void	parse_file(t_cub *data, t_parse *parse)
{
	int	y;
	int	i;

	y = get_vars(data, parse);
	i = -1;
	while (parse->path_to_img[++i])
		;
	if (i != 4)
		exit_parse(data, 1, "must contain NO SO WE EA path to the files" \
		, parse);
	get_map(data, parse, y);
}
