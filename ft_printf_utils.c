/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:10:15 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 00:10:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *counter)
{
	*counter = *counter + write (1, &c, 1);
	return (*counter);
}

int	ft_putstr(char *str, int *counter)
{
	if (!str)
		return (ft_putstr("(null)", counter));
	while (*str)
	{
		*counter = ft_putchar (*str, counter);
		str++;
	}
	return (*counter);
}
