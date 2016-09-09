/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"employee.h"

void printHead( )      /*��ӡԱ����Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","����","����","�Ա�","˰��","��������","����","�ܹ���","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. Ա�����ʹ��� ********\n");
		printf("******** 4. ����ͳ�Ʒ��� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��Ա�����ʹ���˵�����*/
{
		printf("@@@@@@@ 1. ����Ա���ܹ��� @@@@@@@\n");
		printf("@@@@@@@ 2. �����ܹ������� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4������ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����˰�ѡ��ܻ������ʡ��ܽ��� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����β�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Employee emp[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ����Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Employee e;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readEmp(&e,1);       /*����һ���������Ա����¼*/
					 n=insertEmp(emp,n,e);   /*���ú�������Ա����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&e.num);  /*����һ����ɾ����Ա������*/
					 n=deleteEmp(emp,n,e);   /*���ú���ɾ��ָ�����ŵ�Ա����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&e.num);  /*����һ�����޸ĵ�Ա������*/
				      t=searchEmp(emp,n,e,1,find) ; /*���ú�������ָ�����ŵ�Ա����¼*/
				      if (t)                 /*����ù��ŵļ�¼����*/
					 {
						  readEmp(&e,1);   /*����һ��������Ա����¼��Ϣ*/
					      emp[find[0]]=e;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ù��ŵļ�¼������*/ 
 printf("this employee is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Employee emp[],int n)          /*�ú������Ա�����ʹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(emp,n);         /*��Ա�����ܹ���*/
					  break;
			case 2:   calcuRank(emp,n);         /*��������Ա�����ܹ���������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *e,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��˰�ѡ��ܻ������ʡ��ܽ���*/
int i;
    printf(e);                                  /*�����e�������������ʵ���ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ�ſ�*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Employee emp[],int n)               /*�ú�����ɹ���ͳ�Ʒ�������*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,emp,n);                 /*���ô˺��������ſε���ߡ���͡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
			    case 1:   printMarkCourse("����Ա����˰�ѡ��ܻ������ʡ��ܽ�����:\n",mark,2);  /*����ܽ���*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Employee emp[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
    Employee e;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a employee\'s num will be searched:\n");
				      scanf("%ld",&e.num);         /*�������ѯԱ����ѧ��*/
					  break;
				case 2:   printf("Input a employee\'s name will be searched:\n");
				      scanf("%s",e.name);	          /*�������ѯԱ��������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&e.rank);          /*�������ѯԱ���Ĺ�������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchEmp(emp,n,e,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printEmp(&emp[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Employee emp[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortEmp(emp,n,1);         /*��������С�����˳�������¼*/ 
          	 printEmp(emp,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(emp,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(emp,n);     /* 3. Ա�����ʹ���*/
					break;
			case 4: countManage(emp,n);     /* 4. ����ͳ�Ʒ���*/
					break;
			case 5: searchManage(emp,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Employee emp[NUM];                /*����ʵ��һά����洢Ա����¼*/
      int choice,n;
	 n=readFile(emp);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(emp);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(emp,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortEmp(emp,n,1);                   /*�����ļ�ǰ��������С��������*/ 
	     saveFile(emp,n);                   /*����������ļ�*/
      return 0;
}
