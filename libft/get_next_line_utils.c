/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:25:07 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/03 16:41:33 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlengnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

int	check_gnl(char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[j])
	{
		if (i)
		{
			buf[k++] = buf[j];
		}
		if (buf[j] == '\n')
			i = 1;
		buf[j++] = 0;
	}
	return (i);
}

/*
retorna 0 quando nao encontra um \n
*/

char	*get_line(char *line, char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = line;
	line = malloc(ft_strlengnl(buf) + ft_strlengnl(line) + 1);
	if (!line)
		return (0);
	while (tmp && tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	while (*buf)
	{
		line[i++] = *buf;
		if (*buf++ == '\n')
			break ;
	}
	line[i] = '\0';
	if (tmp)
		free (tmp);
	return (line);
}

/*
A B C \n D E

0 0 0 0 
D 0 0 0 0 E
D E 0 0 0 0
i = 1;
*/
