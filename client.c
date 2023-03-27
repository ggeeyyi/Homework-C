#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int judge(int year,int month,int day,int hour,int minute);
    int year[100];
    int month[100];
    int day[100];
    int hour[100];
    int minute[100];

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d.%d.%d %d:%d",&year[i],&month[i],&day[i],&hour[i],&minute[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d-%d-%d-%d-%d",year[i],month[i],day[i],hour[i],minute[i]);
    }
}