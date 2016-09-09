#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"zhubo.h"

void printHead( )      /*��ӡ������Ϣ�ı�ͷ*/
{
printf("%8s%8s%8s%8s%8s\n","����","�Ա�","�����","����","��ʱ��");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. ������Ϣͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����������¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��������¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�������¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��������Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ������ֱ��ʱ�� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ������ʱ������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}

void menuCount( )    /*4��������Ϣͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ��ֱ���ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��ֱ�����ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 3. ��ֱ��ƽ��ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ������Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(zhubo zhu[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*������Ž��в���ɾ���޸ģ�ѧ�Ų����ظ�*/
{
		int choice,t,find[NUM];
     zhubo z;
do
	    {
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readzhu(&z,1);       /*����һ���������������¼*/
					 n=insertzhu(zhu,n,z);   /*���ú�������������¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&z.num);  /*����һ����ɾ��������ѧ��*/
					 n=deletezhu(zhu,n,z);   /*���ú���ɾ��ָ��ѧ�ŵ�������¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&z.num);  /*����һ�����޸ĵ����������*/
				      t=searchzhu(zhu,n,z,1,find) ; /*���ú�������ָ����������Ϣ��¼*/
				      if (t)                 /*����������ļ�¼����*/
					 {
						  readzhu(&z,1);   /*����һ��������������¼��Ϣ*/
					      zhu[find[0]]=z;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/
					  }
					 else                 /*����������ļ�¼������*/
 printf("this student is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(zhubo zhu[],int n)          /*�ú������������Ϣ������*/
{
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(zhu,n);         /*�������������ܷ�*/
					  break;
			case 2:   calcuRank(zhu,n);         /*����������������ʱ��������*/
				      break;
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[7][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ�����̡�ƽ��*/
int i;
    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i��������*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(zhubo zhu[],int n)               /*�ú������������Ϣͳ�ƹ���*/
{
		int choice;
		double mark[7][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,zhu,n);                 /*���ô˺���������������̡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("ֱ��ʱ�������:\n",mark,0);  /*����*/
				      break;
				case 2:   printMarkCourse("ֱ��ʱ����̵���:\n",mark,1);  /*������*/
				      break;
				case 3:   printMarkCourse("ֱ����ƽ��ʱ����:\n",mark,2);  /*���ƽ��*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(zhubo zhu[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
zhubo z;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a zhubo\'s num will be searched:\n");
				      scanf("%ld",&z.num);         /*�������ѯ������ѧ��*/
					  break;
				case 2:   printf("Input a zhubo\'s name will be searched:\n");
				      scanf("%s",z.name);	          /*�������ѯ����������*/
				      break;

				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{
				findnum=searchzhu(zhu,n,z,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printzhu(&zhu[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }
	    }while (choice);
}

int runMain(zhubo zhu[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortzhu(zhu,n,1);         /*��ѧ����С�����˳�������¼*/
          	 printzhu(zhu,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(zhu,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(zhu,n);     /* 3. ������Ϣ����*/
					break;
			case 4: countManage(zhu,n);     /* 4. ������Ϣͳ��*/
					break;
			case 5: searchManage(zhu,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		zhubo zhu[NUM];                /*����ʵ��һά����洢������¼*/
      int choice,n;
	 n=readFile(zhu);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(zhu);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(zhu,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortzhu(zhu,n,1);                   /*�����ļ�ǰ����ʱ����С��������*/
	     saveFile(zhu,n);                   /*����������ļ�*/
      return 0;
}
