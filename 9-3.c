#include <stdio.h>
#include <math.h>
int main()
{
    int chicken,rabbit,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    chicken=(4*n-m)/2;
    rabbit=n-chicken;
    printf("%d %d\n",chicken,rabbit);
    return 0;
}
