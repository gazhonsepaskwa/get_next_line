#include "get_next_line.h"

static int	find_nl(str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		*str++;

	}
	return(0);
}

static int	get_trailing(char *str, int lenstr, char *ret)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n' || i < lenstr)
		i++;
	i++;
	while(i <= lenstr)
		ret[j++] = str[i++];
	ret[i] = 0;
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
	while (mas[i])
		ret[j++] = mas[i++];
	i = 0;
	while (s2)
		ret[j++] = s2[i++];
	ret[j] = 0;
	free(mas);	
}

char	*get_next_line(int fd)
{
	char		*buffer[BUFFER_SIZE];
	char		*byte_read;
	char		*out;
	static char	*rest_from_last[50000]; // change this ?
	static int	after_nl;

	if (rest_from_last != NULL)
		out = ft_add_to_str(out, rest_from_last, (after_nl - 1));
	buffer[0] = 0;
	while (!find_nl(buffer))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		out = ft_add_to_str(out, buffer, byte_read);
		// add something for the null terminator ?
	}
	after_nl = get_trailing(buffer, byte_read, rest_from_last);
}
