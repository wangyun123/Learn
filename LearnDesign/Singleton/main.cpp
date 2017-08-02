#include "singleton.h"
#include <stdio.h>

int main(void)
{
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);

    return 0;
}
