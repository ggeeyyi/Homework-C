#include <stdio.h>
#include <math.h>
int main()
{
    long long n,ns;
    long long f(long long);
    scanf("%d",&n);
    ns=n*(n+1)*(n+2)*(8*n*n+11*n+1)/120;
    printf("%d\n",f(n));
    printf("%d\n",ns);
    if(f(n)==ns)
        printf("0");
    if(f(n)>ns)
        printf("1");
    if(f(n)<ns)
        printf("-1");            
    return 0;
}
long long f(long long n)
{
    int x=0,t=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=i;k++)
        {
            t+=k*k;
        }
        x+=t*i;
        t=0;
    }
    return x; 
}