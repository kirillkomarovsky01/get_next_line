#include "get_next_line.h"

int    clean_all(char **line, char **tail, int *t)
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
    *t = 0;
    return (-1);
}

int	buf_malloc(char **buf, size_t size)
{
	*buf = malloc(size);
	if (!(*buf))
		return (-1);
	return (0);
}
