#include<stdio.h>
#include"pass1.h"

int opsearch(char tar[],char optosch[])
{


    FILE *ff;
     char ch;
     int found=-2;
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

           if(strcmp(optosch,col1)==0)
           {
               // printf("String: %s is found in optab\n",optosch);
                found=1;
                return(1);
           }
     }
    if(found==-2)
    {
        if(strcmp(optosch,"WORD")==0 ||strcmp(optosch,"BYTE")==0 ||strcmp(optosch,"RESW")==0 ||strcmp(optosch,"RESB")==0 ){
                   // printf("String: %s may be a assembler directive\n",optosch);
                    return(2);

                }
        printf("String: %s was not found in optab\n",optosch);
        return(0);
    }
    fclose(ff);



}

