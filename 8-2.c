#include <time.h>
#include <stdio.h>
#include <math.h>
int main()
{
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    int n=35;
    int godown(int);
    printf("n=%d    %d\n",n,godown(n));
    end_t = clock();
    total_t = (double)(end_t - start_t);
    printf("CPU TIME:%fms\n ", total_t  );
    return 0;
}
int godown(int n)
{
    int m;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    else
        {
            m=godown(n-1)+godown(n-2)+godown(n-3);
            return m;
        }
    
}