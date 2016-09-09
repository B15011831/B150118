#include<stdio.h>
#include "welcome.h"
#include<stdlib.h>
#include <time.h>
//�����Ƿ���ں���
int ifexist(char code[])
{
    int a = 0;
    goods read;
    FILE *fp;
    if(fp = fopen(".\\goods.txt","r")) //�ļ���
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //��ȡ�ļ�
            if(!strcmp(code,read.code))
            {
                fclose(fp);
                a = 1;
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    if(a==0)
        printf("���벻���ڣ�����������\n");
    return a;
}

double totalprofit()
{
    int id;
    double total=0,profit=0,abc=0;
    FILE *fp;
    if(fp = fopen(".\\order.txt","r"))//�ļ���
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %lf %lf\n",&id,&total,&profit);//��ȡ���ж�����Ϣ���������ܺ�����
            abc = abc+profit;
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    return total;
}




//ɨ�� ���ز�ѯ����������Ϣ
struct goods readcode(char code[])
{
    goods read;
    FILE *fp;
    if(fp = fopen(".\\goods.txt","r"))
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code)) //������Ҫ������
            {
                fclose(fp);
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    return read;
}

//��ʾ���е�ȫ����Ʒ
void showgoods()
{
    system("cls");
    goods read;
    FILE *fp;
    if(fp = fopen(".\\goods.txt","r")) //�ļ���
    {
        printf("\n\n\n\n***************************************************************\n");
        printf("   **����**     **����**   **�ۼ�**   **�ɱ�**      **����**   \n");
        while(!feof(fp))
        {

            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //��ȡ�ļ�
            printf("%10s   %10s %10.2f %10.2f   %10d\n",read.code,read.name,read.price,read.chengben,read.num);
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
    printf("�밴�����������һ��˵�");
    getchar();
    getchar();
    system("cls");
    adminabc();

}
//����µ���Ʒ
int addgoods(char code[],char name[],char price[],char chengben[],char num[])
{
    FILE *fp;
    if(fp = fopen(".\\goods.txt","a+")) //���ļ�
    {
        fprintf(fp,"\n%s %s %s %s %s          \n          ",code,name,price,chengben,num); //����һ���ĸ�ʽ��д���ļ�
        fclose(fp);
        return 1;
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
        return 0;
    }
}

//д��������Ϣ����������
void createorder(double price,double profit)
{
    int id;
    order add;
    add.id = neworder();//���������������������
    add.total = price;
    add.profit = profit;
    printf("�����������\n");
    FILE *fp;
    if(fp = fopen(".\\order.txt","a+"))
    {
        id = neworder();
        fprintf(fp,"\n%d %.2f %.2f",id,add.total,add.profit);//д���ļ�����ʾ���ζ����۸�
        fclose(fp);
        printf("\n\n���ζ����ţ�%d�ܼ۸�%.2f\n\n",id,add.total);
        checkabc(add.id,add.total,add.profit);
        return 1;
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
        return 0;
    }

}
//����һ
void sale(char code[])
{
    goods read;
    FILE *fp;
    char c = ' ',d[20],e[20];
    if(fp = fopen(".\\goods.txt","r+"))//���ļ�
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);//��ȡ���ݽ���ṹ�����
            if(!strcmp(code,read.code))
            {
              while(c == ' ') //�ļ�ָ����ҵ���һ���ַ���
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//�ļ�ָ�붨λ���
            c = '1';
                while(c != ' ') //�ļ�ָ����ҵ���һ���ո�
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//�ļ�ָ�붨λ���
                fprintf(fp,"          ");
                 fseek(fp,-10,1);
                sprintf(e,"%d\n",read.num-1);//��д����ֹλ���仯��������
                fputs(e,fp);
                fclose(fp); //�ر��ļ�
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
}
//���+1 ˼·ͬ��
void saleadd(char code[])
{
    goods read;
    FILE *fp;
    char c = ' ',d[20],e[20];
    if(fp = fopen(".\\goods.txt","r+"))//���ļ�
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);//��ȡ���ݽ���ṹ�����
            if(!strcmp(code,read.code))
            {
              while(c == ' ') //�ļ�ָ����ҵ���һ���ַ���
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//�ļ�ָ�붨λ���
            c = '1';
                while(c != ' ') //�ļ�ָ����ҵ���һ���ո�
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//�ļ�ָ�붨λ���
                fprintf(fp,"          ");
                 fseek(fp,-10,1);
                sprintf(e,"%d\n",read.num+1);//��д����ֹλ���仯��������
                fputs(e,fp);
                fclose(fp); //�ر��ļ�
                break;
            }
        }
    }
    else
    {
        printf("�ļ����ش����������ݿ��ļ�");
    }
}


//�������������
int neworder()
{
    int id;
    goods read;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //�������������
    return id;
}
