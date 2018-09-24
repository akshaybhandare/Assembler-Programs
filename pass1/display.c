#include<stdio.h>
#include"pass1.h"
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
