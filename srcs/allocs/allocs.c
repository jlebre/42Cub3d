/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:27:00 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/26 17:55:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocs.h>
#include "printf_fd.h"

/*
	It will free a matrix
*/
void	free_matrix(void **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	matrix = NULL;
}

/*
	It will free an array
*/

void	free_array(void *array)
{
	if (!array)
		return ;
	free(array);
	array = NULL;
	array = NULL;
}

/*
	Allocates a memory a sets all bytes to 0
*/
void	*ft_calloc(size_t size)
{
	void	*ptr;
	size_t	i;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (ptr);
	i = -1;
	while (++i < size)
	{
		((char *)ptr)[i] = 0;
		printf_fd(1, "%c", ((char *)ptr)[i]);
	}
	return (ptr);
}

/*
	Calls a struct with functions for allocation and deallocates memory
*/

t_allocs	alloc(void)
{
	static t_allocs	allocs = {
		ft_calloc, free_matrix, free_array
	};

	return (allocs);
}
