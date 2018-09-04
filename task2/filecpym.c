#include<stdio.h>
#include<stdlib.h>
#include "cpy.h"
main()
{
    char c;
    char srf[20] = "in.txt",tar[20];
    FILE *sr,*ta;
    int k=1000;

   // printf("Enter the file you want to open\n");
   // scanf("%s",srf);
    //srf[] = ;
    sr = fopen(srf,"r");

     printf("Enter the target file name\n");
     scanf("%s",tar);

     ta = fopen(tar,"a+");
    printf("Target file opened.....\n");
    fprintf(ta, "\n%d\t", k);
   // k=k+3;
    while((c=fgetc(sr))!=EOF)
     {
        fputc(c,ta);

         if(c=='\n')
         {

       fprintf(ta, "%d\t",(k=k+3));
      }
    }

     fclose(sr);
     fclose(ta);

     dis(tar);
}
