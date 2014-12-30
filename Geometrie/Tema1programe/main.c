#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=100;

    if (x!=0)
    {
        goto L1;
    }
    else
    {
        goto E;
    }

E:
    return 0;

    printf("Hello world!\n");
    return 0;
}
