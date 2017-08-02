#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "copy.h"

int main(int argc, char* argv[])
{
    if (argc<3)
    {
        printf("usage: mycp filesrc filedes\n");
        exit(1);
    }

    int fdsrc = open(argv[1], O_RDONLY);
    if (fdsrc == -1)
    {
        perror("open");
        exit(1);
    }

    int fddes = open(argv[2], O_WRONLY|O_CREAT);
    if (fddes == -1)
    {
        perror("open");
        exit(1);
    }

    copy(fdsrc, fddes);

    close(fdsrc);
    close(fddes);

    return 0;
}
