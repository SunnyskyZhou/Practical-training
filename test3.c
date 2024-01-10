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
    //void exit();  �˳� 0
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
	system("color f0\n");	//�׵׺��ֵ�ɫ�� 
	int n;
  	menu();
  	scanf("%d",&n);  //����ѡ���ܵı��
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
    menu();  //ִ���깦���ٴ���ʾ�˵�����
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
    printf("\t\t||                ��ѡ��<0-8>                    ||\n");
    printf("\t\t---------------------------------------------------\n");
}

void in()  //1.¼�� 
{
   int i,m=0;/*m�Ǽ�¼������*/
      char ch[2];
      FILE *fp;/*�����ļ�ָ��*/
      if((fp=fopen("data.txt","a+"))==NULL)/*��ָ���ļ�*/
      { 
          printf("�ļ������ڣ�\n");
          return;//ֱ�ӷ��أ�����ִ��
      }
      while(!feof(fp))//�ж��Ƿ�ָ�������
    {
          if(fread(&stu[m] ,LEN,1,fp)==1)
        {
              m++;/*ͳ�Ƶ�ǰ��¼����*/
        }
      }
      fclose(fp);
      if(m==0)
      {
          printf("�ļ���û�м�¼!\n");
    }
      else
      {          
        show();/*����show��������ʾԭ����Ϣ*/
      }
      if((fp=fopen("data.txt","wb"))==NULL)
      {
          printf("�ļ������ڣ�\n");
          return;
      }


      printf("����ѧ����Ϣ(y/n):");
      scanf("%s",ch);
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
    {
        printf("number:");
        scanf("%d",&stu[m].num);/*����ѧ��ѧ��*/
        for(i=0;i<m;i++)
            if(stu[i].num==stu[m].num)
            {
                   printf("���ѧ���Ѿ������ˣ������������!");
                getch();
                fclose(fp);
                return;
            }
         printf("name:");
         scanf("%s",stu[m].name);/*����ѧ������*/
         printf("elec:");
        scanf("%lf",&stu[m].elec);/*����ѡ�޿γɼ�*/
         printf("expe:");
         scanf("%lf",&stu[m].expe);/*����ʵ��γɼ�*/
         printf("requ:");
         scanf("%lf",&stu[m].requ);/*������޿γɼ�*/
         stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;/*������ܳɼ�*/
         if(fwrite(&stu[m],LEN,1,fp)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
         {
             printf("���ܱ���!");
             getch();
         }
         else
         {
             printf("%s ������!\n",stu[m].name);
             m++;
         }
         printf("����?(y/n):");/*ѯ���Ƿ����*/
         scanf("%s",ch);
      }
      fclose(fp);
      printf("OK!\n");
}

void search()  //2.��ѯ 
{
	int num,m=0;  //ͬ��
	int i;
	FILE *fp;
	if((fp=fopen("data.txt","r"))==NULL)
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

void del()  //3.ɾ�� 
{
    void print();  //ͬ��
	FILE *fp;
	int num,m=0;  //mΪѧ������
	int i,j;  //iΪ��λѧ��λ�õ�����ѧ��,jΪm-1��ֵ
	int flag=0;
	char ch[2];
	if((fp=fopen("data.txt","r"))==NULL)
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

void modify()  //4.�޸� 
{
	void print();
	int num;  //����ѧ�� 
	char name[50]; //��������
	double expe;  //����ʵ��� 
    double requ;  //�������޿� 
    double elec;  //����ѡ�޿�
    
	FILE *fp;
	int m=0,a;
	int i,j;
	if((fp=fopen("data.txt","r"))==NULL)
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
	 	printf("\n");
	 	printf("��������Ҫ�޸�ѧ����Ϣ��ѧ�ţ�");
	 	scanf("%d",&num); 
	}
	for(i=0;i<m;i++)
	{
	 	if(num==stu[i].num)
	 	{
	      printf("1:ѧ�ţ�2:������3:ʵ��γɼ���4:���޿γɼ���5:ѡ�޿γɼ�\n");
		  printf("��ѧ���ѱ��ҵ�����ѡ����Ҫ�޸ĵ�����(1-5)��");		  
		  scanf("%d",&a);
		  while(a)
		  { 		 
			  switch (a) 
			  {
			  	
			  	case 1:
			  		printf("��%dѧ����ѧ���޸�Ϊ��",num); 
			  		scanf("%d",&num);
					stu[i].num=num;
					for(j=i+1;j<m;j++)
					{
						if(stu[j].num==num)
						{
							printf("���޸ĵ�ѧ���Ѵ���\n");
							getchar();
							return;
						}
					}   
			  		break;
			  		
			  	case 2:
				  	printf("��%dѧ���������޸�Ϊ��",num); 
				  	scanf("%s",name);
				  	strcpy(stu[i].name,name);
				  	break;
					  	
			  	case 3:
			  		printf("��%dѧ����ʵ��γɼ��޸�Ϊ��",expe); 
			  		scanf("%f",&expe);
					stu[i].expe=expe;
			  		stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
			  		
				case 4:
			  		printf("��%dѧ���ı��޿γɼ��޸�Ϊ��",requ); 
			  		scanf("%f",&requ);
			  		stu[i].requ=requ;
			  		stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
			  		
				case 5:
			  		printf("��%dѧ����ѡ�޿γɼ��޸�Ϊ��",elec);
					scanf("%f",&elec);
					stu[i].elec=elec;
					stu[i].sum=stu[i].expe+stu[i].requ+stu[i].elec;
			  		break;
					  	  	  	  	
			  	default:
			  	    printf("ѡ�����������ѡ����Ҫ�޸ĵ����ݣ�");
					scanf("%d",&a);   
			  		break;
			    }
			  
			  printf("��ѡ����Ҫ�޸ĵ�����(������޸�����밴0)��");
			  scanf("%d",&a);
		    }
			if((fp=fopen("stu.txt","wb"))==NULL)
				{
					printf("�ļ���ʧ��\n");
					return;
				}
				for(j=0;j<m;j++)
				{
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("���ܱ���\n");
						getchar();
					}
				}
				fclose(fp);
				printf("�޸ĳɹ���\n");
				break;	 	
	    }
    }
    if(m==i)
    {
    	printf("δ�ҵ���ѧ��\n"); 
	}
}

void insert()  //5.���� 
{
    FILE *fp;
      int i,j,k,m=0,snum;
      if((fp=fopen("data.txt","r+"))==NULL)
    { 
        printf("�ļ���ʧ��\n");
        return;
    }
      while(!feof(fp))  
         if(fread(&stu[m],LEN,1,fp)==1) 
         m++;
      if(m==0) 
    {
          printf("�ļ���û�м�¼!\n");
          fclose(fp);
          return;
      }
      printf("������Ҫ�����λ��(number)��\n");
      scanf("%d",&snum);//����Ҫ�����λ��
    for (i = 0; i < m; i++)
        if (snum == stu[i].num)//�ж��Ƿ����
            break;                                          
          for(j=m-1;j>i;j--)//ѧ�����������
               stu[j+1]=stu[j];//�����һ����¼��ʼ�������һλ
          printf("����������Ҫ�����ѧ����Ϣ.\n");
              printf("ѧ��:");
          scanf("%d",&stu[i+1].num);
          for(k=0;k<m;k++)//�ж��Ƿ����
            if(stu[k].num==stu[m].num)
            {
                printf("ѧ���Ѿ����ڣ������������!");
                getch();
                fclose(fp);
                return;
            }
          printf("����:");
          scanf("%s",stu[i+1].name);
              printf("ѡ�޿γɼ�:");
          scanf("%lf",&stu[i+1].elec);
              printf("ʵ��γɼ�:");
          scanf("%lf",&stu[i+1].expe);
              printf("���޿γɼ�:");
          scanf("%lf",&stu[i+1].requ);
          stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ;
          printf("����ɹ�������������������棡"); 
          if((fp=fopen("data.txt","wb"))==NULL)
        { 
             printf("���ܴ򿪣�\n");
             return;
        }
          for(k=0;k<=m;k++)
          if(fwrite(&stu[k] ,LEN,1,fp)!=1)//���޸ĺ�ļ�¼д������ļ���
           { 
           printf("���ܱ���!"); 
           getch(); 
        }
      fclose(fp);
}

void order()  //6.���� 
{
    FILE *fp;
      struct student t;
      int i=0,j=0,m=0;
      if((fp=fopen("data.txt","r+"))==NULL)
    { 
        printf("�ļ������ڣ�\n");
        return;
      }
      while(!feof(fp)) 
     if(fread(&stu[m] ,LEN,1,fp)==1) 
          m++;
      fclose(fp);
      if(m==0) 
      {
          printf("�ļ���û�м�¼!\n");
          return;
      }
      if((fp=fopen("data.txt","wb"))==NULL)
    {
          printf("�ļ������ڣ�\n");
          return;
    }
    for (i = 0; i < m - 1; i++)
        for (j = i + 1; j < m; j++)/*˫��ѭ��ʵ�ֳɼ��Ƚϲ�����*/
            if (stu[i].sum < stu[j].sum)                                         
            {                                                                          
              t=stu[i];stu[i]=stu[j];stu[j]=t;
        }
    if((fp=fopen("data.txt","wb"))==NULL)
    { 
        printf("�ļ������ڣ�\n");
        return;
    }
      for(i=0;i<m;i++)/*�������ź������������д��ָ���Ĵ����ļ���*/
          if(fwrite(&stu[i] ,LEN,1,fp)!=1)
           { 
            printf("%s ���ܱ����ļ�!\n"); 
            getch();
          }
      fclose(fp);
      printf("����ɹ�\n");
}

void total()  //7.ͳ�� 
{
	FILE *fp;
	int m=0;
	if((fp=fopen("data.txt","r"))==NULL)
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
		  if(m==0)
		  {
		  	printf("�ļ���û������\n");
		  	return;
		}
    printf("ѧ����������%d\n", m);
    fclose(fp);
}

void show()  //8.��ʾ 
{
    int i,m=0;
  FILE *fp;
  if((fp=fopen("data.txt","r"))==NULL)
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


