#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_option
{
	int				count;
	int				lenf;
	int				zero;
	int				minus;
	int				digit;
	int				star;
	int				dot;
	int				width;
	int				accuracy;
	int				sign;
	int				prec;
	int				begin;
	int				end;
	unsigned int	nbr;
	unsigned long	nbr_p;
	char			*prepare;
	char			*format;
	char			type;
}		t_option;

void	flags_p_patch(t_option *opt);
void	check_acc(t_option *opt);
void	space_skip(char *format, size_t *len, t_option *opt);
void	ft_unsigputnbr(unsigned int n);
void	fill_flags(char c, int begin, int end, t_option *opt);
void	update_option(t_option *opt);
void	flags_patch(t_option *opt);
int		ft_unsnbrlen(unsigned int n);
void	ft_input(va_list *arg, char *format, t_option *opt);
void	ft_output_types(va_list *arg, char *format, t_option *opt, size_t *len);
void	print_unsint(va_list *arg, t_option *opt);
int		ft_putchar_fd(char c, int fd);
void	print_percent(t_option *opt);
int		ft_nbrlen_base(unsigned long n);
void	minus_part_width(t_option *opt);
int		ft_putbase(unsigned long nbr, size_t b_len, char *base);
void	print_xX_nbr(va_list *arg, t_option *opt);
void	str_fill_acc(t_option *opt);
void	di_nbr_sign(t_option *opt);
void	check_sign(t_option *opt, va_list *arg);
void	print_di_digit(va_list *arg, t_option *opt);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	print_s_str(va_list *arg, t_option *opt);
void	print_c_char(va_list *arg, t_option *opt);
void	print_di_nbr(va_list *arg, t_option *opt);
void	print_xX_nbr(va_list *arg, t_option *opt);
void	print_p(va_list *arg, t_option *opt);
int		ft_printf(const char *format, ...);
void	general_parsing(va_list *arg, char *format, t_option *opt, size_t *len);
void	zero_minus(char *format, t_option *opt, size_t *len);
void	dot_digit(va_list *arg, char *format, t_option *opt, size_t *len);
int		ft_istype(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(const char c);
int		ft_isdigit(int c);
int		ft_nbrlen(int n);

#endif