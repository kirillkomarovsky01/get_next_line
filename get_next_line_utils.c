#include "get_next_line.h"

int clean_all(char **line, char **tail, int *index)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*tail)
	{
		free(*tail);
		*tail = NULL;
	}
	*index = 0;
	return (-1);
}

int	buf_malloc(char **buf, size_t size)
{
	*buf = malloc(size);
	if (!(*buf))
		return (-1);
	return (0);
}
