#include "get_next_line.h"
#include <stdio.h>

static int	find_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return(0);
}

static char	*get_trailing(char *str, int lenstr)
{
	int	i;
	int	j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	i++;
	ret = malloc(lenstr - i + 1);
	while(i <= lenstr)
		ret[j++] = str[i++];
	return (ret);
}

int	ft_strlen(char *str)
{
	int i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_add_to_str(char *mas, char *s2, int lens2)
{
	char *ret;
	int i;
	int j;

	ret = malloc(ft_strlen(mas) + lens2 + 1);
	i = 0;
	j = 0;
	while (mas && mas[i])
		ret[j++] = mas[i++];
	i = 0;
	while (i < lens2)
		ret[j++] = s2[i++];
	ret[j] = 0;
	free(mas);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int		byte_read;
	char		*out;
	static char	*rest_from_last = NULL;

	out = NULL;
	if (rest_from_last != NULL)
		out = ft_add_to_str(out, rest_from_last, ft_strlen(rest_from_last));
	buffer[0] = 0;
	while (!find_nl(buffer))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if(byte_read == 0)
			return (out);
		buffer[byte_read] = 0;
		out = ft_add_to_str(out, buffer, byte_read);
	}
	rest_from_last = get_trailing(buffer, byte_read);
	out = ft_strcut(out, ft_strlen(rest_from_last));
	return (out);
}
