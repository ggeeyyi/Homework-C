#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int N;
    scanf("%d",&N);
    int a[N][N],*p[N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            {
                scanf("%d",&a[i][j]);
            }
    }

    for(int i=0;i<N;i++)
    {
         p[i]=&a[i][0];
    }  
    int cnt=0;
    while(cnt<(2*N-1))
    {
        if(cnt%2==0)
        {
            printright(p,cnt,N);  
            cnt++;
        }
        if(cnt%2==1)
        {
            printleft(p,cnt,N);
            cnt++;
        }
    }
    return 0;
}
void printright(int *a[],int k,int n)
{
    for(int i=0;i<=k;i++)
    {
        if((i<n)&&((k-i)<n))
            {
                printf("%d",a[k-i][i]);
            }
    }
}
void printleft(int *a[],int k,int n)
{
    for(int i=k;i>=0;i--)
    {
        if((i<n)&&(k-i)<n)
            {
            printf("%d",a[k-i][i]);
            }
    }
}