#include <stdio.h>
#include <math.h>
int main(void)
{
    int m,n,d;
    scanf("%d%d",&n,&m);
    d=f(n,m);
    printf("%d\n",d+1);
    return 0;
}
int f(int n,int m)
{
    if(n==1)
        return 0;
    else
        {
        return ((f(n-1,m)+m)%n);
        }
}
