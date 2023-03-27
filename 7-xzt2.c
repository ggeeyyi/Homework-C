#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,n,tot=0;
    printf("please input a,b,n:");
    scanf("%d %d %d",&a,&b,&n);
    for(int i=1;i<=n;i++)
    {
        tot+=a*b;
        a-=2;
        b+=2;
    }
    printf("the all number of cans is:%d",tot);
    return 0;
}