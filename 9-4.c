#include <stdio.h>
#include <math.h>
int main()
{
    int a[10]={0},m,i=1,M[1000]={0},t=2,flag=0,sum=0;
    scanf("%d",&m);
    M[1]=m;
    while(m!=1)
    {
        for(int n=1;n<=10;n++)
        {
            a[n]=0;
        }
        while(m!=0)
        {
            a[i]=m%10;
            m=m/10;
            i++;
        }
        for(int k=1;k<=10;k++)
        {
            sum+=a[k]*a[k];
        }
        m=sum;
        sum=0;
        if(m==0)
        {
        flag=1;
        break;
        }
    }
    if(flag==0)
        printf("1");
    if(flag==1)
        printf("0");
    return 0;
}