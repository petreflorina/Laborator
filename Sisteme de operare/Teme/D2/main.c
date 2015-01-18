#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

long sum = 0;

int fileinfo(const char *nf)
{
    struct stat s;

    if(stat(nf,&s)==-1)return -1;

    if((s.st_mode & S_IFMT) == S_IFREG)
    {
    //    printf("<file>");
        sum = sum + (long)s.st_size;
    }
    else if((s.st_mode & S_IFMT) == S_IFDIR)
    {
  //      printf("<DIR> %s\n",nf);
        if(nf[strlen(nf)-1] != '.')
        {
            listdir(nf);
        }

    }

//    printf(" %s\n",nf);
    return 0;
}

int listdir(const char *nf)
{
    DIR *pd;
    struct dirent *pde;
    char cale[256], specificator[256];

    if((pd=opendir(nf))==NULL)return -1;

    strcpy(cale, nf);
    strcat(cale,"/");

    while((pde=readdir(pd))!=NULL)
    {
        strcpy(specificator, cale);
        strcat(specificator, pde->d_name);
        if(fileinfo(specificator)==-1)perror(specificator);
    }

    closedir(pd);
    return 0;
}


int main(int argc, char* argv[])
{

    listdir(argv[1]);
    printf("Suma este %d bytes\n",sum);
    return 0;
}
