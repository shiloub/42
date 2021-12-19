#include <stdio.h>
#include "get_next_line.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    int retour;
    char str[1000];

    fd = open("text.txt", O_RDONLY);
    retour = read(fd, str, 1000);
    str[retour] = 0;
    printf("retour de read = %d et str = %s", retour, str);
    retour = read(fd, str, 1000);
    str[retour] = 0;
    printf("retour de read = %d et str = %s", retour, str);
    return 0;
}