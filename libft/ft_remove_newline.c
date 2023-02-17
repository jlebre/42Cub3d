/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:37:19 by marvin            #+#    #+#             */
/*   Updated: 2022/06/12 13:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counter(char *str)
{
	int	i;
	int	counter;

	if (!str)
		return (0);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	return (counter);
}

void	ft_remove_newline(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	if (ptr)
	{
		*ptr = '\0';
	}
}
