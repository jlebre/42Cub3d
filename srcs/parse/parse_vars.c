/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:19:33 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/17 13:32:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static int	fill_color(t_cub *data, char *s, t_parse *parse)
{
	int	i;
	int	rgb[3];

	i = -1;
	rgb[++i] = string().atoi(s);
	if (rgb[i] > 255 || rgb[i] < 0)
		exit_parse(data, 1, "Error during atoi", parse);
	while (++i < 3)
	{
		while (string().isdig(*s))
			s++;
		if (*s != ',')
			exit_parse(data, 1, "Error with formatting the file.cub", parse);
		s++;
		rgb[i] = string().atoi(s);
		if (rgb[i] > 255 || rgb[i] < 0)
			exit_parse(data, 1, "Error during atoi", parse);
	}
	i = 255;
	return (i << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static int	fill_args(t_parse *parse, char *s, int path_i, int color_i)
{
	char	*str;

	if (string().strncmp(s, "C", 1) && string().strncmp(s, "F", 1))
	{
		s += 2;
		str = string().trim(s, " \n\t");
		if (!str)
			return (1);
		parse->path_to_img[path_i] = string().strdup(str);
		alloc().free_array(str);
		if (!parse->path_to_img[path_i])
			return (1);
	}
	else
	{
		s += 1;
		while (string().ft_isspace(*s))
			s++;
		(this_cub())->img.colors[color_i] = fill_color(this_cub(), s, parse);
	}
	return (0);
}

static int	find_args(t_parse *parse, char *s, char *compare)
{
	int	color_i;

	color_i = -1;
	if (!string().strncmp(s, compare, string().len(compare, -1)))
	{
		if (!string().strncmp(s, "C", 1))
			color_i = 1;
		else if (!string().strncmp(s, "F", 1))
			color_i = 0;
		else
			(this_cub())->img.order[++parse->num_vars] = compare[0];
		fill_args(parse, s, parse->num_vars, color_i);
		return (0);
	}
	return (1);
}

static int	choose_var(t_parse *parse, char *s)
{
	if (!find_args(parse, s, "NO"))
		return (0);
	else if (!find_args(parse, s, "SO"))
		return (0);
	else if (!find_args(parse, s, "WE"))
		return (0);
	else if (!find_args(parse, s, "EA"))
		return (0);
	else if (!find_args(parse, s, "F"))
		return (0);
	else if (!find_args(parse, s, "C"))
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
		while (parse->file[i][++j])
		{
			if (!string().ft_isspace(parse->file[i][j]) && parse->file[i][j])
			{
				if (choose_var(parse, &parse->file[i][j]))
					exit_parse(data, 1, "File Not Formatted correctly", parse);
				num_vars++;
				break ;
			}
		}
	}
	return (i);
}
