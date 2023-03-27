#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    enum day {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
    int n;
    scanf("%d",&n);
    n--;
    switch (n)
    {
    case Monday:printf("%s\t","Monday");break;
    case Tuesday:printf("%s\t","Tuesday");break;
    case Wednesday:printf("%s\t","Wednesday");break;
    case Thursday:printf("%s\t","Thursday");break;
    case Friday:printf("%s\t","Friday");break;
    case Saturday:printf("%s\t","Saturday");break;
    case Sunday:printf("%s\t","Sunday");break;
    default:break;
    }
    return 0;
}
