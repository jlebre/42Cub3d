/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:16:10 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/01 01:25:53 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

typedef struct s_cp	t_cp;

struct s_cp
{
	char	**map;
	int		height;
};

int	can_move(t_cp *cp, int x, int y);
int	do_algorithm(t_cp *cp, int x, int y);

#endif
