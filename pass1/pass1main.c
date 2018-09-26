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

    tf=fopen(tar,"w");

    char buf1[100];

    len=countlen(sf);


    fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);//reading first line

    if((strcmp(opcd,str))==0){
        quoint = contoint(oprd);

        startaddr = quoint;
        LOCCTR=startaddr;

        fprintf(tf,"\n\t%s\t%s\t%s\n",label,opcd,oprd);
        fprintf(tf,"%X\t",LOCCTR);


    }
    else{
            LOCCTR = 0;
             startaddr=LOCCTR;

             fprintf(tf,"\n\t%s\t%s\t%s\n",label,opcd,oprd);
                fprintf(tf,"%X\t",LOCCTR);
        }

       //reading second line
        fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);

    while (strcmp(opcd,"END")!=0)
     {

            if(strcmp(label,"-")!=0 )
            {

                if(symsearch(syms,label)==1){
                   printf("\nSymtab error..duplicate symbol\n");
                    errflag=1;
                }else{
                    fprintf(sym,"%X\t%s\n",LOCCTR,label);
                }
            }

                if((a=opsearch(ops,opcd))==1 || (a=opsearch(ops,opcd))==2 ){
                                 if(a==2){
                                   LOCCTR=LOCCTR-3;

                                 }
                                  LOCCTR=LOCCTR+3;

                           if(strcmp(opcd,"WORD")==0){

                               LOCCTR=LOCCTR+3;

                            }
                            else if(strcmp(opcd,"RESW")==0){


                                inint=atoi(oprd);
                                LOCCTR+=(3*(inint));

                            }
                            else if(strcmp(opcd,"RESB")==0){
                                inint=atoi(oprd);
                               LOCCTR+=(inint);
                            }

                            else if(strcmp(opcd,"BYTE")==0){
                                if(oprd[0] == 'C')
                                {

                                    len11=(strlen(oprd)-3);
                                }
                                else if(oprd[0] == 'X')
                                    {
                                    len11=((strlen(oprd)-3)/2);
                                }

                              LOCCTR=LOCCTR+len11;

                            }


                }else{
                    printf("\noptab error..invalid operation code\n");
                    errflag=1;

                }


                    fprintf(tf,"%s\t%s\t%s\n",label,opcd,oprd);
                    fprintf(tf,"%X\t",LOCCTR);


                    fscanf(ff,"%s\t%s\t%s",label,opcd,oprd);

        }//while
        fprintf(tf,"%s\t%s\t%s\n",label,opcd,oprd);

        programlen=LOCCTR-startaddr;
        printf("The Program length = %d",programlen);

    fclose(ff);
    fclose(tf);
    fclose(op);
    fclose(sym);

    disp(tar);

}
