#include <stdio.h>
#include <math.h>
int main()
{
    double s;
    for(int i=2;i<=1000;i++)
    {
        s+=log10(i);
    }
    printf("%d",(int)ceil(s));
    return 0;
}