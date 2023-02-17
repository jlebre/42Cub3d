/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_extra1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:34:34 by jlebre            #+#    #+#             */
/*   Updated: 2022/02/24 20:34:34 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_p_fd(unsigned long n, char *base, int k, int fd)
{
	k++;
	if (n > 15)
	{
		k = ft_putnbr_p_fd(n / 16, base, k, fd);
		n %= 16;
	}
	ft_putchar_fd_pf(base[n], fd);
	return (k);
}

int	ft_putpointer_fd(unsigned long ptr, int fd)
{
	if (!ptr)
		return (write(fd, "0x0", 3));
	return (write(fd, "0x", 2) + ft_putnbr_p_fd(ptr, "0123456789abcdef", 0, 1));
}

int	ft_strchr_pf(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen_pf(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_unsigned(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb < 10)
	{
		nb += '0';
		count += ft_putchar_fd_pf(nb, 1);
	}
	else
	{
		count += ft_unsigned(nb / 10, fd);
		nb = nb % 10 + '0';
		count += ft_putchar_fd_pf(nb, fd);
	}
	return (count);
}
