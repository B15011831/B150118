#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
//��¼����
int login()
{
    printf("\t\t\t***************************\n");
    printf("\t\t\t��ӭ��¼������Ʒ������ϵͳ\n");
    printf("\t\t\t***************************\n");
    printf("\t\t\t�������û�����");
    char user_name[200];
    char user_password[200];
    int c=0,i=0;
    scanf("%s",&user_name);
    printf("\t\t\t���������룺");
    while ((c=getch()) != '\r') //ʹ���������ʱ����ʾ*��
    {
        user_password[i++] = c;
        putchar('*');
    }
    user_password[i] = '\0';
    char admin[] = "root"; //��֤�˺����������Ӧ�ĺ���
    char adminpassword[] = "123456";
    char check[] = "check";
    char checkpassword[] = "123456";
    if(!strcmp(user_name,admin)&& !strcmp(user_password,adminpassword))
    {
        system("cls");
        printf("\n\t\t\t\t����Ա���\n");
        adminabc();
    }
    else
    {
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            system("cls");
            printf("\t\t\t************************\n");
            printf("\t\t\t\t����Ա���\n");
            checkabc(0,0.0,0.0);
        }
        else
        {
            printf("\n\t\t\t�û������������,�밴�س����µ�¼\n");
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
//����Ա����
void checkabc(int id,double total,double profit){
 int command;
    printf("\t\t\t    ��ӭ��������Աϵͳ\n");
    printf("\t\t\t************************\n\n\n");
    printf("\t\t        1����\n\t\t        2������������\n\t\t        3����������\n\n\n");
    do                  //����Ƿ�������ȷ��ָ�������������������
    {
        printf("\t\t\t\t���������");
        scanf("%d",&command);
        printf("\n");
        if(command!=1&&command!=2)
            printf("\t\t\t\t�������\n�ٴ�");

    }
    while(command!=1&&command!=2&&command!=3);
    if(command==1)           //1����������Ա����  2�����뱾����������
    {
        system("cls");
        checkcode();
    }
    else
    {
        if(command==3)
        {
        system("cls");
        login();
        }
        else
        {
        system("cls");
        printf("\t\t\t\t**********************\n");
        printf("\t\t\t\t ��ӭ�鿴����Ӫ������\n\t\t\t\t**********************\n���ζ����ţ�%d\n �ܼ۸�%.2f%\n  ����%.2f\n",id,total,profit);
         printf("\n\n\n�������������һ��");
         getchar();
         getchar();
         system("cls");
        checkabc(id,total,profit);
        }
    }
    return 0;
}


// ¼�뺯��
void inputgoods()
{
    system("cls");
    char code[20];
    char name[20],num[20],price[20],chengben[20],end[20] = "end";
    int s;

    do
    {
        printf("\n\n*************************************************************\n");
        printf("\t��ֱ������Ʒ��Ϣ(�Կո����������end��������)\n");
        printf("*************************************************************\n\n");
        printf("\t****����***��Ʒ����***�۸�***�ɱ�***���****\n\n");
        printf("\t");
        scanf("%s",code);
        if(!strcmp(code,end)){
                system("cls");
            adminabc();
        }
        scanf("%s%s%s%s",name,price,chengben,num);
        if(!checknum(num) && !checknum(code) && !checknum(chengben) && !checknum(price))
            {
             printf("\n\t\t\t***********************");
             printf("\n\t\t\t      ����:%s\n\t\t\t      ����:%s\n\t\t\t      �۸�:%s       \n\t\t\t      �ɱ�:%s       \n\t\t\t      ���:%s\n",code,name,price,chengben,num);
              printf("\t\t\t***********************\n");
            }
        else{
            printf("���������������������롣\n");
             s = 1;
            continue;

            }
       if(addgoods(code,name,price,chengben,num))
            printf("\t**��ӳɹ�**");
       else
            printf("���ʧ��");
        printf("\n�Ƿ���� 1�� or 2��\n\n");
        scanf("%d",&s);
        if(s==2)
        {
            system("cls");
            adminabc();
        }
    }
    while (s==1);
}

//��������
void checkcode()
{
    char code[20],endcode[20]="q",number[20],deletecode[20]="d";
    int flag=0;
    goods good[100]; //�ṹ�����鴢���Ѿ��յ�������
    int i=0,c=1,d=0,e = 0;
    double total=0.0,numdouble,intnum[100];
    order profit;
    printf("��ӭ��������ϵͳ\n��������Ʒ�������Լ�����Ҫ������(����q����,����d����ɾ��ģʽ)��\n");
    do
    {
        scanf("%s",code); //���ȼ���ǲ���������end
        if(!strcmp(code,endcode))
            break;
        //ɾ��ģʽ��ʼ
        if(!strcmp(code,deletecode))
        {
            if(flag == 0) // ���flag��0 ����Ϊû��������Ʒ
            {
                printf("�㻹û�������κ���Ʒ�����������롣");
                checkcode();
            }
            printf("���ѽ���ɾ��ģʽ��������Ҫɾ������Ʒ�������Լ�����Ҫɾ����������(����q����)\n");
            printf("���ι������Ʒ��\n");
            printf("       ����         ����    ����     \n");
            for(d=0; d<i; d++) //����������ڶ����������Ʒ
            {
                printf("%10s%10s%10.0f\n",good[d].code,good[d].name,intnum[d+1]);
            }
            do
            {
                scanf("%s",code);
                if(!strcmp(code,endcode))
                    break;
                scanf("%s",number);
                if(checknum(code) || checknum(number)) // ������˼��
                {
                    printf("����������������������");
                    continue;
                }
                numdouble = atof(number); //�������������ת����ʵ��
                if(numdouble <= 0)
                {
                    printf("����������������������");
                    continue;
                }
                if(ifexist(code))
                {
                    good[i++] = readcode(code);
                    if(good[i-1].num>0)

                    {
                        c=1;
                        for(; c<=numdouble; c++) //���ݽṹ���������Ϣ��������Ʒ
                        {
                            total = total-good[i-1].price;
                            profit.profit = profit.profit - (good[i-1].price-good[i-1].chengben);
                            profit.total = total;
                            saleadd(good[i-1].code);
                        } //���+һ
                        printf("��Ʒ���ƣ�%10s �۸�%10.2fԪ ɾ������:%10.0f \n���ܼ�:%10.2fԪ\n",good[i-1].name,good[i-1].price,numdouble,total);
                    }
                    else
                    {
                        printf("����Ʒ������������������"); //�����Ʒ�Ƿ�������
                        continue;
                    }
                }
                else
                {
                    continue;

                }
            }
            while(1);
            printf("\n��������Ʒ�������Լ�����Ҫ������(����end����)��\n");
            continue;
        }
        //ɾ��ģʽ����
        //�����Ʒ
        scanf("%s",number);
        if(checknum(code) || checknum(number))
        {
            printf("����������������������");
            continue;
        }
        numdouble = atof(number);
        intnum[++e] = numdouble;
        if(numdouble <= 0)
        {
            printf("����������������������");
            continue;
        }
        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {

                c=1;
                for(; c<=numdouble; c++)
                {
                    total = total+good[i-1].price;
                    profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                    profit.total = total;
                    sale(good[i-1].code);
                    flag = 1; //�б����Ѿ�����Ʒ�ˡ�
                } //����һ
                printf("��Ʒ���ƣ�%10s �۸�%10.2fԪ ��������:%10.0f \n�ܼ�:%10.2fԪ\n",good[i-1].name,good[i-1].price,numdouble,total);
            }
            else
            {
                printf("\t\t\t\t����Ʒ������������������");
                continue;
            }
        }
        else
        {
            continue;

        }
    }
    while(1);
    createorder(profit.total,profit.profit);//����������д���ļ�

}

// ����Ա��ں���
void adminabc()
{
    int a;
    char b;
    do
    {
        printf("       ******************************\n");
        printf("            ��ӭ�������Աҳ��\n");
        printf("       ******************************\n");
        printf("  \t**    1��Ʒ��Ϣ¼��       **\n  \t**    2��Ʒ�������б�   **\n  \t**    3�������󱨱�       **\n  \t**    4���ص�¼ҳ��       **\n");
        printf("        ****************************\n\n\n");
        printf("\t**���������");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("������������������!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a)
    {
    case 1:
        inputgoods();
        break;
    case 2:
        showgoods();
        break;
    case 3:
        printf("����������:%.2f",totalprofit());
        printf("�������������һ��");
        getchar();
        getchar();
        system("cls");
        adminabc();
        break;
    case 4:
        system("cls");
        login();
        break    ;
    }


}
//������˺���
int checknum(const char*num)
{
    int i;
    for(i=0; i<20; i++)
    {
        if(num[i]=='\0') break;
        if(!(num[i]>='0'&&num[i]<='9'||num[i]=='\0'||num[i]== '.'))
        {
            //printf("%s",num);
            return 1;
            break;
        }
    }

    return 0;
}
