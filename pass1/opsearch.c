#include<stdio.h>
#include"pass1.h"

int opsearch(char tar[],char optosch[])
{


    FILE *ff;
     char ch;
     int len,res=-1,res1=-2;
    ff=fopen(tar,"r");
    if (ff == NULL)
    {
    printf("I couldn't open.\n");
    exit(0);
    }
    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

            sscanf(buf, "%s\t%s", col1, col2);
           res=strcmp(optosch,col1);
           if(res==0)
           {
                printf("String: %s is found in optab\n",optosch);
                res1=0;
                return(1);
           }


     }
    if(res1==-2)
    {
        printf("String: %s was not found in optab\n",optosch);
        return(0);
    }
    fclose(ff);



}

