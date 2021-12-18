#include "get_next_line.h"

int main()
{
    char *s;
    int fd;

    s = get_next_line(1);
    printf("%s\n", s);
    s = get_next_line(1);
    printf("%s\n", s);
    return 0;


}