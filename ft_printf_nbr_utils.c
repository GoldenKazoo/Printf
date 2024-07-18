/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:10:01 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 00:10:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_nbr_size(long nbr, char *base)
{
	int		i;

	i = 0;
	while (nbr >= ft_strlen(base))
	{
		nbr = nbr / ft_strlen(base);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long nbr, char *base, int *counter)
{
	char	*nbr_base;
	int		size;
	int		base_index;

	if (nbr < 0)
	{
		nbr = nbr * (-1);
		*counter = ft_putchar('-', counter);
	}
	size = ft_nbr_size(nbr, base);
	nbr_base = calloc(sizeof(char), size + 2);
	if (!nbr_base)
		return (*counter);
	while (0 <= size)
	{
		base_index = nbr % ft_strlen(base);
		nbr_base[size] = base[base_index];
		nbr = nbr / ft_strlen(base);
		size--;
	}
	ft_putstr(nbr_base, counter);
	free(nbr_base);
	return (*counter);
}
