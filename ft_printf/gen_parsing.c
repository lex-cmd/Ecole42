#include "ft_printf.h"

void	dot_digit(va_list *arg, char *format, t_option *opt, size_t *len)
{
	opt->dot = 1;
	if (format[*len] == '*')
	{
		opt->accuracy = va_arg(*arg, int);
		(*len)++;
	}
	else if (ft_isdigit(format[*len]))
	{
		while (ft_isdigit(format[*len]))
			opt->accuracy = opt->accuracy * 10 + format[(*len)++] - '0';
	}
}

void	zero_minus(char *format, t_option *opt, size_t *len)
{
	if (format[*len] == '0' || format[*len] == '-')
	{
		if (format[*len] == '0')
		{
			opt->zero = 1;
		}
		else if (format[*len] == '-')
		{
			opt->lenf = *len;
			opt->minus = 1;
			opt->zero = 0;
		}
	}
}

void	flag_digit(char *format, t_option *opt, size_t *len)
{
	if (opt->star == 1)
		opt->width = 0;
	while (ft_isdigit(format[*len]))
	{
		opt->star = 1;
		opt->width = opt->width * 10 + format[(*len)++] - '0';
	}
}

void	flag_star(va_list *arg, char *format, t_option *opt, size_t *len)
{
	if (format[*len] == '*')
	{
		if (format[*len] == '*')
		{
			opt->width = va_arg(*arg, int);
			opt->star = 1;
			if (opt->width < 0)
			{
				opt->minus = 1;
				opt->width *= (-1);
				opt->zero = 0;
			}
		}
	}
}

void	general_parsing(va_list *arg, char *format, t_option *opt, size_t *len)
{
	while (format[*len] == '0' || format[*len] == '-')
	{
		zero_minus(format, opt, len);
		(*len)++;
	}
	if (format[*len] == '*')
	{
		flag_star(arg, format, opt, len);
		(*len)++;
	}
	else if (ft_isdigit(format[*len]))
		flag_digit(format, opt, len);
	if (format[*len] == '.')
	{
		if (format[(*len)++] == '*')
		{
			flag_digit(format, opt, len);
		}
		else
			dot_digit(arg, format, opt, len);
	}
}
