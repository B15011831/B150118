#ifndef _ZHUBO            /*�������룬��ֹ�ظ������Ĵ���*/
#define _ZHUBO
#include <string.h>
#define NUM 20                /*�������������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct zhubo                   /*������¼��������*/
{

		char name[20];
		char sex[10];
		 long num[10];
		char game[10];
		int time[7];
		int total;
		int rank;
};
typedef struct zhubo zhubo;
#define sizezhu sizeof(zhubo)      /*һ��������¼����Ҫ���ڴ�ռ��С*/
int readzhu(zhubo zhu[],int n);       /*����������¼ֵ�������涨������¼ʱֹͣ*/
void printzhu(zhubo  *zhu , int n);   /*�������������¼��ֵ*/

int equal(zhubo z1,zhubo z2,int condition);  /*����condition�����ж�������������������ȷ�*/
int larger(zhubo z1,zhubo z2,int condition);  /*����condition�Ƚ�Student�������ݴ�С*/
void reverse(zhubo zhu[],int n);             /*������¼����Ԫ������*/

void calcuTotal(zhubo zhu[],int n);           /*����������������ֱ��ʱ��*/
void calcuRank(zhubo zhu[],int n);           /*������ʱ��������������Σ������в�������*/
void calcuMark(double m[7][3],zhubo zhu[],int n);


void sortzhu(zhubo zhu[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertzhu(zhubo zhu[],int n,zhubo z);                   /*�������в���һ��Ԫ�ذ����������*/
int deleteStu(zhubo zhu[],int n,zhubo z);                   /*��������ɾ��һ��ָ������ŵ�Ԫ��*/
#endif

