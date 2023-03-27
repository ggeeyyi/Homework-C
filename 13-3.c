#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct fraction
{
    long long int numerator;
    unsigned long long int denominator;
};
int main()
{
    struct fraction Fra_Add(struct fraction f1, struct fraction f2);
    struct fraction Fra_Sub(struct fraction f1, struct fraction f2);
    struct fraction f[11];
    struct fraction temp;
    struct fraction fout;
    fout.denominator=0;
    fout.numerator=0;
    for(int i=1;i<=10;i++)
    {
        f[i].numerator=1;
        f[i].denominator=2*i-1;
    }   
    fout=f[1];
    for(int i=2;i<=10;i++)
    {
        if(i%2==1)
            fout=Fra_Add(fout,f[i]);
        if(i%2==0)
            fout=Fra_Sub(fout,f[i]);
    }
    printf("%lld/%llu\n",fout.numerator,fout.denominator);
    double s;
    for(int i=1;i<=10;i++)
    {
        s+=pow(-1,i-1)/(2*i-1);
    }
    printf("%lf",s);
    return 0;
}
struct fraction Fra_Add(struct fraction f1, struct fraction f2)
{
    struct fraction Add;
    long long int GCD;
    long long int gcd(long long int a,unsigned long long int c);
    if(f1.denominator==0||f2.denominator==0)
        {
            Add.numerator=0;
            Add.denominator=0;
            return Add;
        }
    else
        {
        Add.numerator=(f1.numerator)*(f2.denominator)+(f2.numerator)*(f1.denominator);
        Add.denominator=(f1.denominator)*(f2.denominator);
       GCD=gcd(Add.numerator,Add.denominator);
        Add.numerator=Add.numerator/GCD;
        Add.denominator=Add.denominator/GCD; 
        return Add;
        }
}
struct fraction Fra_Sub(struct fraction f1, struct fraction f2)
{
    struct fraction Sub;
    long long int GCD;
    long long int gcd(long long int a,unsigned long long int c);
    if(f1.denominator==0||f2.denominator==0)
        {
            Sub.numerator=0;
            Sub.denominator=0;
            return Sub;
        }
    else
        {
            Sub.numerator=(f1.numerator)*(f2.denominator)-(f2.numerator)*(f1.denominator);
            Sub.denominator=(f1.denominator)*(f2.denominator);
            GCD=gcd(Sub.numerator,Sub.denominator);
            Sub.numerator=Sub.numerator/GCD;
            Sub.denominator=Sub.denominator/GCD;
            return Sub;
        }
}
long long int gcd(long long int a,unsigned long long int c)
{
    while(c!=0)
    {
        int t=a%c;
        a=c;
        c=t;
    }
    return a;
}