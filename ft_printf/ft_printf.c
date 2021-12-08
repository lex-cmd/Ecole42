#include "ft_printf.h"

int	ft_istype(int c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'u'
		|| c == 'i' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

t_option	fill_optnull(t_option opt)
{
	opt.zero = 0;
	opt.digit = 0;
	opt.width = 0;
	opt.minus = 0;
	opt.type = 0;
	opt.dot = 0;
	opt.star = 0;
	opt.accuracy = 0;
	opt.nbr = 0;
	opt.lenf = 0;
	opt.sign = 0;
	opt.prec = 0;
	opt.begin = 0;
	opt.end = 0;
	opt.nbr_p = 0;
	opt.prepare = NULL;
	opt.format = NULL;
	return (opt);
}

void	ft_output_types(va_list *arg, char *format, t_option *opt, size_t *len)
{
	update_option(opt);
	opt->type = format[*len];
	if (ft_istype(format[*len]) || format[*len] == '%')
	{
		if (opt->type == 'c')
			print_c_char(arg, opt);
		else if (opt->type == 's')
			print_s_str(arg, opt);
		else if (opt->type == '%')
			print_percent(opt);
		else if (opt->type == 'u')
			print_unsint(arg, opt);
		else if (opt->type == 'd' || opt->type == 'i')
			print_di_digit(arg, opt);
		else if (opt->type == 'x' || opt->type == 'X')
			print_xX_nbr(arg, opt);
		else if (opt->type == 'p')
			print_p(arg, opt);
	}
}

void	ft_input(va_list *arg, char *format, t_option *opt)
{
	size_t		len;

	len = 0;
	while (format[len])
	{
		if (format[len] == '%' && !ft_istype(format[len]))
		{
			*opt = fill_optnull(*opt);
			len++;
			if (format[len] == ' ')
				space_skip(format, &len, opt);
			general_parsing(arg, format, opt, &len);
			if (ft_istype(format[len]) == 1 || format[len] == '%')
				ft_output_types(arg, format, opt, &len);
		}
		else
		{
			opt->count++;
			ft_putchar(format[len]);
		}
		len++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_option	opt;

	opt.format = (char *)format;
	opt.count = 0;
	va_start(arg, format);
	ft_input(&arg, (char *)format, &opt);
	va_end(arg);
	return (opt.count);
}
