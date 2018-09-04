#include<stdio.h>
#include"startk.h"
void disp(char tar[])
{
    char c;
    FILE *tr = fopen(tar,"r");
     printf("\nPrinting contents of target file\n");

     while((c=fgetc(tr))!=EOF)
     {
          printf("%c",c);
     }
     fclose(tr);
}

