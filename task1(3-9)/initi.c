#include<stdio.h>
#include"startk.h"


void initial(char tar[],int quotient)
{

    char c;

//    char str = hexadecimalnum;
    FILE *tr = fopen(tar,"a+");
    char sf[30]="in.txt";
    FILE *sr = fopen(sf,"r");
    printf("Target file opened.....\n");

    fprintf(tr, "\n%X\t",quotient);
   // k=k+3;
     while((c=fgetc(sr))!=EOF)
     {
        fputc(c,tr);

         if(c=='\n')
         {
        fprintf(tr, "\t");
        }

    }



    fclose(tr);
    fclose(sr);
}
