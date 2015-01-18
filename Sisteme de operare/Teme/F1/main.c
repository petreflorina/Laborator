#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* prim(int nr){

    int i=0;

    if(nr<2) return "Nu este prim";
    else
    for(i=2; i*i<nr; i++){
        if(nr % i == 0)
            return "Nu este prim";
    }

    return "Este prim";
}

int returnCifra(char cuv){

    return (cuv - '0');
}

int charToInt(char *cuv){

    int nr=0,i;

    for(i=0; i<strlen(cuv); i++){
        nr = nr * 10 + returnCifra(cuv[i]);
    }

    return nr;
}

int main(int argc, char **argv)
{
    int nr;
    nr = charToInt(argv[1]);
    printf("%s",prim(nr));
    return 0;
}
