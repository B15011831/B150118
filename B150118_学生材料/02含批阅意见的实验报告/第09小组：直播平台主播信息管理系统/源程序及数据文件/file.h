#include <stdio.h>
#include <stdlib.h>
#include "zhubo.h"
int  createFile(zhubo zhu[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\zhubo.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input zhubo\' information:\n");
	n=readzhu(zhu,NUM);                /*����student.h�еĺ���������*/
fwrite(zhu,sizezhu,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(zhubo zhu[ ] )                     /*���ļ��е����ݶ������ڽṹ������stu��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\zhubo.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}
    	fread(&zhu[i],sizezhu,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&zhu[i],sizezhu,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(zhubo zhu[],int n)                  /*���ṹ�����������д���ļ�*/
{
  	FILE *fp;
   	if((fp=fopen("d:\\zhubo.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(zhu,sizezhu,n,fp);
	fclose(fp);                              /*�ر��ļ�*/
}

