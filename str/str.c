/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:19:15 by mtavares          #+#    #+#             */
/*   Updated: 2023/03/01 02:37:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3b.h"

int	ft_strlen2(char *str, char c)
{
	int	len;

	len = -1;
	if (!str)
		return (0);
	while (str[++len] && str[len] != c)
		;
	return (len + (str[len] == c));
}
/* This function return a pointer to the last occurrence
	of the char c in a given string */

char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = ft_strlen(str, 0);
	if (!str)
		return (NULL);
	while (str[--i] != c && i > -1)
		;
	if (i == -1)
		return (NULL);
	return (&str[i]);
}

/* This function return a pointer to the first occurrence
	of the char c in a given string */

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i] != c && str[i])
		;
	if (!str[i])
		return (NULL);
	return (&str[i]);
}

/*
	Function that return true if a char is number
		if it isn't returns false
*/

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

t_str	string(void)
{
	static t_str	str = {
		ft_strlen, ft_strncmp, _atoi, ft_strchr, ft_strrchr, strtrim, isdig,
		ft_isspace, itoa, ft_substr, ft_strnstr, ft_isalnum, ft_strdup, strjoin
	};

	return (str);
}
