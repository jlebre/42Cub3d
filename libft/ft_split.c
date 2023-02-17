/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:39:55 by jlebre            #+#    #+#             */
/*   Updated: 2021/12/14 18:50:19 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	split2(char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static void	split1(char **arr, char *s, char c)
{
	int		i;
	int		j;
	int		curr;
	char	*str;

	i = 0;
	curr = 0;
	str = s;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			arr[curr] = malloc(sizeof(char) * (j + 1));
			if (!arr[curr])
				return ;
			split2(arr[curr], str + i, c);
			i += j;
			curr++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	words = count(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	split1(arr, (char *)s, c);
	return (arr);
}
