#include <stdio.h>

int main()
{
    int i,n; 
    int del(int p[],int n);
    scanf("%d",&n);
 
    int p[n];
    for(i=0;i<n;i++)
        p[i]=1;

    del(p,n);
    return 0;

}
int del(int p[],int n)
{
    int k=1,m=0,i;
   
    while(m<n-1)
    {
      for(i=0;i<n;i++)
      {
         if(*(p+i)!=0)
          {
             if(k==3)
             {
                *(p+i)=0;//将退出的人标记为0   
                m++;//退出人数加1 
                k=0;
             }
            k++;
          }
       }
    }
    for(i=0;i<n;i++)//找出地址非0的那个指针即所找的那个编号
        if(*(p+i)!=0)
            printf("%d\n",i+1);
}
 