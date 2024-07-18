/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:59:52 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 11:59:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_strlen_ptr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_nbr_size_ptr(unsigned long nbr, int base_len)
{
	int size;

	size = 1;
	while (nbr >= (unsigned long)base_len)
	{
		nbr /= base_len;
		size++;
	}
	return (size);
}

void	ft_putnbr_base_ptr(unsigned long nbr, const char *base, int base_len, int *counter)
{
	if (nbr >= (unsigned long)base_len)
		ft_putnbr_base_ptr(nbr / base_len, base, base_len, counter);
	*counter += write(1, &base[nbr % base_len], 1);
}

int	ft_putptr(void *ptr, int *counter)
{
	unsigned long pointeradress;

	if (ptr == NULL)
	{
		*counter += write(1, "(nil)", 5);
		return (*counter);
	}
	*counter += write(1, "0x", 2);
	pointeradress = (unsigned long)ptr;
	ft_putnbr_base_ptr(pointeradress, "0123456789abcdef", 16, counter);
	return (*counter);
}
