void	ft_output_percent(va_list va, char const str)
{
	if (*str == 'c')
		ft_putchar (va_arg(va, char));
	else if (*str ==  's')
		ft_putstr (va_arg(va, char *));
	else if (*str == 'p')
		ft_putptr (va_arg(va, void *));
	else if (*str == 'd')
		ft_putnbr (va_arg(va, int));
	else if (*str == 'i')
		ft_putnbr (va_arg(va, int));
	else if (*str == 'u')
		ft_putnbr (va_arg(va, unsigned int));
	else if (*str == 'x')
		ft_putnbrbase(va_arg(va, unsigned int), "0123456789ABCDEF");
	else if (*str == 'X')
		ft_putnbrbase(va_arg(va, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		ft_putchar('%')
}
void	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	va_start(va, start);
	{
		if (*str == '%')
		{
			str++;
			ft_output_percent(va, str)
		}
	}
}