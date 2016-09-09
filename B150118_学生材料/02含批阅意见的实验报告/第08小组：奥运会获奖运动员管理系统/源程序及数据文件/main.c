#include <stdio.h>
#include <string.h>
#include <malloc.h>

//�����˶�Ա�ṹ�� 
struct Athlete{
	long project;        
	char name[20];  //���� 
	char sex[10];   //�Ա� 
	int  num[3];   //��������ͭ����Ŀ 
	int  total;
	int  form;
};

void copyAthlete(struct Athlete* dest,struct Athlete* src){     //�����˶�Ա��Ϣ 
	dest->project = src->project;
	memcpy(dest->name,src->name,20*sizeof(char));
	memcpy(dest->sex,src->sex,10*sizeof(char));
	memcpy(dest->num,src->num,3*sizeof(int));
	dest->total = src->total;
	dest->form = src->form;
}

void listAthleteByGold(struct Athlete athletes[],int total){                    //���ս������� 
	int i,j;
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));     //temp�������� 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));         //���������˶�Ա��Ϣ���������� 
	
	for(i=0;i<total-1;i++){                                                //ð�����򣬸��ݽ������� 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[0] > athletes_temp[j+1].num[0]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("��ý����������ٵ��������ǣ�\n");                         //��ӡ��Ϣ 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[0]);
	}
	
}

void listAthleteBySilver(struct Athlete athletes[],int total){                 //������������ 
	int i,j;
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));         //temp�������� 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));                     //���������˶�Ա��Ϣ���������� 
	
	for(i=0;i<total-1;i++){                                                        //ð�����򣬸����������� 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[1] > athletes_temp[j+1].num[1]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("��������������ٵ��������ǣ�\n");                                        //��ӡ��Ϣ 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[1]);
	}
	
}


void listAthleteByCopper(struct Athlete athletes[],int total){                        //����ͭ������ 
	int i,j; 
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));             //temp�������� 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));                    //���������˶�Ա��Ϣ���������� 
	
	for(i=0;i<total-1;i++){                                                        //ð�����򣬸����������� 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[2] > athletes_temp[j+1].num[2]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("���ͭ���������ٵ��������ǣ�\n");                                         //��ӡ��Ϣ 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[2]);
	}
	
}

void getMostGoldAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostGold = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[0]>mostGold){
			mostGold = athletes[i].num[0];                         //����������ֵ 
			j = i;
		}
	}
	printf("��ý��������������˶�Ա:%s\n", athletes[j].name);
}

void getMostSilverAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostSilver = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[1]>mostSilver){
			mostSilver = athletes[i].num[1];                  //�����������ֵ 
			j = i;
		}
	}
	printf("������������������˶�Ա:%s\n", athletes[j].name);
}

void getMostCopporAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostCoppor = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[2]>mostCoppor){
			mostCoppor = athletes[i].num[2];                //����ͭ�����ֵ 
			j = i;
		}
	}
	printf("���ͭ�������������˶�Ա:%s\n", athletes[j].name);
}

void getAthleteByName(struct Athlete athletes[],int total){
	int i;
	char name[20];
	printf("�������˶�Ա�������в�ѯ�����������:");
	scanf("%s", name);                                    //�����ѯ���� 
	for (i = 0; i < total; i++){                                //�������� 
		if (strcmp(name, athletes[i].name) == 0){
			printf("������%s �Ա�%s ��������%d ������:%d ͭ����:%d\n",athletes[i].name, athletes[i].sex, 
				athletes[i].num[0], athletes[i].num[1], athletes[i].num[2]);
			break;                                        //���Ѿ��ҵ���������forѭ�� 
		}
	}
	if (i == 20){
		printf("%s������\n", name);                     //i�ӵ���20��˵��ǰ��һֱû����forѭ����Ҳ����һֱû�ҵ� 
	}
	
} 

int main(){
	FILE* filep = NULL;
	struct Athlete athletes[20];          //����������ļ���ȡ���˶�Ա��Ϣ 
	char name[20];
	int i = 0;
	int total;
	int choice;
	filep =	fopen("Athlete.txt","r");              //����ǰ¼����Ϣ���ļ� 
	if (filep == NULL){
		printf("Athlete.txt do not exist\n");      //�ļ������ڣ���ʧ�� 
		return 0;
	}

	while (!feof(filep)){                           //��ȡ�ļ���Ϣ��ֱ����ȡ��� 
		fscanf(filep, "%ld%s%s%d%d%d%d%d", &athletes[i].project, &athletes[i].name, &athletes[i].sex,
			&athletes[i].num[0], &athletes[i].num[1], &athletes[i].num[2], &athletes[i].total, &athletes[i].form);
		++i;
	}
	total = i - 1; 	                            //��ȡ���˶�Ա���� 
	printf("##########################################\n");             //��ӡ�˵� 
	printf("###  ��ӭ������˻���˶�Ա����ϵͳ  ###\n");
	printf("###  1: �����ֲ�ѯ�˶�Ա�����       ###\n");
	printf("###  2: ���ҽ��������˶�Ա           ###\n");
	printf("###  3: �������������˶�Ա           ###\n");
	printf("###  4: ����ͭ�������˶�Ա           ###\n");
	printf("###  5: ���ս�����Ŀ�����˶�Ա         ###\n");
	printf("###  6: ����������Ŀ�����˶�Ա         ###\n");
	printf("###  7: ����ͭ����Ŀ�����˶�Ա         ###\n");
	printf("###  8: �˳�ϵͳ\n");
	printf("##########################################\n");
	while(1){
		printf("please input your choice:"); 
		scanf("%d", &choice);                                  //��ȡ�û��˵�ѡ�� 
		switch(choice){
			case 1:
				getAthleteByName(athletes,total);
				break;
			case 2:
				getMostGoldAthlete(athletes,total);
				break;
			case 3: 
			    getMostSilverAthlete(athletes,total);
			    break;
			case 4:
				getMostCopporAthlete(athletes,total);
				break;
			case 5:
				listAthleteByGold(athletes,total);
				break;
			case 6:
			    listAthleteBySilver(athletes,total);
			    break;
			case 7:
				listAthleteByCopper(athletes,total);
				break; 
			case 8:
				return;
			default:
				printf("input invalid\n");            //���������������� 
				continue;
		}
	}

	
	
    return 0; 

}
