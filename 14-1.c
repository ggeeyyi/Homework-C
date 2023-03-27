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
    char id[10]; 
    int number;
    printf("Input your ID: ");
	scanf("%s",id);
    sortbyscores(stu,10);

    FILE* fp = fopen("data.txt", "wb+");
    if (fp == NULL) 
    { 
        printf("cannot open\n"); 
        return -1;
         }
    else
    {
		puts("Open file success\n");
	}
    fwrite(stu, sizeof(struct student), 10, fp);
    puts("Write file success\n");
    //移动文件指针到文件头 
    rewind(fp);

    if (fread(stu, sizeof(struct student), 3, fp) == NULL)
	{
		puts("Read file error\n");
	}
	else
	{
		printf("Read file success\n");
	}
	// 输出读取到的文件内容

    for(int i=0;i<10;i++)
    {
        if(strcmp(id,stu[i].ID)==0)
            number=i;
    }
    printf("StudentID %s Name:%s, sex:%s,birthday:%s,Score:%lf\n",stu[number].ID,stu[number].name,stu[number].sex,stu[number].birthday,stu[number].score);
	fclose(fp);
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