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
        int trigger=0;
        trigger=judge(year[i],month[i],day[i],hour[i],minute[i]);
        while (trigger==0)
        {
            if(minute[i]>60)
            {
                minute[i]=minute[i]-60;
                hour[i]++;
            }
            if(hour[i]>24)
            {
                hour[i]=hour[i]-24;
                day[i]++;
            }
            if((day[i]>31&&(month[i]==1||month[i]==3||month[i]==5||month[i]==7||month[i]==8||month[i]==10||month[i]==12))||((day[i]>30)&&(month[i] == 4 || month[i] == 6 || month[i] == 9 || month[i] == 11))||(day[i]>29&&((year[i] % 100 != 0 && year[i] % 4 == 0) || year[i] % 400 == 0)&&month[i]==2)&&(day[i]>28&&((year[i] % 100 == 0 || year[i] % 4 != 0) && year[i] % 400 != 0)&&month[i]==2))
            {
                if(day[i]>31&&(month[i]==1||month[i]==3||month[i]==5||month[i]==7||month[i]==8||month[i]==10||month[i]==12))
                    {
                        day[i]=day[i]-31;
                        month[i]++;
                    }
                if(((day[i]>30)&&(month[i] == 4 || month[i] == 6 || month[i] == 9 || month[i] == 11)))
                {
                        day[i]=day[i]-30;
                        month[i]++;
                }
                if((day[i]>28&&((year[i] % 100 == 0 || year[i] % 4 != 0) && year[i] % 400 != 0)&&month[i]==2))
                {
                        day[i]=day[i]-28;
                        month[i]++;
                }
                if((day[i]>29&&((year[i] % 100 != 0 && year[i] % 4 == 0) || year[i] % 400 == 0)&&month[i]==2))
                {
                        day[i]=day[i]-29;
                        month[i]++;
                }
            }
            if(month[i]>12)
            {
                month[i]=month[i]-12;
                year[i]++;
            }
            trigger=judge(year[i],month[i],day[i],hour[i],minute[i]);
            if(trigger==0)
                break;
        }  
    }

    for(int i=0;i<n;i++)
    {
        if(hour[i]==24)
        {
            hour[i]=0;
        }
        printf("%d.%d.%d. %d:%d\n",year[i],month[i],day[i],hour[i],minute[i]);
    }
    return 0;
}
int judge(int year,int month,int day,int hour,int minute)
{
    if(minute>60||hour>24)
        return 0;
    if (month < 1 || month>12)
    {
        return 0;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) 
    {
        if (day >= 1 && day <= 31) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
     {
        if (day >= 1 && day <= 30) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }                                     
    else if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) 
    {
        if (day >= 1 && day <= 29) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else 
    {
        if (day >= 1 && day <= 28) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
    