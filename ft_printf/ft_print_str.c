#include "ft_printf.h"

static void	str_dot_fill_width(t_option *opt)
{
	int	width;

	if ((opt->width > opt->lenf && opt->accuracy > opt->lenf)
		|| (opt->width > opt->lenf && opt->accuracy < 0)
		|| (opt->width > opt->lenf && !opt->dot))
		width = opt->width - opt->lenf;
	else if (opt->accuracy < opt->width || opt->accuracy > opt->lenf)
		width = opt->width - opt->accuracy;
	else
		return ;
	if (width <= -1)
		return ;
	while (width)
	{
		ft_putchar(' ');
		width--;
		opt->count++;
	}
}

static void	str_part_minus(t_option *opt)
{
	if (opt->accuracy < 0 && !opt->star)
		return ;
	if (opt->accuracy < opt->lenf && opt->dot)
	{
		str_fill_acc(opt);
		if (opt->accuracy <= opt->width)
			str_dot_fill_width(opt);
	}
	else if (opt->width > opt->lenf)
	{
		ft_putstr(opt->prepare);
		str_dot_fill_width(opt);
	}
	else
		ft_putstr(opt->prepare);
}

static void	str_part_star(t_option *opt)
{
	int	width;

	if (opt->width >= opt->lenf)
	{	
		width = opt->width - opt->lenf;
		while (width)
		{
			ft_putchar(' ');
			width--;
			opt->count++;
		}
	}
}

static void	str_part_dot(t_option *opt)
{
	if (opt->accuracy < 0 && !opt->star)
	{
		ft_putstr(opt->prepare);
		return ;
	}
	if (opt->accuracy <= opt->lenf)
	{
		if (opt->accuracy <= opt->width)
			str_dot_fill_width(opt);
		str_fill_acc(opt);
	}
	else if (opt->width >= opt->lenf)
	{
		str_dot_fill_width(opt);
		ft_putstr(opt->prepare);
	}
	else
		ft_putstr(opt->prepare);
}

void	print_s_str(va_list *arg, t_option *opt)
{
	opt->prepare = va_arg(*arg, char *);
	check_acc(opt);
	if (opt->minus == 1)
		str_part_minus(opt);
	else if ((opt->star == 1 && !opt->minus && !opt->dot)
		|| (opt->width && !opt->minus && !opt->dot))
	{
		str_part_star(opt);
		ft_putstr(opt->prepare);
	}
	else if (opt->dot == 1)
		str_part_dot(opt);
	else
		ft_putstr(opt->prepare);
}
