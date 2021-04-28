#include "get_next_line.h"

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*lineclean(char **line, char *line_s, int j)
{
	char	*temp;

	if (j >= 0)
	{
		line_s[j] = '\0';
		*line = (char*)ft_calloc(ft_strlen(line_s) + 1, sizeof(char));
		temp = (char*)ft_calloc(ft_strlen(&line_s[j + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, line_s, ft_strlen(line_s) + 1);
		ft_strlcpy(temp, &line_s[j + 1], ft_strlen(&line_s[j + 1]) + 1);
		free(line_s);
		line_s = NULL;
		return (temp);
	}
	*line = (char*)ft_calloc(ft_strlen(line_s) + 1, sizeof(char));
	ft_strlcpy(*line, line_s, ft_strlen(line_s) + 1);
	free(line_s);
	line_s = NULL;
	return (line_s);
}

int		new_line(char *line_s)
{
	int	i;

	i = 0;
	if (!line_s)
		return (-1);
	while (line_s[i])
	{
		if (line_s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int             get_next_line(int fd, char **line)
{
        static char             *line_s;
        char                    *buff;
        int    result;

        if (!line || fd < 0 || BUFFER_SIZE < 1)
                return (-1);
        result = 1;
        *line = NULL;
        buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
        if (!line_s)
                line_s = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
        while (result >= 1 && result <= BUFFER_SIZE && new_line(line_s) == -1)
        {
             	result = read(fd, buff, BUFFER_SIZE);
                if (result >= 1 && result <= BUFFER_SIZE && line_s)
                        line_s = strjoin(line_s, buff);
                ft_bzero(buff);
        }
        if (result >= 0 && result <= BUFFER_SIZE)
                line_s = lineclean(line, line_s, new_line(line_s));
        free(buff);
        if (result >= 1 && result <= BUFFER_SIZE)
       		 return (1);
        if (result == 0)
		return (0);
	return (-1);
}
