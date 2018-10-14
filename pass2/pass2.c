#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"pass2.h"
#define BUFFER_SIZE 1000
main()
{
FILE *fint,*ftab,*flen,*fsym,*tf,*opr;
int op1[10],txtlen,i,j=0,len,errflag=0,iter=0,ret1,ret2,count=0,repeat=1,cll=1;
char add[5],add1[10],label1[10],symadd[5],op[5],start[10],temp[30],line[20],label[20],mne[10],operand[10],symtab[10],opmne[10],tar[30]="out.txt",ch;
fint=fopen("Inputs\\Intermediate.txt","r");
flen=fopen("Inputs\\length.txt","r");
ftab=fopen("Inputs\\optab.txt","r");
fsym=fopen("Inputs\\symtab.txt","r");
opr=fopen("objectprogram.txt","w");


FILE * fPtr;
    FILE * fTemp;


    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];


if (fint == NULL)
    {
    printf("I couldn't open file Intermediate.txt\n");
    exit(0);
    }
    if (flen == NULL)
    {
    printf("I couldn't open file length.txt\n");
    exit(0);
    }
    if (ftab == NULL)
    {
    printf("I couldn't open file optab.txt\n");
    exit(0);
    }
    if (fsym == NULL)
    {
    printf("I couldn't open file symtab.txt\n");
    exit(0);
    }

   // printf("Enter the target file name\n");
   // scanf("%s",tar);

    tf=fopen(tar,"w");
fscanf(fint,"%s%s%s%s",add,label,mne,operand);
fprintf(tf,"-\t%s\t%s\t%s\t-\n",label,mne,operand);
if(strcmp(mne,"START")==0)
{
strcpy(start,operand);
fscanf(flen,"%d",&len);
}
fprintf(opr,"H^%s^%X^%X\nT^00%s^",label,atoi(start),len,start);
count++;
fscanf(fint,"%s%s%s%s",add,label,mne,operand);
fprintf(tf,"%s\t%s\t%s\t%s",add,label,mne,operand);  //%s\n
while(strcmp(mne,"END")!=0)
{

    if((ret1=opsearch("Inputs\\optab.txt",mne))>-2){

        ret2=symsearch("Inputs\\symtab.txt",operand);

                if(ret1==-1)
                {

                        if((strcmp(mne,"RESW")==0)||(strcmp(mne,"RESB")==0))
                        {
                            if(cll==1){
                            fprintf(opr,"\nT^");cll=0;}
                            fprintf(tf,"\t-\n");
                        }
                        if((strcmp(mne,"WORD")==0)||(strcmp(mne,"BYTE")==0))
                        {

                                if(strcmp(mne,"WORD")==0){
                                fprintf(opr,"0000%s^",operand);
                                count++;
                                fprintf(tf,"\t0000%s\n",operand);
                                }
                                else{
                                    len=strlen(operand);
                                    if(operand[0]=='C'){    //C'EOF'
                                        fprintf(tf,"\t%d%d%d\n",operand[len-(len-2)],operand[len-(len-3)],operand[len-(len-4)]);
                                        fprintf(opr,"%d%d%d^",operand[len-(len-2)],operand[len-(len-3)],operand[len-(len-4)]);
                                        count++;
                                    }else{
                                        fprintf(tf,"\t%c%c\n",operand[len-(len-2)],operand[len-(len-3)]);
                                        fprintf(opr,"%c%c^",operand[len-(len-2)],operand[len-(len-3)]);
                                        count++;
                                    }

                                }
                        }

                }

                if(ret2==-3){
                    fprintf(opr,"0000%X^",ret1);
                    count++;
             fprintf(tf,"\t0000%X\n",ret1);
                }


                if(ret2!=-3&&ret2!=-2&&ret2>0&&ret1!=-1){
                fprintf(opr,"%X%X^",ret1,ret2);
                count++;
                fprintf(tf,"\t%X%X\n",ret1,ret2);}

    }


fscanf(fint,"%s%s%s%s",add,label,mne,operand);
//if(iter>1){
fprintf(tf,"%s\t%s\t%s\t%s",add,label,mne,operand);
//fprintf(tf,"\t%d%s\n",,ret1,add1);
//}
if(count>repeat*10)
{

    fprintf(opr,"\nT^");
    repeat++;
}

ftab=fopen("optab.txt","r");
fseek(ftab,SEEK_SET,0);
}
fprintf(opr,"\nE^00%s",start);
fclose(fint);
fclose(ftab);
fclose(fsym);
fclose(flen);
//fclose(fout);
fclose(tf);
fclose(opr);



fPtr  = fopen(tar, "r");
    fTemp = fopen("replace.tmp", "w");
if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        replaceAll(buffer, "-", " ");

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
    }


    fclose(fPtr);
    fclose(fTemp);



    remove(tar);

    /* Rename temp file as original file */
    rename("replace.tmp", tar);

disp(tar);
disp("objectprogram.txt");
}


