#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int	clean_all(char **line, char **tail, int *t);
int	from_tail(char **line, char **tail, int *t);
int	add_buf(char **str, char *buf);
int	buf_malloc(char **buf, size_t size);
int	get_new_heap(char **line, char **tail, int fd);
int	get_new(char **line, char **tail, int fd);
int	get_next_line(int fd, char **line);
#endif
