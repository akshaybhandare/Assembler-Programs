#include <stdio.h>
#define MAX 50
#define MAX_COL 3
struct rowwise{
char cal[MAX_COL][20];

}row[MAX];


int main()
{
    char line[500];
    int i=0,nocol,k=2,m=4096;

    FILE *fp = fopen("s.txt", "r");
    FILE *op = fopen("out.txt", "w");
   // FILE *s = fopen("s.txt", "w");

    if (fp == NULL || op == NULL)
    {
        fprintf(stderr, "Error opening file.");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != 0)
    {
        /* Use "%*s" to skip a word when using scanf. */
        nocol=sscanf(line, "%s %s %s %s", row[i].cal[0],row[i].cal[1],row[i].cal[2],row[i].cal[3]);
        if(nocol==4){
         fprintf(op, "%s\t%s\n", row[i].cal[0],row[i].cal[1]);
        }

      /*  if(nocol==1){
            fprintf(s, "%X\t\t%s\t\n",m,row[i].cal[0]);}
        if(nocol==2){
            fprintf(s, "%X\t\t%s\t%s\n",m,row[i].cal[0],row[i].cal[1]);}
        if(nocol==3){
            fprintf(s, "%X\t%s\t%s\t%s\n",m,row[i].cal[0],row[i].cal[1],row[i].cal[2]);}*/

        i++;
        //m+=3;
    }



    /*for(k=0;k<22;k++){
         for(m=0;m<3;m++){
    printf("%s\t",row[k].cal[m]);
    }}*/
}
