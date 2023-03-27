#include <time.h>
#include <stdio.h>
 
int main()
{
    clock_t start_t, end_t;
    double total_t;
    int i;
    int m=4,n=40000,d;
    start_t = clock();
    //scanf("%d%d",&n,&m);
    d=f(n,m);
    printf("%d\n",d+1);
    end_t = clock();
    total_t = (double)(end_t - start_t);
    printf("CPU TIME:%fms\n ", total_t  );
    return(0);
}
int f(int n,int m)
{
    if(n==1)
        return 0;
    else
        {
        return ((f(n-1,m)+m)%n);
        }
}