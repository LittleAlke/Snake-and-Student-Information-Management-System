#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define SIZE 10
int main()
{   void luru();
    void xiugai();
    void shanchu();
    //void pingjun(struct student stu);
    int name_chaxun(char namec[]);
    int number_chaxun(int numberc);
    void paixu();
    void chaxun();
    void xianshiD(int j);
    void xianshi();
    void readfile();
    void writefile();
	int xuanze;
	readfile();
	printf("       <<<<<<<<��ӭʹ�óɼ�����ϵͳ>>>>>>>>         \n"); 
    printf("----------------------------------------------------\n");
    printf("����  1.¼��(׷��)                  2.�ɼ�����  ����\n");
	printf("����  3.��ѯ                        4.�鿴ȫ��  ����\n");
	printf("����  5.�޸���Ϣ                    6.ɾ����Ϣ  ����\n");
	printf("����  7.�˳�                                    ����\n"); 
	printf("----------------------------------------------------\n");
	printf("������ʹ�ù��ܵ���ţ�");
	scanf("%d",&xuanze);
	switch(xuanze)
	{
		case 1:luru();
		        break;
		case 2:paixu();
		        xianshi();
		        break;
		case 3:chaxun();
		        break;
		case 4:xianshi();
		        break;  
		case 5:xiugai();
		        break;
		case 6:shanchu();
		        break;
		case 7:return(0);
		        break;	
				default:printf("��������ȷ��ѡ�\n");
	} 
	writefile();
}                                //���˵� 

struct student//����ṹ�� 
{
	int Class;
	int number;
	char name[20];
	float score1;
	float score2;
	float score3;
	float score4;
	float score5;
	float avscore;           //ƽ���ɼ� 
}students[100];                               
int s=0;                         //Ϊ����ѧ��������������ݳ�ʼ�� 

void luru()//¼�루׷�ӣ��ɼ� 
{
	
	int zong;
	//float pingjun(struct student stu); 
	while(1)
   	{
		printf("������༶��");
		scanf("%d",&students[s].Class);
		getchar();                                  //���ջس��� 
		printf("������ѧ�ţ�");
		scanf("%d",&students[s].number);
		getchar();
		printf("������������");
		scanf("%s",students[s].name);//���ô���ַ���� 
		getchar();
		printf("�������һ�Ƶĳɼ���");
		scanf("%f",&students[s].score1);                                    
		getchar();
		printf("������ڶ��Ƶĳɼ���");
		scanf("%f",&students[s].score2);
		getchar();
    	printf("����������Ƶĳɼ���");
    	scanf("%f",&students[s].score3);
    	getchar();
		printf("��������ĿƵĳɼ���");
		scanf("%f",&students[s].score4);
		getchar();
		printf("���������Ƶĳɼ���");
		scanf("%f",&students[s].score5);
		getchar();
		zong=students[s].score1+students[s].score2+students[s].score3+students[s].score4+students[s].score5;
		students[s].avscore=zong/5;
		s++;
		printf("�Ƿ����¼�룿����������y����������n����");
		if(getchar()=='n') 
		{
			//void writefile();
			break;
		}
		
	}
}  

void xiugai()//�޸���Ϣ 
{
	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
	int zong;
  while(1)
  {
  	char namec[20];
  	int a,j,numberc;
  	printf("��ѡ��ɾ������Ĳ�ѯ��ʽ�������Ӧ�����֣� 1.ѧ��   2.����\n");
  	scanf("%d",&a);
  	if(a==1)
  	{
  	  printf("������ѧ��");
  	  scanf("%d",&numberc);
  	  getchar();
  	  j=number_chaxun(numberc);
  	}
  	else
  	   {
  		 printf("����������");
  		 scanf("%s",namec);//�� 
  		 getchar();
  		 j=name_chaxun(namec);
  	   }
  	if(j==-1)
  	{
  		printf("ѧ�������ڣ�\n");
  	}
  	else
  	  {
  		printf("��Ҫ�޸ĵ�ѧ����ϢΪ��\n");
  		xianshiD(j);
  		printf("-----�������޸ĺ����Ϣ��-----\n");
  		printf("������༶:");
  		scanf("%d",&students[j].Class);
  		getchar();
  		
  		printf("������ѧ��:");
  		scanf("%d",&students[j].number);
  		getchar();
  		
  		printf("����������:");
  		scanf("%s",students[j].name);
  		getchar();
  		
  		printf("�������Ŀһ�ĳɼ�:");
  		scanf("%f",&students[j].score1);
  		getchar();
  		
  		printf("�������Ŀ���ĳɼ�:");
  		scanf("%f",&students[j].score2);
  		getchar();
  		
  		printf("�������Ŀ���ĳɼ�:");
  		scanf("%f",&students[j].score3);
  		getchar();
  		
  		printf("�������Ŀ�ĵĳɼ�:");
  		scanf("%f",&students[j].score4);
  		getchar();
  		
  		printf("�������Ŀ��ĳɼ�:");
  		scanf("%f",&students[j].score5);
  		getchar();
  		zong=students[s].score1+students[s].score2+students[s].score3+students[s].score4+students[s].score5;
  		students[s].avscore=zong/5;
  	  }
  	printf("�Ƿ�����޸ģ�����������y����������n����");
  	if(getchar()=='n')
  	 {
  	 	break;
  	 }
  }
}
 
void shanchu()//ɾ��ѧ����Ϣ 
{
	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
	int i;
	while(i)
	{
	 char namec[20];
	 int a,j,numberc;
	 printf("��ѡ��ɾ������Ĳ�ѯ��ʽ�������Ӧ�����֣� 1.ѧ��   2.����\n");
	 scanf("%d",&a);
	 if(a==1)
	 {
	   printf("������ѧ��");
	   scanf("%d",&numberc);
	   getchar();
	   j=number_chaxun(numberc);	
	 }
	 else
	 {
	   printf("����������");
	   scanf("%s",namec);
	   getchar();
	   j=name_chaxun(namec);
	 }
	 if(j==-1)
	 {
	 	printf("ѧ�������ڣ�\n");
	 }
	 else
	 {
	  printf("��Ҫɾ����ѧ����ϢΪ��\n");
	  xianshiD(j);
	  printf("�Ƿ����Ҫɾ��������������y����������n����");
	  if(getchar()=='y')
	  {
	  	for(i=j;i<s-1;i++)
	  	{
	  		students[i]=students[i+1];
	  	}
	  	s--;
	  }
	  getchar();
	 }
	 printf("�Ƿ����ɾ��������������y����������n����");
	 if(getchar()=='n')
	  {
	 	break;
	  }
	}
}
                          
/*float pingjun(struct student stu) //��ƽ��ֵ 
{
	float a;
	a=(stu.score1+stu.score2+stu.score3+stu.score4+stu.score.5)/5
	return(a);
} */
                                                    

int name_chaxun(char namec[20])//ͨ���������������±� 
{
   int i;
   for(i=0;i<s;i++)
   {
   	if(strcmp(students[i].name,namec)==0)
   	 {
   	    return(i);
     }
   }
   return(-1);
}

int number_chaxun(int numberc)//ͨ��ѧ�ŷ��������±� 
{
	int i;
	for(i=0;i<s;i++)
	{
		if(numberc==students[i].number)
		{
			return(i);
			break;
		}
	}
	return(-1);
}

void paixu()//��ƽ���ɼ����� 
{
     int i,j;
     struct student studentH;
     for (i=0;i<s;i++)
     {
         for (j=1;j<s-i;j++)
         {
              if (students[j-1].avscore<students[j].avscore)
              {
                   studentH=students[j-1];
                   students[j-1]=students[j];
                   students[j]=studentH;
              }
         }
     }

}

 void chaxun()//��ѯ 
 {
 	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
 	while(1)
 	{
 		char namec[20];
 		int a,j,numberc;
 		printf("��ѡ���ѯ��ʽ�������Ӧ�����֣� 1.ѧ��   2.����\n");
 		scanf("%d",&a);
 		if(a==1)
 		 {
 			printf("������ѧ�ţ�");
			scanf("%d",&numberc);
			getchar();
			j=number_chaxun(numberc);
 		 }
 		else
 		  {
 		   printf("������Ҫ��ѯѧ����������");
 		   scanf("%s",namec);
 	  	   getchar();
 		   j=name_chaxun(namec);
 	      }
 		if(j==-1)
 		  {
 			printf("ѧ�������ڣ�\n");
 		  }
 		else
 		   {
 			printf("��Ҫ��ѯ��ѧ����ϢΪ��\n");
 			xianshiD(j);
 		   }
 		printf("�Ƿ������ѯ������������y����������n����");
 		if(getchar()=='n')
 		{
 			break;
 		}
 	}
 }

void xianshiD(int j)//��ʾ����ѧ����Ϣ 
{
	printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","�༶","ѧ��","����","�ɼ�һ","�ɼ���","�ɼ���","�ɼ���","�ɼ���","ƽ���ɼ�");
    printf("-----------------------------------------------------------------------------------\n");
    printf("%8d%8d%8s%8.2f%8.2f%8.2f%8.2f%8.2f%8.2f\n",students[j].Class,students[j].number,students[j].name,students[j].score1,students[j].score2,
	                                                    students[j].score3,students[j].score4,students[j].score5,students[j].avscore);
}
	

void xianshi()//��ʾ����ѧ����Ϣ 
{
	int i;
	printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","�༶","ѧ��","����","�ɼ�һ","�ɼ���","�ɼ���","�ɼ���","�ɼ���","ƽ���ɼ�");
	printf("-----------------------------------------------------------------------------------\n");
	for(i=0;i<s;i++)
	{
	 printf("%8d%8d%8s%8.2f%8.2f%8.2f%8.2f%8.2f%8.2f\n",students[i].Class,students[i].number,students[i].name,students[i].score1,students[i].score2,
	 	                                          students[i].score3,students[i].score4,students[i].score5,students[i].avscore);
	}
}

void readfile()//���ļ��н���Ϣ���� 
{
	FILE *fp;
	int i;
	if((fp=fopen("Alke.txt","rb"))==NULL)
	{
		printf("���ܴ��ļ���\n");
		return;
	}
	if(fread(&s,sizeof(int),1,fp)!=1)
	{
		s=-1;
	}
	else
	{
		for(i=0;i<s;i++)
		{
			fread(&students[i],sizeof(struct student),1,fp);
		}
	}
	fclose(fp);
}

void writefile()//����Ϣд���ļ��� 
{
	FILE *fp;
	int i;
	if((fp=fopen("Alke.txt","wb"))==NULL)
	{
		printf("���ܴ��ļ���\n");
		return;
	}
	if(fwrite(&s,sizeof(int),1,fp)!=1)
	{
		printf("д���ļ�����\n");
	}
	for(i=0;i<s;i++)
	{
		if(fwrite(&students[i],sizeof(struct student),1,fp)!=1)
		{
			printf("д���ļ�����\n");
		}
	}
	fclose(fp);
}
