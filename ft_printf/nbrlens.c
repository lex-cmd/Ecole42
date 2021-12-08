#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr || len == 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_unsnbrlen(unsigned int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	while (nbr || len == 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_nbrlen_base(unsigned long n)
{
	int				len;
	unsigned long	nbr;

	nbr = n;
	len = 0;
	while (nbr || len == 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}
