#include<stdio.h>
#include<string.h>
#include"startk.h"
main()
{
    FILE *ff,*tf;
    char sf[30]="in.txt",tar[30];
    char ch;
    int LOCCTR;
    int len,res=-1,temp;
    char str[10]="START";

    /* long decimalnum=4096, quotient, remainder;
    int i, j = 0;
    char hexadecimalNumber[100];*/

   // char buf1[100];
   // char buf2[100];

    ff=fopen(sf,"r");
    if (ff == NULL)
    {
    printf("I couldn't open.\n");
    exit(0);
    }

    printf("Enter the target file name\n");
    scanf("%s",tar);

    tf=fopen(tar,"a+");

    char buf1[100];

    len=countlen(sf);

    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

           strcpy(buf1,buf);
            if(strlen(buf)<len){
        // sscanf(buf, "%s", col2);
         //fprintf(tf, "%s\n", col2);
         }
         else{
          sscanf(buf, "%s\t%s", col1, col2);
        //  printf("%s\n",col2);
          res=strcmp(str,col2);
          if(res==0){

             quotient = decimalnum;



           initial(tar,quotient);
          }



     }
     }


    fclose(ff);
    fclose(tf);

    disp(tar);

}

