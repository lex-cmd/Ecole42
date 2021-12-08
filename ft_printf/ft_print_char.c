#include "ft_printf.h"

void	char_minus_part(t_option *opt)
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

void	char_star_part(t_option *opt)
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

void	print_c_char(va_list *arg, t_option *opt)
{
	char	type_c;

	opt->count++;
	type_c = va_arg(*arg, int);
	if (opt->minus == 1)
	{
		ft_putchar(type_c);
		char_minus_part(opt);
	}
	else if (opt->star == 1)
	{
		char_star_part(opt);
		ft_putchar(type_c);
	}
	else
		ft_putchar(type_c);
}
