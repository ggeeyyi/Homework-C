#include<stdio.h>
int main()
{
    void sort(int x[],int n); 
    int i,*p,a[10],b[10],c[20],*q;
    p=a; 
    q=b;

    printf("in put 20 numbers:");
    for(i=0;i<10;i++)
        scanf("%d",p++);
    p=a; 
    for(int j=0;j<10;j++)
        scanf("%d",q++);
    q=b;
    sort(p,10); 
  
    for(p=a,i=0;i<10;i++)
    {
        printf("%d ",*p); 
        p++;
    }
    printf("\n");

    sort(q,10); 
    for(q=b,i=0;i<10;i++)
    {
        printf("%d ",*q); 
        q++;
    }//分别比较

    int a1=0,b1=0;
    for(int m=0;m<20;m++)
    {  
    if((a1<=9)&&(b1<=9))
    {
        if(a[a1]<=b[b1])
        {
            c[m]=b[b1];
            b1++;
            }
        else 
        {
            c[m]=a[a1];
            a1++;
            }
    }
    else if(a1==10)
        {
        for(int l=(10+b1);l<20;l++)
            {
                c[l]=b[b1];
                b1++;
            }
        }
    else
        {
        for(int l=(10+a1);l<20;l++)
            {
                c[l]=a[b1];
                a1++;
            }
        }
    }
    printf("\n");
    for(int k=0;k<20;k++)
    {
        printf("%d ",c[k]);
    }
    return 0;
}

void sort(int x[],int n)
{
    int i,j,k,t;
    for(i=0;i<n-1;i++)
{
    k=i;
    for(j=i+1;j<n;j++)
    if(x[j]>x[k]) 
        k=j;
    if(k!=i)
    {
        t=x[i];
        x[i]=x[k];
        x[k]=t;
        }
    }
}
