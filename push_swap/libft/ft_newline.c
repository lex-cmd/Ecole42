#include "libft.h"

char	*ft_newline(size_t size_str)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size_str + 1));
	if (str == NULL)
		return (NULL);
	while (size_str > 0)
		str[size_str--] = '\0';
	str[0] = '\0';
	return (str);
}
