#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_get_temp(char *str);
char	*ft_get_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_is_break_line(char *str);
int		ft_strlen(char *str);
int		ft_free(char *str);

#endif
