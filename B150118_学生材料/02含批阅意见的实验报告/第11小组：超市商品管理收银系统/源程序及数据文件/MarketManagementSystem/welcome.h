//�ṹ����������
struct goods{
    char code[20];
    char name[30];
    double price;
    double chengben;
    int num;
    };
typedef struct goods goods;

struct order{
    int id;
    double total;
    double profit;
    };
typedef struct order order;
//������������
int login();
void adminabc();
void checkabc(int id,double total,double profit);
struct goods readcode();
void inputgoods();
void checkcode();
int ifexist();
void createorder();
int neworder();
void sale();
double totalprofit();
int checknum();
void showorder();
