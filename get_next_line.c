#include "get_next_line.h"

int	from_tail(char **line, char **tail, int *t)
{
	int i;
	int j;

	if (!(*tail))
		return (0);
	i = *t;
	while ((*tail)[i] && (*tail)[i] != '\n')
		i++;
	*line = malloc(i - *t + 1);
	if (!(*line))
		return (-1);
	j = 0;
	while (*t < i)
		(*line)[j++] = (*tail)[(*t)++];
	(*line)[j] = 0;
	if ((*tail)[*t] == '\n')
	{
		(*t)++;
		return (1);
	}
	*t = 0;
	free(*tail);
	*tail = NULL;
	return (0);
}

int	add_buf(char **str, char *buf)
{
	char	*tmp;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (*str && (*str)[i])
		i++;
	j = 0;
	while (buf[j])
		j++;
	tmp = malloc (i + j + 1);
	if (!tmp)
		return (-1);
	tmp[i + j] = 0;
	while (j-- > 0)
		tmp[i + j] = buf[j];
	while (*str && i-- > 0)
		tmp[i] = (*str)[i];
	if (*str)
		free(*str);
	*str = tmp;
	return (0);
}

int	get_new_heap(char **line, char **tail, int fd)
{
	char	*buf;
	ssize_t	i;
	ssize_t	r;

	if (buf_malloc(&buf, BUFFER_SIZE + 1))
		return (-1);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		r = read(fd, buf, BUFFER_SIZE);
		i = 0;
		while (i < r && buf[i] != '\n')
			i++;
		buf[i] = 0;
		if (r < 0 || add_buf(line, buf))
			return (clean_all(&buf, &buf, &fd));
		if (i < r)
		{
			buf[r] = 0;
			if (add_buf(tail, &buf[i + 1]))
				return (clean_all(&buf, &buf, &fd));
		}
	}
	free(buf);
	return (0);
}

int    get_new(char **line, char **tail, int fd)
{
    ssize_t i;
    ssize_t r;
    char    buf[BUFFER_SIZE + 1];

    i = BUFFER_SIZE;
    while (i == BUFFER_SIZE && BUFFER_SIZE > 0)
    {
        r = read(fd, buf, BUFFER_SIZE);
        i = 0;
        while (i < r && buf[i] != '\n')
            i++;
        buf[i] = 0;
        if (r < 0 || add_buf(line, buf))
            return (-1);
        if (i < r)
        {
            buf[r] = 0;
            if (add_buf(tail, &buf[i + 1]))
                return (-1);
        }
    }
    return (0);
}

int	get_next_line(int fd, char **line)
{
    static int    t;
	static char	*tail;
	int		n;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	n = from_tail(line, &tail, &t);
	if (n == 1)
		return (1);
	if (n == -1)
		return (clean_all(line, &tail, &t));
	if (BUFFER_SIZE > 4096)
		n = get_new_heap(line, &tail, fd);
	else
		n = get_new(line, &tail, fd);
	if (n)
		return (clean_all(line, &tail, &t));
	if (!tail)
		return (0);
	return (1);
}
