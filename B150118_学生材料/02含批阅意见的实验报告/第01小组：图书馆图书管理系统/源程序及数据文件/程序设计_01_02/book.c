/*��book.c�ļ�����������*/
#include "book.h"
#include <stdio.h>

void readOneBook(Book *boo)          /*����һ����ĵ�ַ��¼����Ϣ*/
{
		printf("Input one book\'s information\n");
		printf("num:  ");
	    scanf("%ld",&boo->num);
		printf("name:  ");
		scanf("%s",boo->name);	
		printf("writer:  ");
		scanf("%s",boo->writer);
        printf("category:  ");
		scanf("%s",boo->category);
		printf("location:  ");
		scanf("%ld",&boo->location);
		printf("information:  ");
		scanf("%s",boo->information);
		printf("botime:  ");
		scanf("%s",&boo->botime);
		printf("retime:  ");
		scanf("%s",&boo->retime);                        
}


int readBoo(Book *boo,int n)          /*����ͼ���¼�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	     scanf("%ld", &boo[i].num);
		if (boo[i].num==0) 
	    break;
		printf("name:  ");
		scanf("%s",boo[i].name);	
		printf("writer:  ");
		scanf("%s",boo[i].writer);
        printf("category:  ");
		scanf("%s",boo[i].category);
		printf("location:  ");
		scanf("%ld",&boo[i].location);
		printf("information:  ");
		scanf("%s",boo[i].information);
		printf("botime:  ");
		scanf("%s",&boo[i].botime);
		printf("retime:  ");
		scanf("%s",&boo[i].retime);
	}
        
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printBoo ( Book  *boo , int n)       /*�������ͼ���¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%ld",boo[i].num);
		printf("%12s", boo[i].name);
		printf("%14s", boo[i].writer);
        printf("%15s", boo[i].category);
        printf("%7ld",boo[i].location);
		printf("%9s",boo[i].information);
	    printf("%20s",boo[i].botime);
		printf("%24s\n",boo[i].retime);

	}
}

int equal(Book s1,Book s2,int condition)  /*����ж�����Book��¼���*/
{
if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
	return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	    if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
{
	    if (strcmp(s1.writer,s2.writer)==0) 	return 1;
		else return 0;
     }
else if (condition==4)                /*�������condition��ֵΪ4����Ƚ����*/
{
	    if (strcmp(s1.category,s2.category)==0) 	return 1;
		else return 0;
     }
	else return 1;                       /*�����������1*/
} 

int larger(Book s1,Book s2,int condition)  /*����condition�����Ƚ�����Book��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num>s2.num;
	else return 1; /*�����������1*/
}


void reverse(Book boo[],int n)             /*����Ԫ������*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=boo[i];
		boo[i]=boo[n-1-i];
		boo[n-1-i]=temp;
	}
}


void sortBoo(Book boo[],int n)  /*ð������*/
{
	int i,j,temp;
		for (i=1;i<n-1;i++)                  /*������n-1������*/
		  for (j=n-1;j>i;j--)             /*�ݼ�ѭ�����Ӻ���ǰ�Ƚϣ��˺���������Ԫ�ضԼ���*/
			if (boo[j].num<boo[j-1].num)         /*�����Ƚϣ�����һ��Ԫ��С���򽻻���������Ԫ��*/
			{
				temp=boo[j-1].num;
				boo[j-1].num=boo[j].num;
				boo[j].num=temp;
			}
	

}


int searchBoo(Book boo[],int n,Book s,int condition,int f[ ])  /*��boo��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(boo[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}



int insertBoo(Book boo[],int n,Book s)              /*��boo����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortBoo(boo,n);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(boo[i],s,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(boo[i],s,1))                    /*���s���ڵ�ǰԪ��boo[i]�����˳�ѭ��*/
		break;
		boo[i+1]=boo[i];                         /*����Ԫ��boo[i]����һ��λ��*/
	}
	boo[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteBoo(Book boo[],int n,Book s)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(boo[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(boo[i],s,1)����*/ 
		boo[j]=boo[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}




