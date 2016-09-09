/* ��EMPLOYEE.h�ļ����������� */
#ifndef _EMPLOYEE            /*�������룬��ֹ�ظ������Ĵ���*/
#define _EMPLOYEE
#include <string.h>
#define NUM 20               /*����Ա�������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Employee                   /*Ա����¼��������*/
{
		long num;
		char name[20];
		char sex[10];
		int score[3];
		int total;
		int rank;
};
typedef struct Employee Employee;
#define sizeEmp sizeof(Employee)      /*һ��Ա����¼����Ҫ���ڴ�ռ��С*/
int readEmp(Employee emp[],int n);       /*����Ա����¼ֵ������Ϊ0������涨������¼ʱֹͣ*/
void printEmp(Employee *emp , int n);   /*�������Ա����¼��ֵ*/

int equal(Employee e1,Employee e2,int condition);  /*����condition�����ж�����employee����������ȷ�*/
int larger(Employee e1,Employee e2,int condition);  /*����condition�Ƚ�employee�������ݴ�С*/
void reverse(Employee emp[],int n);             /*Ա����¼����Ԫ������*/

void calcuTotal(Employee emp[],int n);           /*��������Ա�����ܹ���*/
void calcuRank(Employee emp[],int n);           /*�����ܹ��ʼ���Ա�������Σ������в�������*/
void calcuMark(double m[3][3],Employee emp[],int n); /*������Ա������˰�ѡ��ܻ������ʡ��ܽ���m�����һά*/
/*��ʾ��һ������ݣ��ڶ�ά��ʾ��˰�ѡ��ܻ������ʡ��ܽ���*/

void sortEmp(Employee emp[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchEmp(Employee emp[],int n,Employee e,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertEmp(Employee emp[],int n,Employee e);                   /*�������в���һ��Ԫ�ذ�Ա������*/
int deleteEmp(Employee emp[],int n,Employee e);                   /*��������ɾ��һ��ָ��Ա����Ԫ��*/
#endif
