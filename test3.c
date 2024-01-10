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
    //void exit();  退出 0
    void in();  //录入 1
    void search();  //查询 2
    void del();  //删除 3
    void modify();  //修改 4
    void insert();  //插入 5
    void order(); //排序 6
    void total();  //统计 7
    void show();  //显示 8

int main()
{
	system("color f0\n");	//白底黑字的色号 
	int n;
  	menu();
  	scanf("%d",&n);  //输入选择功能的编号
  	while(n)
  	{ 
	  	switch(n)
     	{ 
		 	case 1: in();break;
       		case 2: search();break;
       		case 3: del();break;
       		case 4: modify();break;
       		case 5: insert();break;
       		case 6: order();break;
       		case 7: total();break;
	   		case 8: show();break;
       		default:break;
     	}
    getch();
    menu();  //执行完功能再次显示菜单界面
    scanf("%d",&n);
  	}
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
    printf("\t\t||                请选择<0-8>                    ||\n");
    printf("\t\t---------------------------------------------------\n");
}

void in()  //1.录入 
{
   int i,m=0;/*m是记录的条数*/
      char ch[2];
      FILE *fp;/*定义文件指针*/
      if((fp=fopen("data.txt","a+"))==NULL)/*打开指定文件*/
      { 
          printf("文件不存在！\n");
          return;//直接返回，不在执行
      }
      while(!feof(fp))//判断是否指向结束符
    {
          if(fread(&stu[m] ,LEN,1,fp)==1)
        {
              m++;/*统计当前记录条数*/
        }
      }
      fclose(fp);
      if(m==0)
      {
          printf("文件中没有记录!\n");
    }
      else
      {          
        show();/*调用show函数，显示原有信息*/
      }
      if((fp=fopen("data.txt","wb"))==NULL)
      {
          printf("文件不存在！\n");
          return;
      }


      printf("输入学生信息(y/n):");
      scanf("%s",ch);
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
    {
        printf("number:");
        scanf("%d",&stu[m].num);/*输入学生学号*/
        for(i=0;i<m;i++)
            if(stu[i].num==stu[m].num)
            {
                   printf("这个学号已经存在了，按任意键继续!");
                getch();
                fclose(fp);
                return;
            }
         printf("name:");
         scanf("%s",stu[m].name);/*输入学生姓名*/
         printf("elec:");
        scanf("%lf",&stu[m].elec);/*输入选修课成绩*/
         printf("expe:");
         scanf("%lf",&stu[m].expe);/*输入实验课成绩*/
         printf("requ:");
         scanf("%lf",&stu[m].requ);/*输入必修课成绩*/
         stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;/*计算出总成绩*/
         if(fwrite(&stu[m],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
         {
             printf("不能保存!");
             getch();
         }
         else
         {
             printf("%s 被保存!\n",stu[m].name);
             m++;
         }
         printf("继续?(y/n):");/*询问是否继续*/
         scanf("%s",ch);
      }
      fclose(fp);
      printf("OK!\n");
}

void search()  //2.查询 
{
	int num,m=0;  //同上
	int i;
	FILE *fp;
	if((fp=fopen("data.txt","r"))==NULL)
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

void del()  //3.删除 
{
    void print();  //同上
	FILE *fp;
	int num,m=0;  //m为学生人数
	int i,j;  //i为定位学生位置的数字学生,j为m-1的值
	int flag=0;
	char ch[2];
	if((fp=fopen("data.txt","r"))==NULL)
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

void modify()  //4.修改 
{
	void print();
	int num;  //定义学号 
	char name[50]; //定义名字
	double expe;  //定义实验课 
    double requ;  //定义主修课 
    double elec;  //定义选修课
    
	FILE *fp;
	int m=0,a;
	int i,j;
	if((fp=fopen("data.txt","r"))==NULL)
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
	 	printf("\n");
	 	printf("请输入需要修改学生信息的学号：");
	 	scanf("%d",&num); 
	}
	for(i=0;i<m;i++)
	{
	 	if(num==stu[i].num)
	 	{
	      printf("1:学号，2:姓名，3:实验课成绩。4:必修课成绩，5:选修课成绩\n");
		  printf("该学生已被找到，请选择需要修改的内容(1-5)：");		  
		  scanf("%d",&a);
		  while(a)
		  { 		 
			  switch (a) 
			  {
			  	
			  	case 1:
			  		printf("将%d学生的学号修改为：",num); 
			  		scanf("%d",&num);
					stu[i].num=num;
					for(j=i+1;j<m;j++)
					{
						if(stu[j].num==num)
						{
							printf("您修改的学号已存在\n");
							getchar();
							return;
						}
					}   
			  		break;
			  		
			  	case 2:
				  	printf("将%d学生的姓名修改为：",num); 
				  	scanf("%s",name);
				  	strcpy(stu[i].name,name);
				  	break;
					  	
			  	case 3:
			  		printf("将%d学生的实验课成绩修改为：",expe); 
			  		scanf("%f",&expe);
					stu[i].expe=expe;
			  		stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
			  		
				case 4:
			  		printf("将%d学生的必修课成绩修改为：",requ); 
			  		scanf("%f",&requ);
			  		stu[i].requ=requ;
			  		stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
			  		
				case 5:
			  		printf("将%d学生的选修课成绩修改为：",elec);
					scanf("%f",&elec);
					stu[i].elec=elec;
					stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
					  	  	  	  	
			  	default:
			  	    printf("选择错误，请重新选择需要修改的内容：");
					scanf("%d",&a);   
			  		break;
			    }
			  
			  printf("请选择需要修改的内容(如果已修改完成请按0)：");
			  scanf("%d",&a);
		    }
			if((fp=fopen("stu.txt","wb"))==NULL)
				{
					printf("文件打开失败\n");
					return;
				}
				for(j=0;j<m;j++)
				{
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("不能保存\n");
						getchar();
					}
				}
				fclose(fp);
				printf("修改成功！\n");
				break;	 	
	    }
    }
    if(m==i)
    {
    	printf("未找到该学生\n"); 
	}
}

void insert()  //5.插入 
{
    FILE *fp;
      int i,j,k,m=0,snum;
      if((fp=fopen("data.txt","r+"))==NULL)
    { 
        printf("文件打开失败\n");
        return;
    }
      while(!feof(fp))  
         if(fread(&stu[m],LEN,1,fp)==1) 
         m++;
      if(m==0) 
    {
          printf("文件中没有记录!\n");
          fclose(fp);
          return;
      }
      printf("请输入要插入的位置(number)：\n");
      scanf("%d",&snum);//输入要插入的位置
    for (i = 0; i < m; i++)
        if (snum == stu[i].num)//判断是否存在
            break;                                          
          for(j=m-1;j>i;j--)//学号下面的内容
               stu[j+1]=stu[j];//从最后一条记录开始均向后移一位
          printf("现在请输入要插入的学生信息.\n");
              printf("学号:");
          scanf("%d",&stu[i+1].num);
          for(k=0;k<m;k++)//判断是否存在
            if(stu[k].num==stu[m].num)
            {
                printf("学号已经存在，按任意键继续!");
                getch();
                fclose(fp);
                return;
            }
          printf("名字:");
          scanf("%s",stu[i+1].name);
              printf("选修课成绩:");
          scanf("%lf",&stu[i+1].elec);
              printf("实验课成绩:");
          scanf("%lf",&stu[i+1].expe);
              printf("必修课成绩:");
          scanf("%lf",&stu[i+1].requ);
          stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ;
          printf("插入成功！按任意键返回主界面！"); 
          if((fp=fopen("data.txt","wb"))==NULL)
        { 
             printf("不能打开！\n");
             return;
        }
          for(k=0;k<=m;k++)
          if(fwrite(&stu[k] ,LEN,1,fp)!=1)//将修改后的记录写入磁盘文件中
           { 
           printf("不能保存!"); 
           getch(); 
        }
      fclose(fp);
}

void order()  //6.排序 
{
    FILE *fp;
      struct student t;
      int i=0,j=0,m=0;
      if((fp=fopen("data.txt","r+"))==NULL)
    { 
        printf("文件不存在！\n");
        return;
      }
      while(!feof(fp)) 
     if(fread(&stu[m] ,LEN,1,fp)==1) 
          m++;
      fclose(fp);
      if(m==0) 
      {
          printf("文件中没有记录!\n");
          return;
      }
      if((fp=fopen("data.txt","wb"))==NULL)
    {
          printf("文件不存在！\n");
          return;
    }
    for (i = 0; i < m - 1; i++)
        for (j = i + 1; j < m; j++)/*双重循环实现成绩比较并交换*/
            if (stu[i].sum < stu[j].sum)                                         
            {                                                                          
              t=stu[i];stu[i]=stu[j];stu[j]=t;
        }
    if((fp=fopen("data.txt","wb"))==NULL)
    { 
        printf("文件不存在！\n");
        return;
    }
      for(i=0;i<m;i++)/*将重新排好序的内容重新写入指定的磁盘文件中*/
          if(fwrite(&stu[i] ,LEN,1,fp)!=1)
           { 
            printf("%s 不能保存文件!\n"); 
            getch();
          }
      fclose(fp);
      printf("保存成功\n");
}

void total()  //7.统计 
{
	FILE *fp;
	int m=0;
	if((fp=fopen("data.txt","r"))==NULL)
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
		  if(m==0)
		  {
		  	printf("文件中没有内容\n");
		  	return;
		}
    printf("学生总人数：%d\n", m);
    fclose(fp);
}

void show()  //8.显示 
{
    int i,m=0;
  FILE *fp;
  if((fp=fopen("data.txt","r"))==NULL)
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


