#include<stdio.h>
#include<stdlib.h>
#include "task4.h"
#include<string.h>
main()
{
    FILE *ff,*tf;
    char sf[30]="SIC_out.txt",tar[30];
    char ch;
    int len;
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

    len=getlarline(sf);
    //printf("\nans: ",len);
    while ((ch=fgetc(ff))!=EOF)
     {
         char  buf[100],col1[100], col2[100];

         if ( fgets(buf, sizeof(buf), ff) == 0 )
            break;

           strcpy(buf1,buf);
            if(strlen(buf)<len){
         sscanf(buf, "%s", col1);
         fprintf(tf, "%s\n", col1);}
         else{
            sscanf(buf, "%s\t%s", col1, col2);
         fprintf(tf, "%s\t%s\n", col1, col2);
         }
     }




    fclose(ff);
    fclose(tf);

    disp(tar);
}


/*char buf[100], col1[100], col2[100];
       if ( fgets(buf, sizeof(buf), ff) == 0 )
        break;

        if(ch != '\t'&&buf[0]!=0)
            {
                if ( fgets(buf, sizeof(buf), ff) == 0 )
                    break;
                sscanf(buf, "%s\t", col2);
                fprintf(tf, "%s\t\n", col2);
            }
       else{
       if ( fgets(buf, sizeof(buf), ff) == 0 )
        break;
         sscanf(buf, "%s\t%s", col2, col1);
         fprintf(tf, "%s\t%s\n", col2, col1);}*/
