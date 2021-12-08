#include "ft_printf.h"

static void	per_minus_part(t_option *opt)
{
	int	width;

	opt->width--;
	width = opt->width;
	if (opt->width >= 1)
	{	
		while (width)
		{
			ft_putchar(' ');
			width--;
			opt->count++;
		}
	}
	else if (opt->width)
	{
		while (opt->width > 0)
		{
			ft_putchar(' ');
			opt->width--;
			opt->count++;
		}
	}
}

static void	per_fill_zero(t_option *opt)
{
	int	width;

	width = opt->width - 1;
	while (width)
	{
		ft_putnbr(0);
		width--;
		opt->count++;
	}
}

static void	per_star_part(t_option *opt)
{
	int	width;

	opt->width--;
	if (opt->width >= 1)
	{
		width = opt->width;
		while (width)
		{
			ft_putchar(' ');
			width--;
			opt->count++;
		}
	}
}

void	print_percent(t_option *opt)
{
	opt->count++;
	if (opt->minus == 1)
	{
		ft_putchar('%');
		per_minus_part(opt);
	}
	else if (opt->zero == 1)
	{
		per_fill_zero(opt);
		ft_putchar('%');
	}
	else if (opt->star == 1)
	{
		per_star_part(opt);
		ft_putchar('%');
	}
	else
		ft_putchar('%');
}
