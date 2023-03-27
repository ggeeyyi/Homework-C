#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i,x,a[301]={0},p=0,b[101]={0},t=0;
	srand(time(0));
	for(i=1;i<=300;i++)
	{
		x=rand()%100+1;
        a[i]=x;
	}	
    for(int i=1;i<=300;i++)
    {
        for(int j=1;j<=300;j++)
        {
            if(a[i]>=a[j])
            {
               p++;
            }
        }
        if(p>=200)
            {b[t]=a[i];
            t++;}
            p=0;
    }
    for(int i=1;i<=100;i++)
    {
        printf("%d  ",b[i]);
    }
    return 0;
} 
   
