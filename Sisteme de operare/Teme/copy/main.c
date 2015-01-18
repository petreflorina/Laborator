#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <conio.h>
#include <fcntl.h>

int main( int argc, char *argv[])
{
    int n = argc, df;

    char buffer[1];
    buffer[0] = '\0';

    df = creat(argv[n-1], S_IWRITE);

    if(df == -1)
    {
        printf("%s","Eroare la deschiderea (crearea) fisierului\n");
    }

    int i,f,g,nr;

    f = open(argv[n-1], O_WRONLY);

    for(i=1; i<n-1; i++)
    {
        if(argv[i] != '+')
        {
            g = open(argv[i],O_RDONLY);

            int p=read(g,buffer,1) ;

            while(p > 0)
            {
                write(f,buffer,1);
                p=read(g,buffer,1) ;
            }
            close(g);
        }
    }
    close(f);

    return 0;
}
