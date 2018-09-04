#include <stdio.h>
#include <stdlib.h>

int main()
{
int num =0;
//char word[2000];
char *str;
FILE * file_ptr = NULL;
//FILE *in_file = fopen("F:\\akshay\\tokenfile\\in.txt", "");
file_ptr =fopen("F:\\akshay\\tokenfile\\in.txt", "r");
if (file_ptr == NULL)
{
    printf("Error file missing\n");
    return(0);
}

//scanf("%s",word);

//printf("%s\n", word);

while(!feof(file_ptr))//this loop searches the for the current word
{
    fscanf(file_ptr,"%s",str);
    printf("%s\n",str);
    //if(!strcmp(string,word))//if match found increment num
    num++;
}
printf("No. of tokens in the file is %d times\n",num );
return 0;
}
