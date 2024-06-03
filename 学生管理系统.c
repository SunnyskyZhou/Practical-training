#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum

//学生信息（使用结构体进行概述）

struct student
{
    int num;  //定义学号
    char name[20];  //定义名字
    double expe;   //定义实训课成绩
    double requ;   //定义必修课成绩
    double elec; //定义选修课成绩
    double sum; //定义总分
};

//定义主函数
struct student stu[50];

    void menu(); //菜单
    void exit();  //退出 0
    void in();  //录入 1
    void search();  //查询 2
    void del();  //删除 3
    void modify();  //修改 4
    void insert();  //输入 5
    void order(); //排序 6
    void total();  //统计 7
    void show();  //显示 8

int main()
{
    system("color f0\n");
    menu();
    int n;
    printf("请选择功能<0-8>: \n");
    scanf("%d",&n);

while(n)
     switch(n)
     {
         case 1:in(); break;
         case 2:search(); break;
         case 3:del(); break;
         case 4:modify(); break;
         case 5:insert(); break;
         case 6:order(); break;
         case 7:total(); break;
         case 8:show(); break;
         default: break;
     }
     getchar();
     menu();
     scanf("%d",&n);
}

void menu()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t---------------------------------------------------\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||===============================================||\n");
    printf("\t\t||              -学生信息管理系统-               ||\n");
    printf("\t\t||===============================================||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                1.录入学生信息                 ||\n");
    printf("\t\t||                2.查询学生信息                 ||\n");
    printf("\t\t||                3.删除学生信息                 ||\n");
    printf("\t\t||                4.修改学生信息                 ||\n");
    printf("\t\t||                5.插入学生信息                 ||\n");
    printf("\t\t||                6.排名学生成绩                 ||\n");
    printf("\t\t||                7.统计学生总数                 ||\n");
    printf("\t\t||              8.显示所有学生信息               ||\n");
    printf("\t\t||                  0.退出系统                   ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t---------------------------------------------------\n");
}

void in()
{
	void print();
	FILE *fp;  //文件指针
	int i, m=0;  //m指代学生人数
	char ch[2];
	if((fp=fopen("stu.txt","rb"))==NULL)  //判断文件是否存在，不存在则返回，存在继续执行
	{
	   	printf("文件打开失败\n");
	  	return;
    }
	while(!feof(fp))  //循环检察文件是否结束
	{
	  	if(fread(&stu[m],LEN,1,fp)==1)  //指针读取文件字节,反向读取+循环若为真，继续执行循环
	 	{
		 	m++;
		}
	}
	fclose(fp);  //关闭文件
	if(m==0)
	{
	 	printf("文件没有内容\n");  //文件为空
	}
	else
	{
	  	printf("  ");
	}
 	if((fp=fopen("stu.txt","a+"))==NULL)  //追加打开文件，后同上
  	{
   		printf("文件打开失败\n");
   		return;
  	}
	printf("输入学生信息(y/n);\n");
 	scanf("%s",ch);
 	while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
 	{
    	printf("number:\n");
 		scanf("%3d",&stu[m].num);
 		for(i=0;i<m;i++)
 		{
			if(stu[i].num==stu[m].num)
			{
				printf("您的信息已存在\n");
				fclose(fp);
				getchar();  //读取字节
				return;
			}
		}
		printf("num:\n");
		scanf("%s",stu[m].num);
		printf("name:\n");
		scanf("%s",stu[m].name);
		printf("expe:\n");
		scanf("%s",stu[i].expe);
		printf("requ:\n");
		scanf("%f",stu[m].requ);
		printf("elec:\n");
		scanf("%f",&stu[m].elec);
		stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
	  	if(fwrite(&stu[m],LEN,1,fp)!=1)
	  	{
	  		printf("不能保存\n");  //若读写结果与文件内容不一样（即不为真），重新读写
	    	getchar();  //
	  	}
	  	else
	  	{
	   		printf("信息保存成功\n");

	   		m++;  //否则继续
	  	}
		printf("是否继续录入学生信息(y/n)：");
		scanf("%s",ch);
	}
	fclose(fp);
}

void search()
{
	int num,m=0;  //同上
	int i;
	FILE *fp;
	if((fp=fopen("stu.txt","rb"))==NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
		{
		  m++;
	    }
	 }
	fclose(fp);
	if(m==0)
	{
		printf("文件没有内容\n");
		return;
	}
	printf("请输入学生学号进行查询：");
	scanf("%d",&num);
	for(i=0;i<m;i++)
	{
		if(num==stu[i].num)
		{
			printf("\n");
			printf("该学生信息已被查到；\n");
			printf("学号\t姓名\t实验课成绩\t必修课成绩\t选修课成绩\t总成绩\n");
			printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].expe,stu[i].requ,stu[i].elec,stu[i].sum);
			break;
		}
	}
	if(m==i)
	{
		printf("该学生信息不存在\n");
		return;
	}
}

void del()
{
    void print();  //同上
	FILE *fp;
	int num,m=0;  //m为学生人数
	int i,j;  //i为定位学生位置的数字学生,j为m-1的值
	int flag=0;
	char ch[2];
	if((fp=fopen("stu.txt","rb"))==NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
		{
			m++;
		}
	}
	fclose(fp);
	if(m==0)
	{
		printf("文件中没有学生信息\n");
	}
	else
	{
		printf("  ");
	    printf("请输入需要删除学生信息的学号：");
	    scanf("%d",&num);
	}
	for(i=0;i<m;i++)
	{
		if(stu[i].num==num)  //匹配到学生的正确学号及其信息
		{
			printf("该学生已找到，是否删除(y/n):");
			scanf("%s",ch);
			if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)  //大小写无区别
			{
				for(j=i;j<m;j++)
				{
					stu[j]=stu[j+1];
				}
				 m--;
				 flag=1;
				if((fp=fopen("stu.txt","wb"))==NULL)
				{
					printf("文件打开失败\n");
					return;
				}
				for(j=0;j<m;j++)  //同上
				{
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("不能保存\n");
						getchar();
					}
				}
				fclose(fp);
				printf("删除成功！\n");break;

			}
			else
			{
			   printf("学生信息存在，不需要删除。");
			   break;
		    }
		}

	}
	if(m==i&&flag==0)
	{
		printf("未找到该学生");
	}

}

void modify()
{

}

void insert()
{

}

void order()
{

}

void total()
{

}

void show()
{
    int i,m=0;
  FILE *fp;
  if((fp=fopen("stu.txt","rb"))==NULL)
  {
   printf("文件打开失败\n");
   return;
  }
    while(!feof(fp))
 {
  if(fread(&stu[m],LEN,1,fp)==1)
 	 {
	 	m++;
	 }
  }
  fclose(fp);
  if(m==0)
  {
  	printf("文件中没有内容\n");
  }
   printf("学号\t姓名\t实验课成绩\t必修课成绩\t选修课成绩\t总成绩\n");
   for(i=0;i<m;i++)
   {
     printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].expe,stu[i].requ,stu[i].elec,stu[i].sum);
    }
}

