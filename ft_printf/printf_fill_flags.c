#include "ft_printf.h"

void	str_fill_acc(t_option *opt)
{
	int	ac;

	ac = 0;
	while (opt->accuracy != ac && opt->prepare[ac])
	{
		ft_putchar(opt->prepare[ac]);
		ac++;
	}
}

void	update_option(t_option *opt)
{
	if (opt->accuracy < 0)
	{
		opt->dot = 0;
		opt->accuracy = 0;
	}
	if (opt->dot)
		opt->zero = 0;
	if (opt->minus)
		opt->zero = 0;
}

void	fill_flags(char c, int begin, int end, t_option *opt)
{
	int	i;

	i = 0;
	while (begin + i < end)
	{
		ft_putchar(c);
		i++;
		opt->count++;
	}
}

void	flags_patch(t_option *opt)
{
	opt->prec = opt->accuracy - opt->lenf;
	if (opt->prec < 0)
		opt->prec = 0;
	if (opt->prec + opt->lenf + opt->sign > opt->width)
		opt->width = opt->lenf + opt->prec + opt->sign;
	if (opt->minus)
	{
		opt->begin = 0;
		opt->end = opt->width - opt->sign - opt->prec - opt->lenf;
	}
	if (opt->zero && !(opt->minus))
	{
		opt->begin = 0;
		opt->end = 0;
		opt->prec = opt->width - opt->sign - opt->lenf;
	}
	else if (!(opt->minus))
	{
		opt->begin = opt->width - opt->sign - opt->prec - opt->lenf;
		opt->end = 0;
	}
}

void	check_sign(t_option *opt, va_list *arg)
{
	int	tmp;

	tmp = (int)va_arg(*arg, unsigned int);
	if (tmp < 0)
	{
		opt->sign = 1;
		opt->nbr = -tmp;
	}
	else
		opt->nbr = tmp;
}
