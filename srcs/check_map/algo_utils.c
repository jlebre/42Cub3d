/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:46:44 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/01 01:25:34 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <cub3d.h>

static int	map_open(t_cp *cp, int x, int y)
{
	if (x - 1 == -1 || x + 1 == string().len(cp->map[y], -1) - 1)
		return (1);
	else if (y - 1 == -1 || y + 1 == cp->height)
		return (1);
	else if (string().ft_isspace(cp->map[y][x - 1]) || \
	string().ft_isspace(cp->map[y][x + 1]))
		return (1);
	else if (x >= string().len(cp->map[y - 1], -1) - 1 || \
	string().ft_isspace(cp->map[y - 1][x]))
		return (1);
	else if (x >= string().len(cp->map[y + 1], -1) - 1 || \
	string().ft_isspace(cp->map[y + 1][x]))
		return (1);
	return (0);
}

static void	algorithm(t_cp *cp, int x, int y, int *is_open)
{
	if (*is_open)
		return ;
	if (map_open(cp, x, y))
	{
		*is_open = 1;
		return ;
	}
	cp->map[y][x] = 'P';
	if (x - 1 > -1 && !*is_open && can_move(cp, x - 1, y))
		algorithm(cp, x - 1, y, is_open);
	if (x + 1 < string().len(cp->map[y], -1) - 1 && !*is_open && \
	can_move(cp, x + 1, y))
		algorithm(cp, x + 1, y, is_open);
	if (!*is_open && can_move(cp, x, y - 1))
		algorithm(cp, x, y - 1, is_open);
	if (!*is_open && can_move(cp, x, y + 1))
		algorithm(cp, x, y + 1, is_open);
	return ;
}

int	do_algorithm(t_cp *cp, int x, int y)
{
	int	i;

	i = 0;
	if (can_move(cp, x, y))
	{
		algorithm(cp, x, y, &i);
		if (i)
		{
			alloc().free_matrix((void **)cp->map);
			return (i);
		}
	}
	return (0);
}
