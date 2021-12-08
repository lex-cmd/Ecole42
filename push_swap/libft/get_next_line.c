#include "libft.h"

static char	*check_rem(char **rem, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (*rem)
	{
		if (ft_strchr(*rem, '\n'))
		{
			p_n = ft_strchr(*rem, '\n');
			*p_n = '\0';
			*line = ft_strdup(*rem);
			ft_strcpy(*rem, ++p_n);
		}
		else
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
		return (p_n);
	}
	else
		*line = ft_newline(0);
	return (p_n);
}

int	get_line(int fd, char **line, int byte_read, char buf[BUFFER_SIZE + 1])
{
	char			*p_n;
	char			*tmp;
	static char		*rem;

	p_n = check_rem(&rem, line);
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
			if (rem)
				free(rem);
			rem = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				byte_read;
	char			buf[BUFFER_SIZE + 1];

	byte_read = 1;
	buf[byte_read] = '\0';
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	return (get_line(fd, line, byte_read, buf));
}
