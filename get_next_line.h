#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char    *ft_strcut(char* str, int len_to_cut);
int     ft_strlen(char *str);
int     find_nt(char *str);

#endif
