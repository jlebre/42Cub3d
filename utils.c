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

float   degrees_to_radians(float degrees)
{
    return (degrees * (PI / 180));
}

int fix_angle(int angle)
{
    //printf("angle before: %d\n", angle);
    if (angle > 359)
        angle -= 360;
    if (angle < 0)
        angle += 360;
    //printf("angle after: %d\n", angle);
    return (angle);
}