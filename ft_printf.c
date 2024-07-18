/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:10:18 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 00:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_percent(va_list va, const char *str, int *counter)
{
	if (*str == 'c')
		ft_putchar (va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr (va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr (va_arg(va, void *), counter);
	else if (*str == 'd')
		ft_putnbr_base(va_arg(va, int), "0123456789", counter);
	else if (*str == 'i')
		ft_putnbr_base(va_arg(va, int), "0123456789", counter);
	else if (*str == 'u')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789", counter);
	else if (*str == 'x')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789abcdef", counter);
	else if (*str == 'X')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789ABCDEF", counter);
	else if (*str == '%')
		ft_putchar('%', counter);
	return (*counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			counter = ft_output_percent(va, str, &counter);
		}
		else
		{
			counter = ft_putchar(*str, &counter);
		}
		str++;
	}
	va_end(va);
	return (counter);
}
