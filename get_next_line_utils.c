#include "get_next_line.h"

char    *ft_strcut(char* str, int len_to_cut)
{
    char    *ret;
    int     lstr;
    int     i;
    
    lstr = ft_strlen(str);
    ret = malloc(lstr - len_to_cut + 1);
    i = -1;
    while(++i < (lstr - len_to_cut - 1))
        ret[i] = str[i];
    ret[i] = '\n';
    free(str);
    return (ret);
}

int	find_nt(char *str)
{
	while (*str)
	{
		if (*str == '\0')
			return (1);
		str++;
	}
	return(0);
}
