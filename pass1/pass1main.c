#include<stdio.h>
#include"pass1.h"
#include<string.h>

main()
{
    FILE *ff,*tf;
    char sf[30]="copy.txt",tar[30];
    char ops[30]="optab.txt";
     char syms[30]="symtab.txt";
    char ch;
    int LOCCTR;
    int len,res=-1,temp;
    char str[10]="START";
    char quostr[20],dummy1[10],dummy2[10];
    int quoint;
    int startaddr;

    op=fopen(ops,"r");
    sym=fopen(syms,"a+");
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


        /**********/
        /*char  buf[100],col1[100], col2[100];
        if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;*/
        /***********/

    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

           strcpy(buf1,buf);

           /********/
        if(strlen(buf)<len){
                sscanf(buf, "%s\t%s", col1,col2);
                 printf("\nFINDING LOCCTR..\n");
              res=strcmp(str,col2);
          if(res==0){

                quoint = contoint(col3);
                printf("\nReturned value of addr(int) : %d",quoint);
                printf("\nINITIALIZING LOCCTR..\n");
                LOCCTR = quoint;
                startaddr=LOCCTR;
                printf("\n LOCCTR value: %d\n\n",LOCCTR);
        }
        else{
            LOCCTR = 0;
             startaddr=LOCCTR;
             printf("\n LOCCTR value: %d\n\n",LOCCTR);
            //fputc(c,ta);
            printf("\nGETTING ADDRESSES..\n");

        }

        if(1)  //check for comment
            {
                if((strlen(col1))>=1)
                {
                    printf("\nSEARCHING IN SYMTAB..\n");
                   res11=symsearch(syms,col1);
                   if(res11==1)
                   {
                        printf("\nSymtab error..duplicate symbol\n");
                        errflag=1;
                   }
                   else{
                    fprintf(sym,"%d\t%s\n",LOCCTR,col1);
                   }


                   printf("\nSEARCHING IN OPTAB..\n");
                   res12=symsearch(ops,col2);
                   if(res12==1)
                   {
                        printf("\nGETTING ADDRESSES..\n");
                        if(c=='\n')
                        {
                            //if(res12==1){
                            //fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));}
                           if((a=strcmp(col2,"WORD"))==0){
                               fprintf(tf, "%d\t\t",(LOCCTR=LOCCTR+3));
                            }
                            else if((a=strcmp(col2,"RESW"))==0){
                                inint=col3;
                                LOCCTR=LOCCTR*inint;
                                fprintf(tf, "%d\t\t",LOCCTR);
                            }
                            else if((a=strcmp(col2,"RESB"))==0){
                                inint=col3;
                                fprintf(tf, "%d\t\t",(LOCCTR=LOCCTR+inint));
                            }
                            else if((a=strcmp(col2,"BYTE"))==0){
                                if((a=str(col3[0],"C"))==0)
                                {
                                    len11=strlen(col3)-1;
                                }
                                else((a=str(col3[0],"X"))==0){
                                    len11=(strlen(col3)-1)/2;
                                }
                               fprintf(tf, "%d\t\t",(LOCCTR=LOCCTR+len11));
                            }
                            else{
                                fprintf(tf, "%d\t\t",(LOCCTR=LOCCTR+3));
                            }
                        }

                   }
                   else{
                    printf("\noptab error..invalid operation code\n");
                        errflag=1;
                   }




                }//if label is present
            }//comment cond


            }
        else{
        /*******/

          sscanf(buf, "%s\t%s\t%s", col1, col2,col3);

           printf("\nFINDING LOCCTR..\n");
          res=strcmp(str,col2);
          if(res==0){

                quoint = contoint(col3);
                printf("\nReturned value of addr(int) : %d",quoint);
                printf("\nINITIALIZING LOCCTR..\n");
                LOCCTR = quoint;
                startaddr=LOCCTR;
                printf("\n LOCCTR value: %d\n\n",LOCCTR);
        }
        else{
            LOCCTR = 0;
             startaddr=LOCCTR;
             printf("\n LOCCTR value: %d\n\n",LOCCTR);
            //fputc(c,ta);
            printf("\nGETTING ADDRESSES..\n");

        }

            if(1)  //check for comment
            {
                if((strlen(col1))>=1)
                {
                    printf("\nSEARCHING IN SYMTAB..\n");
                   res11=symsearch(syms,col1);
                   if(res11==1)
                   {
                        printf("\nSymtab error..duplicate symbol\n");
                        errflag=1;
                   }
                   else{
                    fprintf(sym,"%d\t%s\n",LOCCTR,col1);
                   }


                   printf("\nSEARCHING IN OPTAB..\n");
                   res12=symsearch(ops,col2);
                   if(res12==1)
                   {
                        printf("\nGETTING ADDRESSES..\n");
                        if(c=='\n')
                        {
                            //if(res12==1){
                            //fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));}
                           if((a=strcmp(col2,"WORD"))==0){
                               fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));
                            }
                            else if((a=strcmp(col2,"RESW"))==0){
                                inint=col3;
                                LOCCTR=LOCCTR*inint;
                                fprintf(tf, "%d\t",LOCCTR);
                            }
                            else if((a=strcmp(col2,"RESB"))==0){
                                inint=col3;
                                fprintf(tf, "%d\t",(LOCCTR=LOCCTR+inint));
                            }
                            else if((a=strcmp(col2,"BYTE"))==0){
                                if((a=str(col3[0],"C"))==0)
                                {
                                    len11=strlen(col3)-1;
                                }
                                else((a=str(col3[0],"X"))==0){
                                    len11=(strlen(col3)-1)/2;
                                }
                               fprintf(tf, "%d\t",(LOCCTR=LOCCTR+len11));
                            }
                            else{
                                fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));
                            }
                        }

                   }
                   else{
                    printf("\noptab error..invalid operation code\n");
                        errflag=1;
                   }




                }//if label is present
            }//comment cond

        }

        if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

        }//while


     }
     }




    fclose(ff);
    fclose(tf);
    fclose(op);

    disp(tar);

}
