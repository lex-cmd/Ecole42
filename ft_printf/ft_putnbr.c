#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
}

void	ft_unsigputnbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
}

int	ft_putbase(unsigned long nbr, size_t len_s, char *str)
{
	if (nbr < len_s)
		return (ft_putchar_fd(str[nbr], 1));
	return (ft_putbase(nbr / len_s, len_s, str)
		+ ft_putchar_fd(str[nbr % len_s], 1));
}
