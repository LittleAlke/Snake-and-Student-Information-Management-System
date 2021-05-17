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
	printf("       <<<<<<<<欢迎使用成绩管理系统>>>>>>>>         \n"); 
    printf("----------------------------------------------------\n");
    printf("※※  1.录入(追加)                  2.成绩排序  ※※\n");
	printf("※※  3.查询                        4.查看全部  ※※\n");
	printf("※※  5.修改信息                    6.删除信息  ※※\n");
	printf("※※  7.退出                                    ※※\n"); 
	printf("----------------------------------------------------\n");
	printf("请输入使用功能的序号：");
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
				default:printf("请输入正确的选项！\n");
	} 
	writefile();
}                                //主菜单 

struct student//定义结构体 
{
	int Class;
	int number;
	char name[20];
	float score1;
	float score2;
	float score3;
	float score4;
	float score5;
	float avscore;           //平均成绩 
}students[100];                               
int s=0;                         //为后续学生数组的输入数据初始化 

void luru()//录入（追加）成绩 
{
	
	int zong;
	//float pingjun(struct student stu); 
	while(1)
   	{
		printf("请输入班级：");
		scanf("%d",&students[s].Class);
		getchar();                                  //接收回车键 
		printf("请输入学号：");
		scanf("%d",&students[s].number);
		getchar();
		printf("请输入姓名：");
		scanf("%s",students[s].name);//不用带地址符号 
		getchar();
		printf("请输入第一科的成绩：");
		scanf("%f",&students[s].score1);                                    
		getchar();
		printf("请输入第二科的成绩：");
		scanf("%f",&students[s].score2);
		getchar();
    	printf("请输入第三科的成绩：");
    	scanf("%f",&students[s].score3);
    	getchar();
		printf("请输入第四科的成绩：");
		scanf("%f",&students[s].score4);
		getchar();
		printf("请输入第五科的成绩：");
		scanf("%f",&students[s].score5);
		getchar();
		zong=students[s].score1+students[s].score2+students[s].score3+students[s].score4+students[s].score5;
		students[s].avscore=zong/5;
		s++;
		printf("是否继续录入？（是则输入y，否则输入n。）");
		if(getchar()=='n') 
		{
			//void writefile();
			break;
		}
		
	}
}  

void xiugai()//修改信息 
{
	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
	int zong;
  while(1)
  {
  	char namec[20];
  	int a,j,numberc;
  	printf("请选择删除对象的查询方式并输入对应的数字： 1.学号   2.姓名\n");
  	scanf("%d",&a);
  	if(a==1)
  	{
  	  printf("请输入学号");
  	  scanf("%d",&numberc);
  	  getchar();
  	  j=number_chaxun(numberc);
  	}
  	else
  	   {
  		 printf("请输入姓名");
  		 scanf("%s",namec);//不 
  		 getchar();
  		 j=name_chaxun(namec);
  	   }
  	if(j==-1)
  	{
  		printf("学生不存在！\n");
  	}
  	else
  	  {
  		printf("您要修改的学生信息为：\n");
  		xianshiD(j);
  		printf("-----请输入修改后的信息：-----\n");
  		printf("请输入班级:");
  		scanf("%d",&students[j].Class);
  		getchar();
  		
  		printf("请输入学号:");
  		scanf("%d",&students[j].number);
  		getchar();
  		
  		printf("请输入姓名:");
  		scanf("%s",students[j].name);
  		getchar();
  		
  		printf("请输入科目一的成绩:");
  		scanf("%f",&students[j].score1);
  		getchar();
  		
  		printf("请输入科目二的成绩:");
  		scanf("%f",&students[j].score2);
  		getchar();
  		
  		printf("请输入科目三的成绩:");
  		scanf("%f",&students[j].score3);
  		getchar();
  		
  		printf("请输入科目四的成绩:");
  		scanf("%f",&students[j].score4);
  		getchar();
  		
  		printf("请输入科目五的成绩:");
  		scanf("%f",&students[j].score5);
  		getchar();
  		zong=students[s].score1+students[s].score2+students[s].score3+students[s].score4+students[s].score5;
  		students[s].avscore=zong/5;
  	  }
  	printf("是否继续修改？（是则输入y，否则输入n。）");
  	if(getchar()=='n')
  	 {
  	 	break;
  	 }
  }
}
 
void shanchu()//删除学生信息 
{
	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
	int i;
	while(i)
	{
	 char namec[20];
	 int a,j,numberc;
	 printf("请选择删除对象的查询方式并输入对应的数字： 1.学号   2.姓名\n");
	 scanf("%d",&a);
	 if(a==1)
	 {
	   printf("请输入学号");
	   scanf("%d",&numberc);
	   getchar();
	   j=number_chaxun(numberc);	
	 }
	 else
	 {
	   printf("请输入姓名");
	   scanf("%s",namec);
	   getchar();
	   j=name_chaxun(namec);
	 }
	 if(j==-1)
	 {
	 	printf("学生不存在！\n");
	 }
	 else
	 {
	  printf("您要删除的学生信息为：\n");
	  xianshiD(j);
	  printf("是否真的要删除？（是则输入y，否则输入n。）");
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
	 printf("是否继续删除？（是则输入y，否则输入n。）");
	 if(getchar()=='n')
	  {
	 	break;
	  }
	}
}
                          
/*float pingjun(struct student stu) //求平均值 
{
	float a;
	a=(stu.score1+stu.score2+stu.score3+stu.score4+stu.score.5)/5
	return(a);
} */
                                                    

int name_chaxun(char namec[20])//通过姓名返回数组下标 
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

int number_chaxun(int numberc)//通过学号返回数组下标 
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

void paixu()//按平均成绩排序 
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

 void chaxun()//查询 
 {
 	int number_chaxun(int numberc);
	int name_chaxun(char namec[20]);
	void xianshiD(int j);
 	while(1)
 	{
 		char namec[20];
 		int a,j,numberc;
 		printf("请选择查询方式并输入对应的数字： 1.学号   2.姓名\n");
 		scanf("%d",&a);
 		if(a==1)
 		 {
 			printf("请输入学号：");
			scanf("%d",&numberc);
			getchar();
			j=number_chaxun(numberc);
 		 }
 		else
 		  {
 		   printf("请输入要查询学生的姓名：");
 		   scanf("%s",namec);
 	  	   getchar();
 		   j=name_chaxun(namec);
 	      }
 		if(j==-1)
 		  {
 			printf("学生不存在！\n");
 		  }
 		else
 		   {
 			printf("你要查询的学生信息为：\n");
 			xianshiD(j);
 		   }
 		printf("是否继续查询？（是则输入y，否则输入n。）");
 		if(getchar()=='n')
 		{
 			break;
 		}
 	}
 }

void xianshiD(int j)//显示单条学生信息 
{
	printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","班级","学号","姓名","成绩一","成绩二","成绩三","成绩四","成绩五","平均成绩");
    printf("-----------------------------------------------------------------------------------\n");
    printf("%8d%8d%8s%8.2f%8.2f%8.2f%8.2f%8.2f%8.2f\n",students[j].Class,students[j].number,students[j].name,students[j].score1,students[j].score2,
	                                                    students[j].score3,students[j].score4,students[j].score5,students[j].avscore);
}
	

void xianshi()//显示所有学生信息 
{
	int i;
	printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","班级","学号","姓名","成绩一","成绩二","成绩三","成绩四","成绩五","平均成绩");
	printf("-----------------------------------------------------------------------------------\n");
	for(i=0;i<s;i++)
	{
	 printf("%8d%8d%8s%8.2f%8.2f%8.2f%8.2f%8.2f%8.2f\n",students[i].Class,students[i].number,students[i].name,students[i].score1,students[i].score2,
	 	                                          students[i].score3,students[i].score4,students[i].score5,students[i].avscore);
	}
}

void readfile()//从文件中将信息读出 
{
	FILE *fp;
	int i;
	if((fp=fopen("Alke.txt","rb"))==NULL)
	{
		printf("不能打开文件！\n");
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

void writefile()//将信息写入文件中 
{
	FILE *fp;
	int i;
	if((fp=fopen("Alke.txt","wb"))==NULL)
	{
		printf("不能打开文件！\n");
		return;
	}
	if(fwrite(&s,sizeof(int),1,fp)!=1)
	{
		printf("写入文件错误！\n");
	}
	for(i=0;i<s;i++)
	{
		if(fwrite(&students[i],sizeof(struct student),1,fp)!=1)
		{
			printf("写入文件错误！\n");
		}
	}
	fclose(fp);
}
