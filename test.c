#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char	*ret;

	fd = open("foo.txt", O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
}
