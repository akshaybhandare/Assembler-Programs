#include<stdio.h>
#define MAX_ROWS 60
#define MAX_COLUMNS 8
main()
{
char elements[MAX_ROWS][MAX_COLUMNS];
FILE *f2 = fopen("in.txt" , "r");
char buf[200];
if (NULL != f2)
{
    int row = 0;
    char lineBuf[500];
    while (NULL != fgets(buf, sizeof(lineBuf), f2))
    {
        int col = 0;
        // Get column elements from lineBuf here into elements[row][col]
        //  locating the next column parsing for delimiters.
        // This depends on the file format
        const char *colData = lineBuf;
        elements[row][col++] = atoi(colData);
        // ...
        row++;
    }
    fclose(f2);
}
}
