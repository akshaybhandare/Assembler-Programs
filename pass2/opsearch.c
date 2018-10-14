#include<stdio.h>
#include"pass2.h"

int opsearch(char tar[],char optosch[])
{


    FILE *ff;
     char ch;
     int found=-2,inint;
    ff=fopen(tar,"r");
    if (ff == NULL)
    {
    printf("I couldn't open.\n");
    exit(0);
    }
    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100],col3[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

            sscanf(buf, "%s\t%s\t%s", col1,col2,col3);

           if(strcmp(optosch,col1)==0)
           {
               if(strcmp(optosch,"J")==0){
                    found=1;
                    return(60);
               }
               else if(strcmp(optosch,"COMP")==0){
                    found=1;
                    return(40);
               }

                found=1;
                return(atoi(col3));
           }

     }
    if(found==-2)
    {
                if(strcmp(optosch,"WORD")==0 ||strcmp(optosch,"BYTE")==0 ||strcmp(optosch,"RESW")==0 ||strcmp(optosch,"RESB")==0 ){
                   // printf("String: %s may be a assembler directive\n",optosch);
                   // printf("here");

                    return(-1);

                }
                //
    }
    fclose(ff);



}

