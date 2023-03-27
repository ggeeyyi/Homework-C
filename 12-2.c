#include <stdio.h>
#include <stdlib.h>
#define N 10
int main() 
{
  // 定义一个10*10的矩阵
  int matrix[N][N];

  // 定义一个变量用来存储输入的整数n
  int n;

  // 定义一个变量用来存储第n对角线上的元素和
  int sum = 0;

  // 使用指针计算第n对角线上的元素和
    for (int i=0;i<N;i++) 
    {
        for (int j=0;j<N;j++) 
        {
            matrix[i][j]=10*i+j;
        }
    }
    scanf("%d", &n);
    for (int i=0;i<N;i++) 
    {
        for (int j=0;j<N;j++) 
        {
            if (((i+j)%N)==n) 
            {
                sum += *(*(matrix + i) + j);
            }
        }
    }

  // 输出第n对角线上的元素和
    printf("%d", sum);

    return 0;
}