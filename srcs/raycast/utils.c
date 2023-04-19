/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:51:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/23 17:51:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	degrees_to_radians(float degrees)
{
	return (degrees * (PI / 180));
}

int fix_angle(int angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return ((float)sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
