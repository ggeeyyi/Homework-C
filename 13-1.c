#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct student
{
    char ID[10];
    char name[10];
    char sex[10];
    char birthday[10];
    double score;
};
int main()
{
    struct student stu[10];
    char ID_[10];
    char name_[10];
    char sex_[10];
    char birthday_[10];
    double score_;
    int counter=1;
    for(int i=0;i<10;i++)
    {
        scanf("%s",ID_);
        strcpy(stu[i].ID,ID_);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%s",name_);
        strcpy(stu[i].name,name_);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%s",sex_);
        strcpy(stu[i].sex,sex_);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%s",birthday_);
        strcpy(stu[i].birthday,birthday_);
    }
    for(int i=0;i<10;i++)
    {
        scanf("%lf",&stu[i].score);
    }
    for(int i=0;i<10;i++)
    {
        printf("%s   %s   %s   %s   %lf\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].birthday,stu[i].score);
    }
    double ave;
    for(int i=0;i<10;i++)
    {
        ave+=0.1*stu[i].score;
    }
    printf("average=%lf\n",ave);
    sortbyscores(stu,10);
    return 0;
}
void sortbyscores(struct student stub[],int n)
{
    int i,j;
    struct student temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stub[i].score<stub[j].score)
            {
                temp=stub[i];
                stub[i]=stub[j];
                stub[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%s   %s   %s   %s   %lf\n",stub[i].ID,stub[i].name,stub[i].sex,stub[i].birthday,stub[i].score);
    }
}