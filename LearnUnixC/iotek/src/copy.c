#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "copy.h"

#define BUFFER_LENGTH 1024

void copy(int fdSrc, int fdDes)
{ 
    char* buf[BUFFER_LENGTH]={0};

    ssize_t size;
    while( (size = read(fdSrc, buf, BUFFER_LENGTH)) > 0 )
    {
        ssize_t s1 = write(fdDes, buf, size);
        if (s1 != size)
        {
            perror("write error");
            exit(1);
        }
    }
}
