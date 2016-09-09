/* ��book.h�ļ����������� */
#ifndef _BOOK             /*�������룬��ֹ�ظ������Ĵ���*/
#define _BOOK
#include <string.h>
#define NUM 20                /*����ͼ�������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Book                   /*ͼ���¼��������*/
{
		long num;
		char name[20];
		char writer[20];
		char category[20];
		long location;
        char information[20];
        char botime[40];
        char retime[40];
	
};
typedef struct Book Book;

#define sizeBoo sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/
int readBoo(Book *boo,int n);       /*����ͼ���¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void readOneBook(Book *boo);          /*����һ��ͼ���¼ֵ����ʼ��boo*/
void printBoo(Book  *boo , int n);   /*�������ͼ���¼��ֵ*/

int equal(Book s1,Book s2,int condition);  /*����condition�����ж�����Book����������ȷ�*/
int larger(Book s1,Book s2,int condition);  /*����condition�Ƚ�Book�������ݴ�С*/
void reverse(Book boo[],int n);             /*ͼ���¼����Ԫ������*/


void sortBoo(Book boo[],int n);   /*ð�����򷨴�С��������*/

int searchBoo(Book boo[],int n,Book s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
int insertBoo(Book boo[],int n,Book s);   /*�������в���һ��Ԫ�ذ������������*/
int deleteBoo(Book boo[],int n,Book s);   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/

#endif
