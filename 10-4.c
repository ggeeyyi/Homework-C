#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[30],b[30];
    int m,n,p[128]={0},q[128]={0},cnt=0;
    scanf("%s",&a);
    scanf("%s",&b);
    m=strlen(a);
    n=strlen(b);
    for(int i=0;i<m;i++)
    {
        p[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        q[b[i]]++;
    }
    for(int i=0;i<130;i++)
    {
        if((p[i]==q[i])&&(p[i]!=0))
            cnt+=p[i];
    }
    if(cnt==m)
        printf("1");
    else    
        printf("0");
    return 0;
}