#include <stdio.h>
#include <math.h>
int main()
{
    int n,a,b,flag=0;
    scanf("%d",&n);
    a=(n-1)/2;
    if(n>2)
    {
        for(int i=1;i<=a;i++)
        {
            b=a-i;
            for(int j=b+1;j>=1;j--)
            {
                printf(" ");
            }
            for(int k=1;k<=2*i-1;k++)
            {
                printf("*");
            }
            printf("\n");
        }
    for(int i=1;i<=n;i++)
        {printf("*");}
    printf("\n");
    for(int i=a;i>=1;i--)
        {
            b=a-i;
            for(int j=0;j<=b;j++)
            {
                printf(" ");
            }
            for(int k=2*i-1;k>=1;k--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else 
        printf("Input error");
    return 0;
}
    
    