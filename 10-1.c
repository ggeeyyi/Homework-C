#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char sA[30],sB[30];
    char m,n;
    int a,b,cnt,flag=0;
    scanf("%s",&sA);
    scanf("%s",&sB);
    a=strlen(sA);
    b=strlen(sB);
    for(int i=0;i<=(a-b);i++)
    {
        cnt=0;
        for(int j=0;j<=b-1;j++)
        {
            if(sA[i+j]==sB[j])
            {
                cnt++;
            }
            if((sA[i+j]!=sB[j])&&(sB[j]=='?'))
            {
                cnt++;
            }
        }
        if(cnt==b)
            {
                printf("%d ",i);
                flag=1;
            }
    }
    if(flag==0)
        printf("No match found");
    return 0;
}