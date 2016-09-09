/* ��student.h�ļ����������� */
#ifndef _MEDCINE             /*�������룬��ֹ�ظ������Ĵ���*/
#define _MEDCINE
#include <string.h>
#define COD 20                /*����ҩƷ�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Medcine                   /*ѧ����¼��������*/
{
		long cod;
		char name[20];
		char type[10];
		char spec[20];
		long num;
                double price;
		long intime;
                long outtime;
                char term[10];
                long outterm;
};
typedef struct Medcine Medcine;
#define sizeMed sizeof(Medcine)      /*һ�ּ�¼����Ҫ���ڴ�ռ��С*/
int readMed(Medcine med[],int n);       /*����ҩƷ��¼ֵ������Ϊ0������涨������¼ʱֹͣ*/
void printMed(Medcine  *med , int n);   /*�������ҩƷ��¼��ֵ*/

int equal(Medcine s1,Medcine s2,int condition);  /*����condition�����ж�����Medcine����������ȷ�*/
int larger(Medcine s1,Medcine s2,int condition);  /*����condition�Ƚ�Medcine�������ݴ�С*/
void reverse(Medcine med[],int n);             /*ҩƷ��¼����Ԫ������*/


void sortMed(Medcine med[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchMed(Medcine med[],int n,Medcine s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertMed(Medcine med[],int n,Medcine s);                   /*�������в���һ��Ԫ�ذ���������*/
int deleteMed(Medcine med[],int n,Medcine s);                   /*��������ɾ��һ��ָ�������Ԫ��*/
#endif
