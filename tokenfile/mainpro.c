#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "th.h"
int main(){
char ch, buffer[100];
    FILE *fp = fopen("in.txt","r");
    int j=0,i;
    char operators[] = "+-*/%=";
   // char fileb[20] = "in.txt";
   // fp = fopen(fileb,"r");

    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF){

    for(i = 0; i < 6; ++i){
               if(ch == operators[i])
                   printf("%c is operator\n", ch);
           }

           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;

                   if(isKeyword(buffer) == 1)
                       printf("%s is Keyword\n", buffer);
                   else
                       printf("%s is Indentifier\n", buffer);
           }

    }

    fclose(fp);
    return(0);
}
