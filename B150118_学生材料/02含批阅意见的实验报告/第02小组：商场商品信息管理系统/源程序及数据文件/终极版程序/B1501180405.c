/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"product.h"
int baseManage(Product pro[],int n);

void printHead( )      /*��ӡ��Ʒ��Ϣ�ı�ͷ*/
{
printf("%4s%4s%12s%8s%8s%10s%9s\n","","��Ʒ���","����","Ʒ��","�۸�","���","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1.��ʾ������Ϣ ********\n");
		printf("******** 2.������Ϣ���� ********\n");
		printf("******** 3.��Ʒ�۸���� ********\n");
		printf("******** 4.��Ʒ���ͳ�� ********\n");
        printf("******** 5.����������ѯ ********\n");
		printf("******** 0.�˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuPrice( )     /*3����Ʒ�۸����˵�����*/
{
		printf("@@@@@@@@ 1. ������Ʒ�ܼ� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݼ۸����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4����Ʒ���ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����϶�  &&&&&&&&\n");
		printf("&&&&&&&& 2. �������  &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵�&&&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ʒ��Ų�ѯ########\n");
		printf("######## 2. �����Ʋ�ѯ    ########\n");
		printf("######## 3. ��Ʒ�Ʋ�ѯ    ########\n");
		printf("######## 0. �����ϲ�˵�  ########\n");
}


void priceManage(Product pro[],int n)          /*�ú��������Ʒ�۸������*/
{  
	int choice;
	do
	{
		menuPrice( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(pro,n);         /*��������Ʒ���ܼ۸�*/
					  break;
			case 2:   calcuRank(pro,n);         /*������Ʒ�ļ۸�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *s,int m[2],int k)   /*��ӡ���ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1�ֱ��Ӧ���϶ࡢ����*/

          printf(s);                                  /*�����s����������������ʾ��Ϣ*/
		  printf("%10d",m[k]);
	      printf("\n");
}

void countManage(Product pro[],int n)               /*�ú��������Ʒ���ͳ�ƹ���*/
{
	
		int mark[2];
		int choice;
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,pro,n);                 /*���ô˺�������϶༰������Ʒ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  printMarkCourse("�϶�����:\n",mark,0);
			              break;
				case 2:  printMarkCourse("���ٿ����:\n",mark,1);
				          break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Product pro[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Product s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a product\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ��Ʒ�ı��*/
					  break;
				case 2:   printf("Input a product\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ��Ʒ������*/		  
				      break;   
				case 3:   printf("Input a brand will be searched:\n");
				      scanf("%s",&s.brand);          /*�������ѯ��Ʒ��Ʒ��*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchPro(pro,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printPro(&pro[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Product pro[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortPro(pro,n,1);         /*�������С�����˳�������¼*/ 
          	 printPro(pro,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(pro,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: priceManage(pro,n);     /* 3. ��Ʒ�۸����*/
					break;
			case 4: countManage(pro,n);     /* 4. ���ͳ��*/
					break;
			case 5: searchManage(pro,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}


int baseManage(Product pro[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{
		int choice,t,find[NUM];
        Product  s;
  do
	    {   
  menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
  printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readPro(&s,1);       /*����һ�����������Ʒ��¼,��ʼ��s*/
					 n=insertPro(pro,n,s);   /*���ú���������Ʒ��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ������Ʒ���*/
					 n=deletePro(pro,n,s);   /*���ú���ɾ��ָ����ŵ���Ʒ��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ʒ���*/
				      t=searchPro(pro,n,s,1,find) ; /*���ú�������ָ����ŵ���Ʒ��¼*/
				      if (t)                 /*����ñ�ŵļ�¼����*/
					 {
						  readPro(&s,1);   /*����һ����������Ʒ��¼��Ϣ*/
					      pro[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
   printf("this product is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
			 }
		}while(choice);
  return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}




int main( )
{
		Product pro[NUM];                /*����ʵ��һά����洢��Ʒ��¼*/
      int choice,n;
	 n=readFile(pro);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {

		 n=createFile(pro);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pro,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPro(pro,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(pro,n);                   /*����������ļ�*/
      return 0;
}
/*��product.c�ļ�����������*/
#include "product.h"
#include <stdio.h>
int readPro(Product  *pro , int n)          /*������Ʒ��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one product\'s information\n");
		printf("num:  ");
	     scanf("%ld", &pro[i].num);
		if (pro[i].num==0) break;
		printf("name: ");
		scanf("%s",pro[i].name);	
		printf("brand:  ");
		scanf("%s",pro[i].brand);
    	    pro[i].total=0.0;                /*�ܼ���Ҫ������ã���ֵ��Ϊ0.0*/
		printf("Input the price of the product:\n");
	    scanf("%lf",&pro[i].price);
    	printf("count:  ");
		scanf("%d",&pro[i].count);
		pro[i].rank=0;                 /*������Ҫ���ݿ�������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}
void printPro ( Product  *pro , int n)       /*���������Ʒ��¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", pro[i].num);
		printf("%10s", pro[i].name);
		printf("%12s", pro[i].brand);
		printf("%10.2f",pro[i].price);
    	printf("%8d",pro[i].count);
		printf("%9d\n",pro[i].rank);
	}
}

int equal(Product s1,Product s2,int condition)  /*����ж�����Product��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�Ʒ��*/
	 {
	     if (strcmp(s1.brand,s2.brand)==0) 	return 1;
		else return 0;
     }
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚϼ۸�*/
		return s1.price==s2.price;
	else return 1;                       /*�����������1*/
} 

int larger(Product s1,Product s2,int condition)  /*����condition�����Ƚ�����Product��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚϼ۸�*/
		return s1.price>s2.price;	
	if (condition==3)                    /*�������condition��ֵΪ3����ȽϿ��*/
		return s1.count>s2.count;		
	else return 1; /*�����������1*/
}

void reverse(Product pro[],int n)             /*����Ԫ������*/
{
	int i;
	Product temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=pro[i];
		pro[i]=pro[n-1-i];
		pro[n-1-i]=temp;
	}
}

void calcuTotal(Product pro[],int n)         /*����������Ʒ���ܼ۸�*/
{
	int i;
	double s;
		pro[0].total =0;
		s=0;
	for (i=0;i<n;i++)                      /*ѭ������������Ʒ�۸�*/
	{           
			pro[i].total=(pro[i].price)*(pro[i].count);
			s=s+pro[i].total;
	}	
	
	printf("%.2f\n",s);
}

void sortPro(Product pro[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Product t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(pro[minpos],pro[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=pro[i];
			pro[i]=pro[minpos];
			pro[minpos]=t;
		}
	}
}


int searchPro(Product pro[],int n,Product s,int condition,int f[ ])  /*��pro��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(pro[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertPro(Product pro[],int n,Product s)              /*��Pro��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortPro(pro,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(pro[i],s,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(pro[i],s,1))                    /*���s���ڵ�ǰԪ��pro[i]�����˳�ѭ��*/
		break;
		pro[i+1]=pro[i];                         /*����Ԫ��pro[i]����һ��λ��*/
	}
	pro[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deletePro(Product pro[],int n,Product s)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(pro[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(pro[i],s,1)����*/ 
		pro[j]=pro[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
void calcuRank(Product pro[],int n)          /*���ݼ۸����������Ʒ���������۸���ͬ��������ͬ*/
{
	int i;	
	sortPro(pro,n,2);                     /*�ȵ���sortPro�㷨�����۸���С��������*/
	reverse(pro,n);                     /*�����ã��򰴼۸��ɴ�С������*/
	pro[0].rank=1; /*��һ����¼������һ����1*/
		for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(pro[i],pro[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����۸����*/
			pro[i].rank=pro[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			pro[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(int m[2],Product pro[],int n) 
{
	int i;
	m[0]=pro[0].count;
	for (i=1;i<n;i++)                 /*����϶�*/		
	{   
	    if (m[0]<pro[i].count)
				m[0]=pro[i].count;

	}
    m[1]=pro[0].count;
	for (i=1;i<n;i++)                 /*�������*/		
	{   
		if (m[1]>pro[i].count)
				m[1]=pro[i].count;
	}
}