#include<stdio.h>
#include"pass2.h"

int contoint(char quostr[])
{
    unsigned long mult = 1;
    unsigned long re = 0;
    int i;
    int len = strlen(quostr);
    for(i = len -1 ; i >= 0 ; i--)
    {
        re = re + ((int)quostr[i] -48)*mult;
        mult = mult*10;
        }
    return re;
}
