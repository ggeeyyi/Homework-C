#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start_t, end_t;
    double total_t;
    int m=4,n=400000,j;
    start_t = clock();
    //scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        j=(j+m)%i;
    }
    printf("%d\n",j+1);
    end_t = clock();
    total_t = (double)(end_t - start_t);
    printf("CPU TIME:%fms\n ", total_t  );

    return 0;
}