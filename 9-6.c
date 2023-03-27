#include <stdio.h>
#include <math.h>
int main()
{
    int weishu(long long),num;
    int w[18]={0};
    int d[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int s=0,m,t=18;
    long long y;
    scanf("%lld",&y);
    if(weishu(y)==18)
        {
        for(int i=0;i<18;i++)
        {
            w[i]=y%10;
            y=y/10;
        }
        for(int i=0;i<17;i++)
            {
                s+=w[17-i]*d[i];
            }
        m=(-(s%11)+12)%11;
        if(m==w[0])
            printf("合法");
        else
            {printf("不合法,");
            printf("校验位应该是%d",m);}
        }
    else
        {
        for(int i=0;i<17;i++)
        {
            w[i]=y%10;
            y=y/10;
        }
        for(int i=0;i<17;i++)
            {
                s+=w[16-i]*d[i];
            }
       
        m=(-(s%11)+12)%11;
        if(m==10)
            printf("合法");
        else
            {printf("不合法,");
            printf("校验位应该是%d",m);}
        }
        
    return 0;
}
int weishu(long long x)
{
    int num;
    while(x!=0)
    {
        x=x/10;
        num++;
    }
    return (num);
}