#include <stdio.h>
#include <stdlib.h>

int sumCif(int n)
{
    int sum=0;

    while(n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main(int argc, char* argv[])
{
    int s;
    s = atoi(argv[1]);

    printf("%d",sumCif(s));
    return 0;
}
