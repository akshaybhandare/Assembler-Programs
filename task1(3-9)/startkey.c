#include<stdio.h>
#include<string.h>
#include"startk.h"
main()
{
    FILE *ff,*tf;
    char sf[30]="in.txt",tar[30];
    char ch;
    char LOCCTR[20];
    int len,res=-1,temp;
    char str[10]="START";
    char quostr[20],dummy1[10],dummy2[10];
    int quoint;
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
          sscanf(buf, "%s\t%s\t%s", col1, col2,quostr);
         // sscanf(buf, "%s\t%s\t%d", dummy1, dummy2,quoint);

        //  printf("%s\n",col2);
          res=strcmp(str,col2);
          if(res==0){

                quoint = contoint(quostr);
            // printf("\nhere in str: %s",quostr);
             printf("\nReturned value of addr(int) : %d",quoint);
            // quotient = decimalnum;

           // strcat("0x",quostr);

            strcpy(LOCCTR,quostr);
            printf("\n LOCCTR value(string): %s\n\n",LOCCTR);


            initial(tar,quoint);
          }



     }
     }


    fclose(ff);
    fclose(tf);

    disp(tar);

}

