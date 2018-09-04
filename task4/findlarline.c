#include<stdio.h>
#include "task4.h"
#include<string.h>

int getlarline(char sf[])
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

       // while(c != EOF && c != '\n'){
        //count = count + 1;}
    }
    printf("count: %d\n",mac);
    fclose(t);
    mac=mac-4;
    return(mac);

}
