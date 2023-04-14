/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:19:33 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/14 16:15:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_color(t_cub *data, char *s, t_parse *parse)
{
	int	i;
	int	rgb[3];

	i = -1;
	rgb[++i] = ft_atoi(s);
	if (rgb[i] > 255 || rgb[i] < 0)
		exit_parse(data, 1, "Error during atoi", parse);
	while (++i < 3)
	{
		while (ft_isdigit(*s))
			s++;
		if (*s != ',')
			exit_parse(data, 1, "Error with formating the file.cub", parse);
		s++;
		rgb[i] = ft_atoi(s);
		if (rgb[i] > 255 || rgb[i] < 0)
			exit_parse(data, 1, "Error during atoi", parse);
	}
	i = 255;
	return (i << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static int	fill_args(t_parse *parse, char *s, int path_i, int color_i)
{
	if (ft_strncmp(s, "C", 1) && ft_strncmp(s, "F", 1))
	{
		s += 2;
		while (ft_isspace(*s))
			s++;
		parse->path_to_img[path_i] = ft_strdup_without_newline(s);
		if (!parse->path_to_img[path_i])
			return (1);
	}
	else
	{
		s += 1;
		while (ft_isspace(*s))
			s++;
		cub()->img.colors[color_i] = fill_color(cub(), s, parse);
	}
	return (0);
}

static int	find_args(t_parse *parse, char *s, char *compare)
{
	int	color_i;

	color_i = -1;
	if (!ft_strncmp(s, compare, ft_strlen2(compare, -1)))
	{
		if (!ft_strncmp(s, "C", 1))
			color_i = 1;
		else if (!ft_strncmp(s, "F", 1))
			color_i = 0;
		else
			cub()->img.order[++parse->num_vars] = compare[0];
		fill_args(parse, s, parse->num_vars, color_i);
		return (0);
	}
	return (1);
}

static int	choose_var(t_parse *parse, char *s)
{
	if (!find_args(parse, s, "NO"))
		return (0);
	if (!find_args(parse, s, "SO"))
		return (0);
	if (!find_args(parse, s, "WE"))
		return (0);
	if (!find_args(parse, s, "EA"))
		return (0);
	if (!find_args(parse, s, "F"))
		return (0);
	if (!find_args(parse, s, "C"))
		return (0);
	return (1);
}

int	get_vars(t_cub *data, t_parse *parse)
{
	int	i;
	int	j;
	int	num_vars;

	parse->path_to_img = alloc().calloc(sizeof(char *) * 5);
	if (!parse->path_to_img)
		exit_parse(data, 1, "Error with malloc", parse);
	num_vars = 0;
	i = -1;
	while (parse->file[++i] && num_vars != 6)
	{
		j = -1;
		while (parse->file[i][++j] && num_vars != 6)
		{
			if (!ft_isspace(parse->file[i][j]) && parse->file[i][j])
			{
				if (choose_var(parse, &parse->file[i][j]))
					exit_parse(data, 1, "File Not Formated corretly", parse);
				num_vars++;
				break ;
			}
		}
	}
	return (i);
}
