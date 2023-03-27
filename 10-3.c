#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[30];
    int n,b[128]={0},k;
    scanf("%s",&a);
    n=strlen(a);
    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(int t=127;t>=0;t--)
    {
        if(b[t]!=0)
        {
            for(int k=0;k<b[t];k++)
            {
                printf("%c",t);
            }
        }
    }
    return 0;
}