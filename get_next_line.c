#include "get_next_line.h"

char	*get_tmp(char *str)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!(res))
		return (NULL);
	if (i < ft_strlen(str))
		i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	ft_free(str);
	return (res);
}

char	*get_line(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!(res))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		break_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_free(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	r = 1;
	while (!break_line(tmp) && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
			return (-1);
		buff[r] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	*line = get_line(tmp);
	tmp = get_tmp(tmp);
	if (!(*line) || !(tmp))
		return (-1);
	if (r == 0)
	{
		r = ft_free(tmp);
		tmp = NULL;
		return (0);
	}
	return (1);
}
