#include "libft.h"

int	numstr(char const *s, char c)
{
	unsigned int	i;
	int				pass;

	pass = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			pass++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (pass);
}
