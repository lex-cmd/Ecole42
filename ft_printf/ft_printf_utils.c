#include "ft_printf.h"

void	space_skip(char *format, size_t *len, t_option *opt)
{
	ft_putchar(format[*len]);
	opt->count++;
	while (format[*len] == ' ')
		(*len)++;
}

void	check_acc(t_option *opt)
{
	if (opt->prepare == NULL)
	{
		opt->prepare = "(null)";
		opt->lenf = ft_strlen("(null)");
	}
	else
		opt->lenf = ft_strlen(opt->prepare);
	if (opt->accuracy < opt->lenf && opt->dot)
		opt->count += opt->accuracy;
	else
		opt->count += opt->lenf;
}

void	flags_p_patch(t_option *opt)
{
	opt->prec = opt->accuracy - opt->lenf;
	if (opt->prec < 0)
		opt->prec = 0;
	if (opt->prec + opt->lenf > opt->width)
		opt->width = opt->lenf + opt->prec * 2;
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
