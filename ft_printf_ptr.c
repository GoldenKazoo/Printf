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

unsigned long	ft_strlen_ptr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_nbr_size_ptr(unsigned long nbr, char *base)
{
	unsigned long		i;

	i = 0;
	while (nbr >= ft_strlen_ptr(base))
	{
		nbr = nbr / ft_strlen_ptr(base);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_ptr(unsigned long nbr, char *base, int *counter)
{
	char	*nbr_base;
	int		size;
	int		base_index;

	size = ft_nbr_size_ptr(nbr, base);
	nbr_base = calloc(sizeof(char), size + 2);
	if (!nbr_base)
		return (*counter);
	while (0 <= size)
	{
		base_index = nbr % ft_strlen_ptr(base);
		nbr_base[size] = base[base_index];
		nbr = nbr / ft_strlen_ptr(base);
		size--;
	}
	ft_putstr(nbr_base, counter);
	free(nbr_base);
	return (*counter);
}

int	ft_putptr(void *ptr, int *counter)
{
	unsigned long	pointeradress;

	if (ptr == NULL)
	{
		*counter += write(1, "(nil)", 5);
		return (*counter);
	}
	*counter += write(1, "0x", 2);
	pointeradress = (unsigned long)ptr;
	ft_putnbr_base_ptr(pointeradress, "0123456789abcdef", counter);
	return (*counter);
}
