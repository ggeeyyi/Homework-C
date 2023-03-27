#include <stdio.h>
#include <math.h>
int main()
{
    int a[40]={0},cnt;
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=40;j++)
        {
            if(a[j]==0)
            {
                cnt++;
                if(cnt%11==0)
                    a[j]=1;
            }
        }
        cnt=0;
    }
    for(int k=1;k<=40;k++)
        printf("%d\n",a[k]);
    return 0;
}