/* ��product.h�ļ����������� */
#ifndef _PRODUCT             /*�������룬��ֹ�ظ������Ĵ���*/
#define _PRODUCT 
#include <string.h>
#define NUM 20                /*������Ʒ�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Product                   /*��Ʒ��¼��������*/
{
		long num;
		char name[20];
		char brand[10];
		double price;
		int count;
		double total;
		int rank;
};
typedef struct Product Product;
#define sizePro sizeof(Product)      /*һ����Ʒ��¼����Ҫ���ڴ�ռ��С*/
int readPro(Product pro[],int n);       /*������Ʒ��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printPro(Product  *pro , int n);   /*���������Ʒ��¼��ֵ*/
void printMarkCourse(char *s,int m[2],int k);   /*��ӡ���ͨ�ú�������countManage ����*/
int equal(Product s1,Product s2,int condition);  /*����condition�����ж�����Product����������ȷ�*/
int larger(Product s1,Product s2,int condition);  /*����condition�Ƚ�Product�������ݴ�С*/
void reverse(Product pro[],int n);             /*��Ʒ��¼����Ԫ������*/

void calcuTotal(Product pro[],int n);           /*����������Ʒ���ܼ۸�*/
void calcuRank(Product pro[],int n);           /*���ݼ۸������Ʒ���Σ������в�������*/
void calcuMark(int m[],Product pro[],int n); /*����϶������Ʒ*/

void sortPro(Product pro[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchPro(Product pro[],int n,Product s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertPro(Product pro[],int n,Product s);                   /*�������в���һ��Ԫ�ذ��������*/
int deletePro(Product pro[],int n,Product s);                   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/
#endif
