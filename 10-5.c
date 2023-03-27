#include <stdio.h>
int main()
{
	char a[13];
	int b[5]={0},t=0,c[5]={0},m=0,p=0;
	long long sum;
	scanf("%s",a);
	for(int i=0;i<13;i++)
	{
		if(a[i]!='.')
		{
			b[t]++;
		}
		else
			t++;
	}
	for(int i=0;i<13;i++)
	{
		if(a[i]!='.')
		{
			c[p]+=pow(10,b[m]-1)*(a[i]-48);
			b[m]--;
		}
		else
			{m++;
			p++;}
	}
	sum=pow(2,24)*c[0]+pow(2,16)*c[1]+pow(2,8)*c[2]+pow(2,0)*c[3];
	printf("%lld",sum);
	return 0;
}
