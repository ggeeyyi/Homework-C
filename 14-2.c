#include<stdio.h>
#include<ctype.h>

int main()
{
	FILE* fp = fopen("upper.txt", "w+");
	if (fp == NULL) 
    { 
        printf("cannot open"); 
        return -1;
         }
	char c = 0;
	while (1) 
    {
		c = getchar();
		if (c == '#')
            break;
		if (islower(c))c=toupper(c);
		    fputc(c, fp);
	}
	fclose(fp);
	char x = 0;
	FILE* fp0 = fopen("upper.txt", "r");
	while (1) 
    {
		x=fgetc(fp0);
		printf("%c", x);
		if (x == EOF)
            break;
	}
	fclose(fp0);
}