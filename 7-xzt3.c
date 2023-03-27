#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d,e,f,n,cntp=0,cntq=0;
    for(a=1;a<=4;a++)
        {
            for(b=0;b<=9;b++)
            {
                for(c=0;c<=9;c++)
                {
                    for(d=0;d<=9;d++)
                    {
                        for(e=0;e<=9;e++)
                        {
                            for(f=0;f<=9;f++)
                            {
                                if((a!=b)&&(a!=c)&&(a!=d)&&(a!=e)&&(a!=f)&&(b!=c)&&(b!=d)&&(b!=e)&&(b!=f)&&(c!=d)&&(c!=e)&&(c!=f)&&(d!=e)&&(d!=f)&&(e!=f))
                                {n=100000*a+10000*b+1000*c+100*d+10*e+f;
                                printf("%d\n",n);}
                                }
                            }
                        }
                    }
                }
            }
    return 0;
}