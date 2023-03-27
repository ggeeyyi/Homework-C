#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
    char zyf,zzf,c;
    char input[140];
    int a[140];
    int search(int a[],int n);
    scanf("%c %c",&zyf,&zzf);
    scanf("%[\n]",input);
    gets(input);
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]==zyf)
            a[i]=1;
        if(input[i]==zzf)
            a[i]=-1;
    }
    for(int i=0;i<strlen(input);i++)
    {
        int k=0;
        if(a[i]==-1)
        {
           k=search(a,i-1);
           for(int m=k+1;m<i;m++)
            {
                printf("%c",input[m]);        
            }          
            printf("\n");
           a[k]=0;
           a[i]=0;
        }

    }
    
    return 0;
}
int search(int a[],int n)
{
    int flag=-1;
    for(int i=n;i>=0;i--)
    {
        if(a[i]==1)
        {
            flag=i;
            break;
        }
    }
    return flag;
}