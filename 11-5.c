#include<stdio.h>
int main()
{
    int N,max[4],min[4],MAX,MIN,N2,a[4],N1;
    void maxsort(int x[]);
    void minsort(int y[]);
    scanf("%d",&N);
    
    N1=N;
    for(int i=3;i>=0;i--)
    {
        a[i]=N1%10;
        N1=N1/10;
    }


    if((a[0]!=a[1])&&(a[0]!=a[2])&&(a[0]!=a[3])&&(a[1]!=a[2])&&(a[1]!=a[3])&&(a[2]!=a[3]))
    {
        while (N!=6174)
        {
        N2=N;
        for(int i=3;i>=0;i--)
        {
            max[i]=N2%10;
            min[i]=N2%10;
            N2=N2/10;
        }
        maxsort(max);
        minsort(min);
        
        MAX=1000*max[0]+100*max[1]+10*max[2]+max[3];
        MIN=1000*min[0]+100*min[1]+10*min[2]+min[3];
        N=MAX-MIN;
        printf("%d-%d=%d\n",MAX,MIN,N);
        }
    }
    else  
        printf("error");
    return 0;
}
void maxsort(int x[])
{
    int i,j,k,t,n=4;
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

void minsort(int y[])
{
    int i,j,k,t,n=4;
    for(i=0;i<n-1;i++)
    {
    k=i;
    for(j=i+1;j<n;j++)
        if(y[j]<y[k]) 
            k=j;
        if(k!=i)
        {
            t=y[i];
            y[i]=y[k];
            y[k]=t;
        }
    }
}