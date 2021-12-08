#include "ps.h"

long long	ft_atoll(const char *str)
{
	long				znak;
	unsigned long long	res;

	res = 0;
	znak = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		znak *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 9223372036854775807 && (znak == 1))
			return (-1);
		else if (res > 9223372036854775807 && (znak == -1))
			return (0);
		str++;
	}
	return ((long long)(res * znak));
}

void	big_error_int(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (atoll(str[i]) > 2147483647 || atoll(str[i]) < -2147483648)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

void	string_on_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	big_error_int(str);
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != '2'
				&& str[i][j] != '3' && str[i][j] != '4'
				&& str[i][j] != '5' && str[i][j] != '6' && str[i][j] != '7'
				&& str[i][j] != '8' && str[i][j] != '9'
				&& str[i][j] != ' ' && str[i][j] != '-')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
