#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum

//ѧ����Ϣ��ʹ�ýṹ����и�����

struct student
{
    int num;  //����ѧ��
    char name[20];  //��������
    double expe;   //����ʵѵ�γɼ�
    double requ;   //������޿γɼ�
    double elec; //����ѡ�޿γɼ�
    double sum; //�����ܷ�
};

//����������
struct student stu[50];

    void menu(); //�˵�
    void exit();  //�˳� 0
    void in();  //¼�� 1
    void search();  //��ѯ 2
    void del();  //ɾ�� 3
    void modify();  //�޸� 4
    void insert();  //���� 5
    void order(); //���� 6
    void total();  //ͳ�� 7
    void show();  //��ʾ 8

int main()
{
    system("color f0\n");
    menu();
    int n;
    printf("��ѡ����<0-8>: \n");
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
    printf("\t\t||              -ѧ����Ϣ����ϵͳ-               ||\n");
    printf("\t\t||===============================================||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                1.¼��ѧ����Ϣ                 ||\n");
    printf("\t\t||                2.��ѯѧ����Ϣ                 ||\n");
    printf("\t\t||                3.ɾ��ѧ����Ϣ                 ||\n");
    printf("\t\t||                4.�޸�ѧ����Ϣ                 ||\n");
    printf("\t\t||                5.����ѧ����Ϣ                 ||\n");
    printf("\t\t||                6.����ѧ���ɼ�                 ||\n");
    printf("\t\t||                7.ͳ��ѧ������                 ||\n");
    printf("\t\t||              8.��ʾ����ѧ����Ϣ               ||\n");
    printf("\t\t||                  0.�˳�ϵͳ                   ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t||                                               ||\n");
    printf("\t\t---------------------------------------------------\n");
}

void in()
{
	void print();
	FILE *fp;  //�ļ�ָ��
	int i, m=0;  //mָ��ѧ������
	char ch[2];
	if((fp=fopen("stu.txt","rb"))==NULL)  //�ж��ļ��Ƿ���ڣ��������򷵻أ����ڼ���ִ��
	{
	   	printf("�ļ���ʧ��\n");
	  	return;
    }
	while(!feof(fp))  //ѭ������ļ��Ƿ����
	{
	  	if(fread(&stu[m],LEN,1,fp)==1)  //ָ���ȡ�ļ��ֽ�,�����ȡ+ѭ����Ϊ�棬����ִ��ѭ��
	 	{
		 	m++;
		}
	}
	fclose(fp);  //�ر��ļ�
	if(m==0)
	{
	 	printf("�ļ�û������\n");  //�ļ�Ϊ��
	}
	else
	{
	  	printf("  ");
	}
 	if((fp=fopen("stu.txt","a+"))==NULL)  //׷�Ӵ��ļ�����ͬ��
  	{
   		printf("�ļ���ʧ��\n");
   		return;
  	}
	printf("����ѧ����Ϣ(y/n);\n");
 	scanf("%s",ch);
 	while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
 	{
    	printf("number:\n");
 		scanf("%3d",&stu[m].num);
 		for(i=0;i<m;i++)
 		{
			if(stu[i].num==stu[m].num)
			{
				printf("������Ϣ�Ѵ���\n");
				fclose(fp);
				getchar();  //��ȡ�ֽ�
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
	  		printf("���ܱ���\n");  //����д������ļ����ݲ�һ��������Ϊ�棩�����¶�д
	    	getchar();  //
	  	}
	  	else
	  	{
	   		printf("��Ϣ����ɹ�\n");

	   		m++;  //�������
	  	}
		printf("�Ƿ����¼��ѧ����Ϣ(y/n)��");
		scanf("%s",ch);
	}
	fclose(fp);
}

void search()
{
	int num,m=0;  //ͬ��
	int i;
	FILE *fp;
	if((fp=fopen("stu.txt","rb"))==NULL)
	{
		printf("�ļ���ʧ��\n");
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
		printf("�ļ�û������\n");
		return;
	}
	printf("������ѧ��ѧ�Ž��в�ѯ��");
	scanf("%d",&num);
	for(i=0;i<m;i++)
	{
		if(num==stu[i].num)
		{
			printf("\n");
			printf("��ѧ����Ϣ�ѱ��鵽��\n");
			printf("ѧ��\t����\tʵ��γɼ�\t���޿γɼ�\tѡ�޿γɼ�\t�ܳɼ�\n");
			printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].expe,stu[i].requ,stu[i].elec,stu[i].sum);
			break;
		}
	}
	if(m==i)
	{
		printf("��ѧ����Ϣ������\n");
		return;
	}
}

void del()
{
    void print();  //ͬ��
	FILE *fp;
	int num,m=0;  //mΪѧ������
	int i,j;  //iΪ��λѧ��λ�õ�����ѧ��,jΪm-1��ֵ
	int flag=0;
	char ch[2];
	if((fp=fopen("stu.txt","rb"))==NULL)
	{
		printf("�ļ���ʧ��\n");
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
		printf("�ļ���û��ѧ����Ϣ\n");
	}
	else
	{
		printf("  ");
	    printf("��������Ҫɾ��ѧ����Ϣ��ѧ�ţ�");
	    scanf("%d",&num);
	}
	for(i=0;i<m;i++)
	{
		if(stu[i].num==num)  //ƥ�䵽ѧ������ȷѧ�ż�����Ϣ
		{
			printf("��ѧ�����ҵ����Ƿ�ɾ��(y/n):");
			scanf("%s",ch);
			if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)  //��Сд������
			{
				for(j=i;j<m;j++)
				{
					stu[j]=stu[j+1];
				}
				 m--;
				 flag=1;
				if((fp=fopen("stu.txt","wb"))==NULL)
				{
					printf("�ļ���ʧ��\n");
					return;
				}
				for(j=0;j<m;j++)  //ͬ��
				{
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("���ܱ���\n");
						getchar();
					}
				}
				fclose(fp);
				printf("ɾ���ɹ���\n");break;

			}
			else
			{
			   printf("ѧ����Ϣ���ڣ�����Ҫɾ����");
			   break;
		    }
		}

	}
	if(m==i&&flag==0)
	{
		printf("δ�ҵ���ѧ��");
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
   printf("�ļ���ʧ��\n");
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
  	printf("�ļ���û������\n");
  }
   printf("ѧ��\t����\tʵ��γɼ�\t���޿γɼ�\tѡ�޿γɼ�\t�ܳɼ�\n");
   for(i=0;i<m;i++)
   {
     printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].expe,stu[i].requ,stu[i].elec,stu[i].sum);
    }
}

