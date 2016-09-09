/*��book.c�ļ�����������*/
#include "book.h"
#include <stdio.h>



int readBoo(Book *boo,int n)          /*����ͼ���¼�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	     scanf("%ld", &boo[i].num);
		if (boo[i].num==0) break;
		printf("name: ");
		scanf("%s",boo[i].name);	
		printf("writer:  ");
		scanf("%s",boo[i].writer);
        printf("category:  ");
		scanf("%s",boo[i].category);
		printf("location:  ");
		scanf("%d",boo[i].location);
		printf("information:  ");
		scanf("%s",boo[i].location);
		printf("botime:  ");
		scanf("%d",boo[i].botime);
		printf("retime:  ");
		scanf("%d",boo[i].retime);
	}
        
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printBoo ( Book  *boo , int n)       /*�������ͼ���¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", boo[i].num);
		printf("%8s", boo[i].name);
		printf("%8s", boo[i].writer);
        printf("%8s", boo[i].category);
        printf("%8ld", boo[i].location);
		printf("%8s", boo[i].information);
	    printf("%8d", boo[i].botime);
		printf("%8d", boo[i].retime);

	}
}

int equal(Book s1,Book s2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.writer==s2.writer;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ����*/
		return s1.category==s2.category;
	else return 1;                       /*�����������1*/
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




void  insertBoo(Book boo[],int n,int x)
{
int i,j;
for (i=0;i<n&&boo[i].num<x;i++)         /*���Ҵ������λ��*/
for (j=n-1;j>=i;j--)            /*�õݼ�ѭ����λ*/
    boo[j+1].num=boo[j].num;
    boo[i].num=x;                       /*������±�Ԫ��ֵ��ֵΪ�����x*/

}


int deleteBoo(Book boo[],int n,int s)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	int flag=1;                                  /*�Ƿ��ҵ���ɾԪ�صı�־λ��1�ҵ���0δ�ҵ�*/
	for (i=0;i<n && boo[i].num!=s;i++)                 /*Ѱ�Ҵ�ɾ����Ԫ���Ƿ����*/	          
	if (i==n)                                    /*ѭ��ֹͣʱ���i==n,��˵��Ԫ�ز�����*/
		flag=0;
	else
	{
	for(j=i;j<n-1;j++)
	
		boo[j].num=boo[j+1].num;
	}
	 return flag;                      
}




int main()
  {
	  int x=5,y=5,z=5,n=5,i=0;
	  int SIZE=6;
	  Book boo[200];
	  printBoo(boo,SIZE);                  /*���ɾ��ǰ������*/
	  printf("Please input x be deleted:\n");

    scanf("%8ld,&x");                /*�����ɾ����Ԫ��*/
 if(deleteBoo(boo,SIZE,x))
     printBoo(boo,SIZE-1);             /*����ɹ������ɾ���������Ԫ��*/
else
     printf("can not delete!\n");    /*�������δɾ������ʾ��Ϣ*/

printBoo(boo,SIZE-1);
 printf("Please input y be inserted:\n");
scanf("%8ld,&y");                  /*����������ֵy*/
insertBoo(boo,SIZE-1,y);
printBoo(boo,SIZE);



return 0;  
  }


