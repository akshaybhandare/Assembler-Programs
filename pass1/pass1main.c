#include<stdio.h>
#include"pass1.h"
#include<string.h>
#include<stdlib.h>

main()
{
    FILE *ff,*tf,*op,*sym;
    char sf[30]="copy.txt",tar[30];
    char ops[30]="optab.txt";
     char syms[30]="symtab.txt";
    char ch;
    int LOCCTR;
    char label[50],opcd[50],oprd[50];
    int len,res=-1,temp;
    char str[10]="START";
    char quostr[20];
    int quoint,programlen;
    int startaddr,res11,res12,errflag=0,a,inint,len11;

    op=fopen(ops,"r");
    sym=fopen(syms,"w");
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

    //findung locctr
    //if length is small
     printf("\nFINDING LOCCTR..\n");
    fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);//reading first line
    if((strcmp(opcd,str))==0){
        quoint = contoint(oprd);
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

        }
       //reading second line
       fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);
       printf("%s\t%s\t%s",label,opcd,oprd);


    fprintf(tf, "\n%d\t", LOCCTR);
    while (strcmp(opcd,"END")!=0 && (ch=fgetc(ff))!=EOF)
     {

            if(strcmp(label,"-")!=0 )
            {

                /******/printf("\nSEARCHING %s IN SYMTAB..\n",label);
                if(symsearch(syms,label)==1){
                   printf("\nSymtab error..duplicate symbol\n");
                   exit(0);
                    errflag=1;
                }else{
                    fprintf(sym,"%d\t%s\n",LOCCTR,label);
                }
            }


        /******/printf("\nSEARCHING %s IN OPTAB..\n",opcd);

                if(symsearch(ops,opcd)==1){
                  printf("GETTING ADDRESS..\n\n\n");

               fputc(ch,tf);

                    if(ch=='\n')
                        {
                            //if(res12==1){
                            //fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));}
                           if((a=strcmp(opcd,"WORD"))==0){
                               fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));
                            }
                            else if((a=strcmp(opcd,"RESW"))==0){
                                inint=oprd;
                                LOCCTR=LOCCTR*inint;
                                fprintf(tf, "%d\t",LOCCTR);
                            }
                            else if((a=strcmp(opcd,"RESB"))==0){
                                inint=oprd;
                                fprintf(tf, "%d\t",(LOCCTR=LOCCTR+inint));
                            }
                            else if((a=strcmp(opcd,"BYTE"))==0){
                                if((a=strcmp(oprd[0],"C"))==0)
                                {
                                    len11=(strlen(oprd)-4);
                                }
                                else if((strcmp(oprd[0],"X")) == 0)
                                    {
                                    len11=((strlen(oprd)-3)/2);
                                }
                               fprintf(tf, "%d\t",(LOCCTR=LOCCTR+len11));
                            }
                            else{
                                fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));
                            }
                        }
                }else{
                    printf("\noptab error..invalid operation code\n");
                    errflag=1;
                    exit(0);
                }


         fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);
         printf("\n%s\t%s\t%s",label,opcd,oprd);
        }//while
        fprintf(tf, "%d\t",(LOCCTR=LOCCTR+3));
        programlen=LOCCTR-startaddr;
        printf("The Program length = %d",programlen);

    fclose(ff);
    fclose(tf);
    fclose(op);
    fclose(sym);

    disp(tar);

}
