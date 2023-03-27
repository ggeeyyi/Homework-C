#include <stdio.h>
#include <stdlib.h>
#define MAX 5

double A[5][5];
double b[5];
double X[5];
int N;

void Input_Matrix()//输入矩阵
{
    int i,j;
    N=4;
    printf("MAT A:\n");
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            scanf("%lf",&A[i-1][j-1]);
    }
    printf("MAT B:\n");
    for(i=1; i<=N; i++)
    {
        scanf("%lf",&b[i-1]);
    }
}

int main()
{
    int i,j,k;
    float m;
    float S;
    Input_Matrix();


    for(k=0; k<N-1; k++)
    {
        if(!A[k][k])
            return -1;
        for(i=k+1; i<N; i++)
        {
            m=A[i][k]/A[k][k];
            for(j=k; j<N; j++)
            {
                A[i][j]=A[i][j]-m*A[k][j];
            }
            b[i]=b[i]-m*b[k];
        }
    }
 

    X[N-1]=b[N-1]/A[N-1][N-1];
    for(k=N-2; k>=0; k--)
    {
        S=b[k];
        for(j=k+1; j<N; j++)
        {
            S=S-A[k][j]*X[j];
        }
        X[k]=S/A[k][k];
    }
    printf("X=\n\n");
    for(i=0;i<N;i++)
        printf("%.4lf\n",X[i]);
    return 0;
}
