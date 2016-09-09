#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
 
void printHead( )      /*��ӡͼ����Ϣ�ı�ͷ*/
{
	printf("%s\t%s\t\t%s\t\t%s\t%s\t%s\t\t%s\t\t%s\n","���","����","����","���","λ��","��Ϣ","����ʱ��","�黹ʱ��");
}

void menu()      /*����˵�����*/
{
	printf("*****1.��ʾ������Ϣ*****\n");
    printf("*****2.������Ϣ����*****\n");
    printf("*****3.ͼ����Ϣ����*****\n");
    printf("*****4.����������ѯ*****\n");
    printf("*****0.�˳�        *****\n");
}
void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. ��������ͼ�� %%%%%%%%\n");
        printf("%%%%%%%% 4. �޸�ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}
void menuMessage( )     /*3��ͼ����Ϣ����˵�����*/
{

		printf("@@@@@@@@ 1. ��ʾͼ������λ�� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ��ʾ��������Ϣ   @@@@@@@@\n");
        printf("@@@@@@@@ 3. ��ʾ����ʱ��     @@@@@@@@\n");
		printf("@@@@@@@@ 4. ��ʾӦ�黹ʱ��   @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵�     @@@@@@@@\n");
}
 
void menuSearch()    /*4������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����߲�ѯ   ########\n");
		printf("######## 4. ������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Book boo[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
                                             /*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  int choice,t,find[NUM];
   Book s;
   do
   {   
	   menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
       printf("choose one operation you want to do:\n");
	   scanf("%d",&choice);	          /*����ѡ��*/
	   switch(choice)
	   {
	     case 1:readOneBook(&s);       /*����һ���������ͼ���¼����ʼ��s*/
				n=insertBoo(boo,n,s);/*���ú�������ͼ���¼*/
				break;
		 case 2:printf("Input the number deleted\n");
			    scanf("%ld",&s);  /*����һ����ɾ����ͼ����*/
				n=deleteBoo(boo,n,s);   /*���ú���ɾ��ָ����ŵ�ͼ���¼*/
				break;
         case 3:printf("Input the number sorted\n");
				scanf("%ld",&s);  /*����һ���������ͼ����*/
				sortBoo(boo,n) ; /*���ú�������ָ����ŵ�ͼ��*/
                break;
		 case 4:printf("Input the number modified\n");
			    scanf("%ld",&s);  /*����һ�����޸ĵ�ͼ����*/
				t=searchBoo(boo,n,s,1,find) ; /*���ú�������ָ����ŵ�ͼ���¼*/
				if (t)                 /*�����ͼ��ļ�¼����*/
				{
					readBoo(&s,1);   /*����һ��������ͼ���¼��Ϣ*/
					boo[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
				}					 
				else                 /*����ñ�ŵļ�¼������*/ 
                printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
				break;
			    case 0: break;
		}
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void messageManage(Book boo[],int n)          /*�ú������ͼ����Ϣ������*/
{  
	int choice,num,i,resultnum;
	do
	{
		menuMessage( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);  /*�������ѡ��*/
		if (choice==0) break;
		else if (choice <1|| choice >4)
		{ printf("���벻�Ϸ�\n");
		continue;}
		printf("��������:\n");
		scanf("%d",&num);
		for (i = 0;i < n;i++) if (boo[i].num==num) resultnum=i;
		switch(choice)
		{
			case 1:
				
				printf("ͼ������λ��Ϊ��\n%d\n\n",boo[resultnum].location);         /*��ʾͼ������λ��*/
					  break;
			case 2:   
			
				printf("��������ϢΪ��\n%s\n\n",boo[resultnum].information);     /*��ʾ��������Ϣ*/
					  break;
			case 3:   
				printf("����ʱ��Ϊ��\n%s\n\n",boo[resultnum].botime);         /*��ʾ����ʱ��*/
				      break;	
			case 4:    
				printf("Ӧ�黹ʱ��Ϊ��\n%s\n\n",boo[resultnum].retime);       /*��ʾ�黹ʱ��*/
				      break;	
			case 0:   break;
		}
	}while(choice);
}







void searchManage(Book boo[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
    Book s;
	   do
	   {
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ�鱾�ı��*/
					  break;
				case 2:   printf("Input a book\'s name will be searched:\n");
				      scanf("%s",&s.name);	          /*�������ѯ�鱾������*/		  
				      break;   
				case 3:   printf("Input a writer will be searched:\n");
				      scanf("%s",&s.writer);            /*�������ѯ�鱾������*/
			          break;
				case 4:   printf("Input a category will be searched:\n");
				      scanf("%s",&s.category);          /*�������ѯ�鱾�����*/
					  break;
				case 0:   break;
			}	
                 if (choice>=1&&choice<=4)
			{ 
				findnum=searchBoo(boo,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)        /*ѭ������f������±�*/
	      	         printBoo(&boo[f[i]],1);        /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
			}		
	    }while (choice);
}


int runMain(Book boo[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				    printBoo(boo,n);
					break;
			case 2: n=baseManage(boo,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: messageManage(boo,n);     /* 3. ͼ����Ϣ����*/
					break;
        	case 4: searchManage(boo,n);     /* 4. ����������ѯ*/
				     break;
            case 0: break;
		}
		return n;
}




int main()
{
	int n,m,choice,z;
	Book boo[2000];

	printf("��ӭ����ͼ���ͼ�����ϵͳ\n\n");
	printf("1 ����ϵͳ\n0 �˳�ϵͳ\n\n\n");
	scanf("%d",&z);
	if(z==0)
		return 0;
    if(z==1)
    printf("���������룺\n");
	scanf("%d",&m);
    if(m==888888)
	{ 
            n=readFile(boo);              /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	        if(!n)                        /*���ԭ�����ļ�Ϊ��*/
			{
				n=createFile(boo);        /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
			}
			do
			{
	        menu();                      /*��ʾ���˵�*/
	        printf("Please input your choice: ");
	        scanf("%d",&choice);
	        if (choice>=0&&choice<=4)
	             n=runMain(boo,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	        else 
		         printf("error input,please input your choice again!\n");
			} while (choice);
			
	     sortBoo(boo,n);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(boo,n);                   /*����������ļ�*/
	}
	else
	{
		printf("�����������ϵͳ���Զ��˳�\n");
		return 0;
	}
	return 0;
}




