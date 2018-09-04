#include<stdio.h>
#include "cpy.h"
void dis(char tar[])
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
