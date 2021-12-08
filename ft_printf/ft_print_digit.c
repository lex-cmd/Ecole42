#include "ft_printf.h"

void	null_print_nbr(t_option *opt)
{
	opt->end = opt->width;
	fill_flags(' ', 0, opt->end, opt);
	opt->count--;
}

void	print_di_digit(va_list *arg, t_option *opt)
{
	check_sign(opt, arg);
	opt->lenf = ft_unsnbrlen(opt->nbr);
	opt->count += opt->lenf;
	if (opt->nbr == 0 && opt->accuracy == 0 && opt->dot)
	{
		null_print_nbr(opt);
		return ;
	}
	flags_patch(opt);
	fill_flags(' ', 0, opt->begin, opt);
	fill_flags('-', 0, opt->sign, opt);
	fill_flags('0', 0, opt->prec, opt);
	ft_unsigputnbr(opt->nbr);
	fill_flags(' ', 0, opt->end, opt);
}

void	print_unsint(va_list *arg, t_option *opt)
{
	opt->nbr = va_arg(*arg, unsigned int);
	opt->lenf = ft_unsnbrlen(opt->nbr);
	opt->count += opt->lenf;
	if (opt->nbr == 0 && opt->accuracy == 0 && opt->dot)
	{
		null_print_nbr(opt);
		return ;
	}
	flags_patch(opt);
	fill_flags(' ', 0, opt->begin, opt);
	fill_flags('0', 0, opt->prec, opt);
	ft_unsigputnbr(opt->nbr);
	fill_flags(' ', 0, opt->end, opt);
}

void	print_p(va_list *arg, t_option *opt)
{
	char	*str;

	opt->nbr_p = va_arg(*arg, unsigned long);
	opt->lenf = ft_nbrlen_base(opt->nbr_p);
	opt->lenf += 2;
	opt->count += opt->lenf;
	opt->accuracy = 0;
	str = "0123456789abcdef";
	if (opt->nbr == 0 && opt->accuracy == 0 && opt->dot)
	{
		null_print_nbr(opt);
		return ;
	}
	flags_p_patch(opt);
	fill_flags(' ', 0, opt->begin, opt);
	fill_flags('0', 0, opt->prec, opt);
	ft_putstr("0x");
	ft_putbase(opt->nbr_p, 16, str);
	fill_flags(' ', 0, opt->end, opt);
}

void	print_xX_nbr(va_list *arg, t_option *opt)
{
	char	*str;

	opt->nbr = va_arg(*arg, unsigned int);
	opt->lenf = ft_nbrlen_base(opt->nbr);
	opt->count += opt->lenf;
	if (opt->type == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (opt->nbr == 0 && opt->accuracy == 0 && opt->dot)
	{
		null_print_nbr(opt);
		return ;
	}
	flags_patch(opt);
	fill_flags(' ', 0, opt->begin, opt);
	fill_flags('0', 0, opt->prec, opt);
	ft_putbase(opt->nbr, 16, str);
	fill_flags(' ', 0, opt->end, opt);
}
