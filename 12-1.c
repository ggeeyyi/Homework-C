#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Arrscanf(char arr[][80], int N);//输入字符串
void sort(char arr[][80], int N);//将字符串排序
void Swap(char **left, char **right);//交换指针
int main()
{
    int N;
    scanf("%d", &N);
    char (*arr)[80]=malloc(N*80*sizeof(char));
    Arrscanf(arr,N);
    sort(arr,N);
    for(int i=0;i<N;i++)
    {
      printf("%s", arr[i]);
      if(i!=N-1) 
        printf("\n");
    }
    free(arr);
    return 0;
}

void Arrscanf(char arr[][80], int N)
{
    for(int i = 0; i < N; i++)
    {
        scanf("%s", arr[i]);
    }
}
void sort(char arr[][80], int N)
{   
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N-i-1;j++)
      {
        if(strcmp(arr[j],arr[j+1])==1)
          {    
            Swap(arr+j,arr+(j+1));
          }
        }
    }
}
void Swap(char **left, char **right)
{
    char *temp = *left;
    *left = *right;
    *right = temp;
}