#include<stdio.h>
#include<string.h>
#include"search.h"

void comp(char str[])
{
    FILE *ff;
     char ch;
     int len,res=-1,res1=-2;
    char sf[30]="SIC_FirstCol.txt";
    ff=fopen(sf,"r");
    if (ff == NULL)
    {
    printf("I couldn't open.\n");
    exit(0);
    }
    len=countlen(sf);
    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

           //strcpy(buf1,buf);
            if(strlen(buf)<len){
         //sscanf(buf, "%s", col1);
         //fprintf(tf, "%s\n", col1);
            }
         else{
            sscanf(buf, "%s\t%s", col1, col2);
           res=strcmp(str,col2);
           if(res==0)
           {
                printf("String: %s is found\n",str);
                res1=0;
           }
         }

     }
    if(res1==-2)
    {
        printf("String: %s was not found\n",str);
    }
    fclose(ff);
}
