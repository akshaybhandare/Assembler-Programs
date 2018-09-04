#include<stdio.h>
#include "task4.h"
void disp(char tar[])
{
    char c;
    FILE *tr = fopen(tar,"r");
     printf("Printing contents of target file\n");

     while((c=fgetc(tr))!=EOF)
     {
          printf("%c",c);
     }
     fclose(tr);
}
