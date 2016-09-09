/*��employee.c�ļ�����������*/
#include "employee.h"
#include <stdio.h>

int readEmp(Employee  *emp , int n)          /*����Ա����¼ֵ������Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one employee\'s information\n");
		printf("num:  ");
	     scanf("%ld", &emp[i].num);
		if (emp[i].num==0) break;
		printf("name: ");
		scanf("%s",emp[i].name);	
		printf("sex:  ");
		scanf("%s",emp[i].sex);
    	     emp[i].total=0;                /*�ܹ�����Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three pay of the employee:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&emp[i].score[j]);	
		}
		emp[i].rank=0;                 /*������Ҫ�����ܹ��������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printEmp ( Employee  *emp , int n)       /*�������Ա����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", emp[i].num);
		printf("%8s", emp[i].name);
		printf("%8s", emp[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",emp[i].score[j]);
	    printf("%7d",emp[i].total);
	    printf("%5d\n",emp[i].rank);
	}
}

int equal(Employee e1,Employee e2,int condition)  /*����ж�����Employee��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϹ���*/
		return e1.num==e2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(e1.name,e2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return e1.rank==e2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܹ���*/
		return e1.total==e2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Employee e1,Employee e2,int condition)  /*����condition�����Ƚ�����Employee��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return e1.num>e2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܹ���*/
		return e1.total>e2.total;	
	else return 1; /*�����������1*/
}

void reverse(Employee emp[],int n)             /*����Ԫ������*/
{
	int i;
	Employee temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=emp[i];
		emp[i]=emp[n-1-i];
		emp[n-1-i]=temp;
	}
}

void calcuTotal(Employee emp[],int n)         /*��������Ա�����ܹ���*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������Ա����¼*/
	{
		emp[i].total =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ���������Ź���*/
			emp[i].total +=emp[i].score[j];
	}	
}

void calcuRank(Employee emp[],int n)          /*�����ܹ��ʼ�������Ա����������������ͬ��������ͬ*/
{
	int i ;                       
	sortEmp(emp,n,2);                     /*�ȵ���sortEmp�㷨�����ܹ�����С��������*/
	reverse(emp,n);                      /*�����ã����ܹ����ɴ�С������*/
	emp[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(emp[i],emp[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܹ������*/
			emp[i].rank=emp[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			emp[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Employee emp[],int n) /*��ȫ��˾Ա������˰�ѡ��ܻ������ʡ��ܽ���*/
/*������ʽ������ά����m�ĵ�һά��������һ��ڶ�ά������˰�ѡ��ܻ������ʡ��ܹ���*/
{
	int i,j;
    for (i=0;i<3;i++)                 /*��ȫ��˾����˰�ѣ��ܻ������ʣ��ܽ���*/
	{ 
		m[i][2]=emp[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=emp[j].score[i];
	}
}

void sortEmp(Employee emp[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Employee t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(emp[minpos],emp[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=emp[i];
			emp[i]=emp[minpos];
			emp[minpos]=t;
		}
	}
}

int searchEmp(Employee emp[],int n,Employee e,int condition,int f[ ])  /*��emp��������condition��������*/
/*��e��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(emp[i],e,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertEmp(Employee emp[],int n,Employee e)              /*��stu�����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortEmp(emp,n,1);                              /*�Ȱ���������*/
	for (i=0;i<n;i++)
	{
		if (equal(emp[i],e,1))                      /*������ͬ��������룬��֤���ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*�����Ŵ�С��������*/
	{
		if (!larger(emp[i],e,1))                    /*���e���ڵ�ǰԪ��emp[i]�����˳�ѭ��*/
		break;
		emp[i+1]=emp[i];                         /*����Ԫ��emp[i]����һ��λ��*/
	}
	emp[i+1]=e;                                /*���±�i+1������Ԫ��e*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteEmp(Employee emp[],int n,Employee e)            /*��������ɾ��ָ�����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(emp[i],e,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(emp[i],s,1)����*/ 
		emp[j]=emp[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
