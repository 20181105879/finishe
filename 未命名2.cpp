#include <iostream>
#include <algorithm>
#include <cstring>
#include<fstream>
#define STUDENTNUMBER 5
#define TEACHERNUMBER 7
using namespace std;
long long i,j,k;
char output_headline[100]={"学号-------名字--性别--学院---班级--平均分----号码"};
char show_headline1[250]={"学号------------------姓名---------性别--------------------学院------------------------班级-------分数-------2---------3---------4-----------5-----------6-----------7-------号码-------平均分\n"};
char Stuenden_headline[100];
char Teacher_headline[100];
struct Students1{
    char id[30];
    char name[30];
    char sex[20];
    char college[50];
    char st_class[30];
    long long phone;
    double sore[TEACHERNUMBER];
    double avg;
    double sum;
    
}student1[STUDENTNUMBER];
struct Teachers{
    char name[30];
    char id[30];
    char adress[100];
    char phone[12];
    double sore[STUDENTNUMBER];
    char sex[20];
}teacher[TEACHERNUMBER];
bool cmp( Students1  &p1,Students1 &p2)
{
    if(p1.avg>p2.avg)
    {
        return 1;
    }
    else if(p1.avg==p2.avg)
    {
        if(p1.name-p2.name>0)
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
        return 0;
    }
}
int main()
{
    FILE *p1=NULL;
//    p1=fopen("/Users/s20181105879/Desktop/teacher.txt","r");
        p1=fopen("teacher.txt","r");
    if(!p1)
    {
        printf("open fail\n");
        return 0;
    }
    fscanf(p1,"%s",Teacher_headline);
    for(i=0;i<TEACHERNUMBER;i++)
    {
        fscanf(p1,"%s",teacher[i].id,teacher[i].name);
        fscanf(p1,"%s",teacher[i].name);
        fscanf(p1,"%s",teacher[i].sex);
        fscanf(p1,"%s",teacher[i].adress);
        fscanf(p1,"%s",teacher[i].phone);
        for(j=0;j<STUDENTNUMBER;j++)
        {
            fscanf(p1,"%lf",&teacher[i].sore[j]);
        }
    }
    fclose(p1);
    FILE *fp=NULL;
 //   fp=fopen("/Users/s20181105879/Desktop/student.txt","r");
        fp=fopen("student.txt","r");
    if(!fp)
    {
        printf("open fail\n");
        return 0;
    }
    fscanf(fp,"%s",Stuenden_headline);
    for(i=0;i<STUDENTNUMBER;i++)
    {
        fscanf(fp,"%s",student1[i].id);
        fscanf(fp,"%s",student1[i].name);
        fscanf(fp,"%s",student1[i].sex);
        fscanf(fp,"%s",student1[i].college);
        fscanf(fp,"%s",student1[i].st_class);
        fscanf(fp,"%lld",&student1[i].phone);
    }
    fclose(fp);
    for(j=0;j<STUDENTNUMBER;j++)
    {
        for(k=0;k<TEACHERNUMBER;k++)
        {
            student1[j].sore[k]=teacher[k].sore[j];
        }
    }
    for(i=0;i<STUDENTNUMBER;i++)
    {
        sort(student1[i].sore,student1[i].sore+TEACHERNUMBER);
        student1[i].sum=0;
        for(j=0;j<TEACHERNUMBER;j++)
        {
            student1[i].sum+=student1[i].sore[j];
        }
        student1[i].avg=(student1[i].sum-student1[i].sore[0]-student1[i].sore[TEACHERNUMBER-1])/(TEACHERNUMBER-2);
    }
    sort(student1,student1+STUDENTNUMBER,cmp);
    printf("%s\n",output_headline);
    for(i=0;i<STUDENTNUMBER;i++)
    {
        printf("rank %lld:\n",(i+1));
        printf("%-10s%-8s%-6s",student1[i].id,student1[i].name,student1[i].sex);
        printf("%-10s%-10s",student1[i].college,student1[i].st_class);
        printf("%-6.2f  %-10lld\n",student1[i].avg,student1[i].phone);
        printf("\n");
    }
    FILE *pp=NULL;
//    pp=fopen("/Users/s20181105879/Desktop/show.txt","w");
        pp=fopen("show.txt","w");
    if(!pp)
    {
        printf("open false\n");
        return 0;
    }
    fprintf(pp,"%s",show_headline1);
    for(i=0;i<STUDENTNUMBER;i++)
    {
        fprintf(pp,"rank %4lld:\n",i+1);
        fprintf(pp,"%-10s",student1[i].id);
        fprintf(pp,"%20s",student1[i].name);
        fprintf(pp,"%10s",student1[i].sex);
        fprintf(pp,"%30s",student1[i].college);
        fprintf(pp,"%30s",student1[i].st_class);
        for(int j=0;j<TEACHERNUMBER;j++)
        {
            fprintf(pp,"%10.2f",student1[i].sore[j]);
        }
        fprintf(pp,"%15lld",student1[i].phone);
        fprintf(pp,"%10.2f",student1[i].avg);
        fprintf(pp,"\n\n");
    }
    fclose(pp);
    return 0;
}
//学生表格
//学号------姓名---性别----学院------班级--------号码
//2018110  邱健军    男     机械院     机械工程    1008611
//2018111  王二胖    女     医学院     内护理学   1008612
//2018112  张红星    男     计算机     修飞机学   1008613
//2018113  刘之伟    男     地科院    土木工程    1008614
//2018114  阳建波    男     计科院    软件工程    1008615
//老师表格
//编号--姓名--性别--地址------------------号码---1--2---3--4--5--6--7--8......
//110   张三    男     江西省赣州市信丰县   11010  72 88 69 11 28 
//111   李四    男     江苏省镇江市大唐县   10020  32 58 99 11 22
//112   王五    男     浙江省丽水市丽水县   10030  62 88 99 33 22 
//113   赵六    男     广西省丽水市丽水县   10040  72 88 79 11 62 
//114   刘启    女     江苏省镇江市信丰县   10050  72 22 99 11 22 
//115   李八    男     浙江省丽水市大唐县   10060  22 88 29 51 72 
//116   何九    男     浙江省丽水市信丰县   10070  72 96 99 11 92 

