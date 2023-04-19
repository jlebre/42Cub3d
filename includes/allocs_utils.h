/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:25:50 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/30 17:26:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCS_UTILS_H
# define ALLOCS_UTILS_H

# include <stdlib.h>
# include <allocs.h>

void		free_matrix(void **matrix);
void		free_array(void *array);
void		*ft_calloc(size_t size);

#endif
