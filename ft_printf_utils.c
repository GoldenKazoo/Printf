
int	ft_putchar(char c, int  counter)
{
	counter = counter + write (1, &c, 1);
	return (counter);
}

int	ft_putstr(char *str, , int  counter)
{
	while (*str != '\0')
	{
		counter = counter + putchar (*str, counter);
		str++;
	}
	return (counter);
}

int	ft_putptr(void *ptr, int counter)
{
	char	*str;

	str = 
}
