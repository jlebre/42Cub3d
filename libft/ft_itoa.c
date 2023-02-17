/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:00:37 by jlebre            #+#    #+#             */
/*   Updated: 2021/12/13 13:09:42 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int a)
{
	int	counter;

	if (a <= 0)
	{
		a *= -1;
		counter = 1;
	}
	else
		counter = 0;
	while (a > 0)
	{
		a /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = count(n);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	arr[size] = '\0';
	while (n > 0)
	{
		arr[size - 1] = ((n % 10) + '0');
		n /= 10;
		size--;
	}
	return (arr);
}
