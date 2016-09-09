#include "zhubo.h"
#include <stdio.h>

int readzhu(zhubo  *zhu , int n)          /*����������¼ֵ�������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one zhubo\'s information\n");
		printf("name: ");
		scanf("%s",zhu[i].name);
		printf("sex:  ");
		scanf("%s",zhu[i].sex);
		printf("num:  ");
        scanf("%ld", zhu[i].num);
		printf("game: ");
		scanf("%s",zhu[i].game);
		printf("Input time of the zhubo:\n");
		for (j=0;j<7;j++)
	    {
		    scanf("%d",&zhu[i].time[j]);
		}

	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printzhu ( zhubo  *zhu , int n)       /*�������������¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8s", zhu[i].name);
		printf("%8s", zhu[i].sex);
		printf("%8ld", zhu[i].num);
		printf("%8s", zhu[i].game);
		printf("%8d\n", zhu[i].total);
	}
	    printf("%5d\n",zhu[i].rank);
}

int equal(zhubo z1,zhubo z2,int condition)  /*����ж�����������¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϷ����*/
		return z1.num==z2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(z1.name,z2.name)==0) 	return 1;
		else return 0;
     }

	else return 1;                       /*�����������1*/
}

int larger(zhubo z1,zhubo  z2,int condition)  /*����condition�����Ƚ�����������¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϷ����*/
		return z1.num>z2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ���ʱ��*/
		return z1.total>z2.total;
	else return 1; /*�����������1*/
}

void reverse(zhubo zhu[],int n)             /*����Ԫ������*/
{
	int i;
	zhubo temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=zhu[i];
		zhu[i]=zhu[n-1-i];
		zhu[n-1-i]=temp;
	}
}

void calcuTotal(zhubo zhu[],int n)         /*��������ѧ������ʱ��*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������������¼*/
	{
		zhu[i].total =0;
		for (j=0;j<7;j++)               /*�ڲ�ѭ�����������ʱ��*/
			zhu[i].total +=zhu[i].time[j];
	}
}

void calcuRank(zhubo zhu[],int n)          /*������ʱ���������������������ʱ����ͬ��������ͬ*/
{
	int i ;
	sortzhu(zhu,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(zhu,n);                      /*�����ã����ܷ��ɴ�С������*/
	zhu[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(zhu[i],zhu[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			zhu[i].rank=zhu[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/
	    else
			zhu[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[7][3],zhubo zhu[],int n) /*������������̡�ƽ��*/

{
	int i,j;
	for (i=0;i<7;i++)
	{
		m[i][0]=zhu[0].time[i];
		for (j=1;j<n;j++)
			if (m[i][0]<zhu[j].time[i])
				m[i][0]=zhu[j].time[i];
	}
	for (i=0;i<7;i++)
	{
		m[i][1]=zhu[0].time[i];
		for (j=1;j<n;j++)
			if (m[i][1]>zhu[j].time[i])
				m[i][1]=zhu[j].time[i];
	}
	for (i=0;i<7;i++)
		m[i][2]=zhu[0].time[i];
		for (j=1;j<n;j++)
			m[i][2]+=zhu[j].time[i];
		m[i][2]/=n;
}



void sortzhu(zhubo zhu[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	zhubo t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(zhu[minpos],zhu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=zhu[i];
			zhu[i]=zhu[minpos];
			zhu[minpos]=t;
		}
	}
}

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[ ])  /*��stu��������condition��������*/
/*��z��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(zhu[i],z,condition))
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/
}

int insertzhu(zhubo zhu[],int n,zhubo z)              /*��zhu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortzhu(zhu,n,1);                              /*�Ȱ�����ź�����*/
	for (i=0;i<n;i++)
	{
		if (equal(zhu[i],z,1))                      /*�������ͬ��������룬��֤����ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*������Ŵ�С��������*/
	{
		if (!larger(zhu[i],z,1))                    /*���z���ڵ�ǰԪ��zhu[i]�����˳�ѭ��*/
		break;
		zhu[i+1]=zhu[i];                         /*����Ԫ��zhu[i]����һ��λ��*/
	}
	zhu[i+1]=z;                                /*���±�i+1������Ԫ��s*/
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deletezhu(zhubo zhu[],int n,zhubo z)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(zhu[i],z,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(zhu[i],s,1)����*/
		zhu[j]=zhu[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/

	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}

