

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
int main()
{
    int fd = open("test", O_RDONLY);
    while (get_next_line(fd))
        ;

}