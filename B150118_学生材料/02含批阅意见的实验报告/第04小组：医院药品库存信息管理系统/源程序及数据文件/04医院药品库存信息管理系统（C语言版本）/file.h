 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "medcine.h"        
int  createFile(Medcine med[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\medcine.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input medcines\' information:\n");
	n=readMed(med,COD);                /*����student.h�еĺ���������*/
fwrite(med,sizeMed,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(Medcine med[ ] )                     /*���ļ��е����ݶ������ڽṹ������stu��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\medcine.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&med[i],sizeMed,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&med[i],sizeMed,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(Medcine med[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\medcine.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(med,sizeMed,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}
