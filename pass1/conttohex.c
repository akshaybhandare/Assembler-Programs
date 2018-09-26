    #include<stdio.h>
    #include<pass1.h>
   char conttohex(int LOCCTR)
    {
     long decimal=LOCCTR, quotient, remainder;
     int i, j = 0;
     char hexadecimal[100];


     quotient = decimal;

     while (quotient != 0)
     {
     remainder = quotient % 16;          //step 1
     if (remainder < 10)
     hexadecimal[j++] = 48 + remainder;   //step 2
     else
     hexadecimal[j++] = 55 + remainder;   //step 3
     quotient = quotient / 16;            //step 4
     }

     printf("Equivalent hexadecimal value of decimal number %d:",decimal);

     //step 6
     for (i = j; i >= 0; i--)
     printf("%c", hexadecimal[i]);
     return 0;
    }
