 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "product.h"        
int  createFile(Product pro[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\product.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input products\' information:\n");
	n=readPro(pro,NUM);                /*����product.h�еĺ���������*/
    fwrite(pro,sizePro,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(Product pro[ ] )                     /*���ļ��е����ݶ������ڽṹ������pro��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\product.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&pro[i],sizePro,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&pro[i],sizePro,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(Product pro[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\product.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(pro,sizePro,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}
