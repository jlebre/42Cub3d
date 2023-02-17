/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_without_newline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:27:22 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 21:27:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_without_newline(const char *str)
{
	char	*new_str;

	ft_remove_newline((char *)str);
	new_str = ft_strdup(str);
	return (new_str);
}
