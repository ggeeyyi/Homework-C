#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[30],b[30];
    int m,n=0;
    scanf("%s",&a);
    m=strlen(a);
    for(int i=0;i<m;i++)
    {
        if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
            {b[n]=a[i];
            n++;}
    }
    for(int i=0;i<m;i++)
    {
        if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
            {
            a[i]=b[n-1];
            n--;
            }
    }
    for(int i=0;i<m;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}