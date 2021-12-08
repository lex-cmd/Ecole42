#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s1[size])
		size += 1;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] != c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return (&(((char *)str)[i]));
}

static char	*check_reminder(char *reminder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (reminder)
	{
		if (ft_strchr(reminder, '\n'))
		{
			p_n = ft_strchr(reminder, '\n');
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			ft_strclr(reminder);
		}
		return (p_n);
	}
	else
		*line = ft_strnew(0);
	return (p_n);
}

int	get_line(int fd, char **line, int byte_read)
{
	char			buf[BUFFER_SIZE + 1];
	char			*p_n;
	char			*tmp;
	static char		*reminder;

	p_n = check_reminder(reminder, line);
	while (!p_n && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		buf[byte_read] = '\0';
		if (byte_read == 0)
			return (0);
		if (ft_strchr(buf, '\n'))
		{
			p_n = ft_strchr(buf, '\n');
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int	byte_read;

	byte_read = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	return (get_line(fd, line, byte_read));
}
