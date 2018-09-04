#include<stdio.h>
#include"search.h"
int countlen(char sf[])
{
    int count=0;
    int mac=0;
    char c;
    //char sf[30]="out1.txt";
    FILE *t = fopen(sf,"r");
    while ((c=fgetc(t))!=EOF)
    {
        if(c=='\n')
        {
            if(count>mac){mac=count;}
            count=0;
        }
        count=count+1;


    }
   // printf("count: %d\n",mac);
    fclose(t);
    mac=mac-5;
    return(mac);


}
