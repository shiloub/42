#include <stdio.h>
#include "get_next_line.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char	*s;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	// printf("%s\n", s);
	// s = get_next_line(1);
	// printf("%s\n", s);
	while (s = get_next_line(fd))
		printf("%s", s);
	return 0;
}
