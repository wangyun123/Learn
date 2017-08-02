#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "copy.h"

int main(int argc, char* argv[])
{
    int fdin = STDIN_FILENO;
    int fdout = STDOUT_FILENO;

    int i;
    for (i=1; i<argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            continue;
        }
        copy(fd, fdin);
        close(fd);
    }

    if (argc==1) copy(fdin, fdout);
    return 0;
}
