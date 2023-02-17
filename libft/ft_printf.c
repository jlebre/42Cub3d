/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:13:22 by jlebre            #+#    #+#             */
/*   Updated: 2022/02/16 20:48:30 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char **c, va_list arg)
{
	if (**c == 'c')
		return (ft_putchar_fd_pf(va_arg(arg, int), 1));
	else if (**c == 's')
		return (ft_putstr_fd_pf(va_arg(arg, char *), 1));
	else if (**c == 'p')
		return (ft_putpointer_fd(va_arg(arg, unsigned long), 1));
	else if (**c == 'd')
		return (ft_putnbr_fd_pf(va_arg(arg, int), 0, 1));
	else if (**c == 'i')
		return (ft_putnbr_fd_pf(va_arg(arg, int), 0, 1));
	else if (**c == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int), 1));
	else if (**c == 'x')
		return (ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789abcdef", 0, 1));
	else if (**c == 'X')
		return (ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789ABCDEF", 0, 1));
	else if (**c == '%')
		return (ft_putchar_fd_pf(**c, 1));
	else
		return (1);
}

static int	ft_main(va_list arg, char *c)
{
	int	counter;

	counter = 0;
	while (*c)
	{
		if (*c == '%')
		{
			c++;
			if (ft_strchr_pf("cspdiuxX%", *c))
				counter += check(&c, arg);
			else
				return (counter);
		}
		else
			counter += write(1, c, 1);
		c++;
	}
	return (counter);
}

int	ft_printf(const char *c, ...)
{
	va_list	arg;
	int		counter;

	if (!c)
		return (-1);
	counter = 0;
	va_start(arg, c);
	counter = ft_main(arg, (char *)c);
	va_end(arg);
	return (counter);
}
