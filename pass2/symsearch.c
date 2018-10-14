#include<stdio.h>
#include"pass2.h"
#include<stdlib.h>

int symsearch(char tar[],char labeltosch[])
{


    FILE *ff;
     char ch;
     int len,res=-1,res1=-2;

    ff=fopen(tar,"r");
    char add[30],label[30],inint[30],spl[30];

    if (ff == NULL)
    {
    printf("I couldn't open.\n");
    exit(0);
    }


     while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];
         char col3[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

            sscanf(buf, "%s\t%s\t%s", col1, col2,col3);

           if(strcmp(labeltosch,col2)==0)
           {

                return(atoi(col3));
           }
           if(strcmp("BUFFER,X",labeltosch)==0)
           {
               return(4174);
           }
           if(strcmp("-",labeltosch)==0)
           {
               return(-3);
           }
     }
    if(res1==-2)
    {

       // printf("String: %s was not found in symtab\n",labeltosch);
        return "NULL";
       // return(0);
    }
    fclose(ff);

}

