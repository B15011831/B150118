/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"medcine.h"

void printHead( )      /*��ӡҩƷ��Ϣ�ı�ͷ*/
{
printf("%4s%10s%6s%6s%10s%6s%10s%10s%8s%10s\n","����","ҩƷ����","����","���","�������","�۸�","���ʱ��","����ʱ��","������","����ʱ��");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ҩƷ�����Ϣ   ********\n");
		printf("******** 2. ҩƷ��������� ********\n");
		printf("******** 3. ��������ҩƷ   ********\n");
        printf("******** 4. ����������ѯ   ********\n");
		printf("******** 0. �˳�           ********\n");
}

void menuScore( )     /*2��ҩƷ���������˵�����*/
{
		printf("@@@@@@@@ 1. ҩƷ������     @@@@@@@@\n");
        printf("@@@@@@@@ 2. �޸Ŀ����Ϣ @@@@@@@@\n");
        printf("@@@@@@@@ 3. ɾ��ҩƷ     @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}


void menuSearch()    /*4������������ѯ�˵�����*/
{
		printf("######## 1. ��ҩƷ�����ѯ   ########\n");
		printf("######## 2. ��ҩƷ���Ʋ�ѯ   ########\n");
		printf("######## 3. �����ʱ���ѯ   ########\n");
		printf("######## 0. �����ϲ�˵�     ########\n");
}


int scoreManage(Medcine med[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ�ѧ�Ų����ظ�*/
{  
	int choice,t,find[COD];
	Medcine s;
	do
	{   
		menuScore( );                  /*��ʾ��Ӧ�Ķ����˵�*/
		printf("���������ѡ��:\n");
		scanf("%d",&choice);	          /*����ѡ��*/
		switch(choice)
		{
		case 1:	 readMed(&s,1);       /*����һ���������ҩƷ��¼*/
				 n=insertMed(med,n,s);   /*���ú�������ҩƷ�������¼*/
				 saveFile(med,n);
				 break;
		case 2:   printf("��������޸ĵ�ҩƷ����\n");
					 scanf("%ld",&s.cod);  /*����һ�����޸ĵ�ҩƷ����*/
				      t=searchMed(med,n,s,1,find) ; /*���ú�������ָ��ҩƷ�ļ�¼*/
				      if (t)                 /*�����ѧ�ŵļ�¼����*/
					 {
						  readMed(&s,1);   /*����һ��������ҩƷ�����Ϣ*/
					      med[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }
					  else                 /*�����ҩƷ����ļ�¼������*/ 
                     printf("��ҩƷ�����ڣ��㲻�ܶ�����в���\n"); /*�����ʾ��Ϣ*/
					  break;
		case 3:   printf("�������ɾ����ҩƷ����\n");
					 scanf("%ld",&s.cod);  /*����һ����ɾ����ҩƷ����*/
					 n=deleteMed(med,n,s);   /*���ú���ɾ��ָ��ҩƷ�����ҩƷ��¼*/
					 break;
		case 0: break;
		}
	}while(choice);
	return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}




void searchManage(Medcine med[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findcod,f[COD];
Medcine s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("���������ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("�������ѯҩƷ�ı���:\n");
				      scanf("%ld",&s.cod);         /*�������ѯѧ����ѧ��*/
					  break;
				case 2:   printf("�������ѯҩƷ������:\n");
				      scanf("%s",s.name);	          /*�������ѯҩƷ������*/		  
				      break;   
				case 3:   printf("�������ѯҩƷ�����ʱ��:\n");
				      scanf("%d",&s.intime);          /*�������ѯҩƷ���ʱ��*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findcod=searchMed(med,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findcod)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findcod;i++)         /*ѭ������f������±�*/
	      	 printMed(&med[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("�ü�¼������!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Medcine med[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
			     	sortMed(med,n,1);         /*��������С�����˳�������¼*/ 
          	        printMed(med,n);          /*��������С�����˳��������м�¼*/
		 			break;
			case 2: n=scoreManage(med,n);   /* 2. ҩƷ���������*/ 
			   	     break;
			case 3: sortMed(med,n,3);
					printHead( );                  /*��ӡ��ͷ*/
					printMed(med,n);      /* 3. ������Ϣͳ��*/
					break;
			case 4: searchManage(med,n);     /* 4. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Medcine med[COD];                /*����ʵ��һά����洢ҩƷ��¼*/
      int choice,n;
	 n=readFile(med);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(med);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("���������ѡ��: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(med,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("�������,�������������ѡ��!\n");
	} while (choice);
	sortMed(med,n,1);                   /*�����ļ�ǰ��ҩƷ������С��������*/ 
	     saveFile(med,n);                   /*����������ļ�*/
      return 0;
}













/*��medcine.c�ļ�����������*/
#include "medcine.h"
#include <stdio.h>

int readMed(Medcine  *med , int n)          /*����ҩƷ��¼ֵ������Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("����ҩƷ��Ϣ\n");
		printf("ҩƷ����:  ");
	     scanf("%ld", &med[i].cod);
		if (med[i].cod==0) break;
		printf("ҩƷ����: ");
		scanf("%s",&med[i].name);	
		printf("ҩƷ����:  ");
		scanf("%s",&med[i].type);
		printf("���:\n");
		scanf("%s",&med[i].spec);
		printf("����: ");
		scanf("%ld",&med[i].num);	
		printf("�۸�: ");
		scanf("%lf",&med[i].price);	
		printf("���ʱ��:  ");
		scanf("%ld",&med[i].intime);
		printf("����ʱ��: ");
		scanf("%ld",&med[i].outtime);	
		printf("������:  ");
		scanf("%s",&med[i].term);
		printf("�����ڵ���ʱ��:  ");
		scanf("%ld",&med[i].outterm);
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printMed ( Medcine  *med , int n)       /*�������ҩƷ��¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%2ld", med[i].cod);
		printf("%10s", med[i].name);
		printf("%8s", med[i].type);
		printf("%14s",med[i].spec);
	    printf("%6ld",med[i].num);
	    printf("%8.2f",med[i].price);
		printf("%10ld",med[i].intime);
	    printf("%4ld",med[i].outtime);
	    printf("%4s",med[i].term);
	    printf("%10ld\n",med[i].outterm);
	}
}

int equal(Medcine s1,Medcine s2,int condition)  /*����ж�����Medcine��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ���*/
		return s1.cod==s2.cod;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ����ʱ��*/
	     return s1.intime==s2.intime;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ�����*/
		return s1.num==s2.num;
	else return 1;                       /*�����������1*/
} 

int larger(Medcine s1,Medcine s2,int condition)  /*����condition�����Ƚ�����ҩƷ��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ���*/
		return s1.cod>s2.cod;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ�����*/
		return s1.num>s2.num;
	if (condition==3)                    /*�������condition��ֵΪ2����Ƚ���Ч�ڵ���ʱ��*/
		return s1.outterm>s2.outterm;
	else return 1; /*�����������1*/
}

void reverse(Medcine med[],int n)             /*����Ԫ������*/
{
	int i;
	Medcine temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=med[i];
		med[i]=med[n-1-i];
		med[n-1-i]=temp;
	}
}



void sortMed(Medcine med[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Medcine t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(med[minpos],med[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=med[i];
			med[i]=med[minpos];
			med[minpos]=t;
		}
	}
}

int searchMed(Medcine med[],int n,Medcine s,int condition,int f[ ])  /*��med��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(med[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertMed(Medcine med[],int n,Medcine s)              /*��med�������������������һ��Ԫ��s*/
{
	int i;
	sortMed(med,n,1);                              /*�Ȱ���������*/
	for (i=0;i<n;i++)
	{
		if (equal(med[i],s,1))                      /*������ͬ��������룬��֤�����Ψһ��*/
		{
		    printf("��ҩƷ�������,�����ظ�¼��!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*�������С��������*/
	{
		if (!larger(med[i],s,1))                    /*���s���ڵ�ǰԪ��med[i]�����˳�ѭ��*/
		break;
		med[i+1]=med[i];                         /*����Ԫ��med[i]����һ��λ��*/
	}
	med[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteMed(Medcine med[],int n,Medcine s)            /*��������ɾ��ָ�������һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(med[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("��ҩƷ�����¼�����ڣ�\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(med[i],s,1)����*/ 
		med[j]=med[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}






