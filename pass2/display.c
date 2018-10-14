#include<stdio.h>
#include"pass2.h"
void disp(char tar[])
{
    char c;
    FILE *tr = fopen(tar,"r");
   //  printf("\nPrinting contents of Intermediate file\n");
    printf("\n");
     while((c=fgetc(tr))!=EOF)
     {
          printf("%c",c);
     }
     fclose(tr);
}
