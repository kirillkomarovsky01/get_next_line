#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_break_line(char *str)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		all_len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	all_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * all_len);
	if (!(res))
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	ft_free(s1);
	return (res);
}

char	*ft_get_line(char *str)
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

char	*ft_get_temp(char *str)
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
