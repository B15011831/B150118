#include <stdio.h>
#include <stdlib.h>
#include "goods.h"        
int  createFile(Goods good[ ])              
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\ckglxt.txt", "wb")) == NULL) 
	{
	    printf("�޷����ļ� !\n");         
	    exit(0);                           
    	}
	printf("��������Ʒ��Ϣ:\n");
	n=readGood(good,NUM);                
fwrite(good,sizeGood,n,fp);                  
 	fclose(fp);                             
	 return n;
}

int readFile(Goods good[ ] )                     
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\ckglxt.txt", "rb")) == NULL)  
	{
	    printf("�ļ������ڣ����ȴ����ļ�:\n");  
	    return 0;                              
	}	 
    	fread(&good[i],sizeGood,1,fp);                  
   	while(!feof(fp))                           
	{
		i++;
	    	fread(&good[i],sizeGood,1,fp);             
     }
	fclose(fp);                                
	return i;                                 
}

void saveFile(Goods good[],int n)                  
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\ckglxt.txt", "wb")) == NULL) 
	{
		printf("�޷����ļ� !\n");          
		exit(0);                           
	}
	fwrite(good,sizeGood,n,fp);        
	fclose(fp);                              
}
