#include<stdio.h>
int main()
{
    void sort(int x[],int n); 
    int i,*p,a[10];
    p=a; 
    printf("input 10 numbers:");
    for(i=0;i<10;i++)
        scanf("%d",p++);
    p=a; 
    sort(p,10); 
    return 0;
}

void sort(int x[],int n)
{
    int i,j,k,t,b[10]={0,1,2,3,4,5,6,7,8,9},*p;
    for(i=0;i<n-1;i++)
    {
    k=i;
    for(j=i+1;j<n;j++)
        if(x[j]<x[k]) 
            k=j;
        if(k!=i)
        {
            t=x[i];
            x[i]=x[k];
            x[k]=t;

            t=b[i];
            b[i]=b[k];
            b[k]=t;
        }
    }
    for(p=x,i=0;i<10;i++)
    {
        printf("%d ",*p); 
        p++;
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",b[i]); 
    }
}
