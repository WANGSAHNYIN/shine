#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#define MAX_NAME 15
#define MAX_SEX 5


//����ע���¼ϵͳ�Ľṹ��
typedef struct Users
{
	char account[20];    //���ַ�������
	char code[20];       //����
}User;
struct student
{
	//ѧ��������Ϣ
	int xuehao;//ѧ��
	char name[MAX_NAME];//����
	int age;//����
	char sex[MAX_SEX];//�Ա�

	//��Ʒ��Ϣ
	int MerchKind_1;   //��Ʒ����---����
	int Money1;        //��������Ʒ���ѽ��
	int MerchKind_2;   //��Ʒ����---ѧϰ
	int Money2;        //ѧϰ����Ʒ���ѽ��
	int MerchKind_3;  //��Ʒ����---����	
	int Money3;
	int MerMon;       //�����ܽ��
	struct student* next;
};
typedef struct xiaofei X;
typedef struct student S;//�����ֽṹ��ֱ���X��S���
char filename[20] = "D:/StudentInfo.txt";//����ȫ�ֱ������������ݵ��ļ�
char filename_use[30] = "D:/Confidential_info.txt";
S* h;





//�˺������ڿ�ʼ����Ĳ���
void Start()
{
	printf("\t******************************************************\n");
	printf("\t*                                                    *\n");
	printf("\t*            ��ӭʹ��ѧ��������Ϣ����ϵͳ            *\n");
	printf("\t*            ������Ӧ����Ӧ������ѡ����            *\n");
	printf("\t*                                                    *\n");
	printf("\t******************************************************\n");
	printf("\t*                    0.�˳�                          *\n");
	printf("\t*                    1.��¼ϵͳ                      *\n");
	printf("\t*                    2.ע���µ��˺�                  *\n");
	printf("\t******************************************************\n");
	printf("\t*��������������:>");
}



//�û�ע�ắ��
void UserRegister()
{
	FILE* pf = NULL;
	User test, examine;
	/*���������ṹ�����,examine������ȡ�ļ��б�����˺�������Ϣ��
	test����ʹ����������Ϣ����ͨ��examine�ж�ʹ����������Ƿ��ظ�*/
	system("cls");
	printf("\t******************************************************\n");
	printf("\t*                    ע�����                        *\n");
	printf("\t******************************************************\n");
	if ((pf = fopen(filename_use, "rb")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		return;
	}
	fread(&examine, sizeof(User), 1, pf);
	printf("\t*������Ҫע����˺�:>");
	scanf("%s", test.account);//�����˺�
	while (1)
	{
		if (strcmp(test.account, examine.account))
		{
			if (!feof(pf))
			{
				fread(&examine.account, sizeof(User), 1, pf);//���ļ��е�������ע����˺Ű�������������Ƿ���֮�ظ�
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("��������˺��Ѵ���!ע��ʧ��...\n");
			fclose(pf);
			return;
		}
	}
	printf("\t*�������Ӧ������:>");
	scanf("%s", test.code);
	pf = fopen(filename_use, "ab");
	fwrite(&test, sizeof(User), 1, pf);
	system("cls");
	printf("\t******************************************************\n");
	printf("\t*                  �˺�ע��ɹ�!                     *\n");
	printf("\t******************************************************\n");
	printf("\t*���μ������˺���Ϣ:\n");
	printf("\t*�˺�:>%s\n", test.account);
	printf("\t*����:>%s\n", test.code);
	fclose(pf);//�ر��ļ�
	system("pause");
	system("cls");
	return;
}








//ѧ����Ϣ���뺯��
void shuru()
{
	S* m;//hͷָ�룬m��ָ�� �����ƶ���nβ��ָ�� ���𴴽��ڴ�
	h = m = (S*)malloc(sizeof(S));


	while (1) {
		S* n = (S*)malloc(sizeof(S));
		system("cls");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\t+                                                        +\n");
		printf("\t+               ����ʹ��ѧ����Ϣ¼�빦��                 +\n");
		printf("\t+                  ���ϸ��ո�ʽ����                    +\n");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\t+              ��ѧ�Ŵ�����0���˳�¼�빦��               +\n");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("*������ѧ����ѧ��:>");
		scanf("%d", &n->xuehao);
		if (n->xuehao == 0)break;
		printf("*������ѧ��������:>");
		scanf("%s", n->name);
		printf("*������ѧ��������:>");
		scanf("%d", &n->age);
		printf("*������ѧ�����Ա�(mΪ���ԣ�fΪŮ��):>");
		scanf("%s", n->sex);
		printf("*�������ѧ������������Ʒ������:>");
		scanf("%d", &n->MerchKind_1);
		printf("*�������ѧ������������Ʒ�����Ѷ�:>");
		scanf("%d", &n->Money1);
		printf("*�������ѧ������ѧϰ��Ʒ������:>");
		scanf("%d", &n->MerchKind_2);
		printf("*�������ѧ������ѧϰ��Ʒ�����Ѷ�:>");
		scanf("%d", &n->Money2);
		printf("*�������ѧ������������Ʒ������:>");
		scanf("%d", &n->MerchKind_3);
		printf("*�������ѧ������������Ʒ�����Ѷ�:>");
		scanf("%d", &n->Money3);
		printf("*������ѧ�����������ܽ��:>");
		scanf("%d", &n->MerMon);
		m->next = n;
		m = m->next;
	}
	m->next = NULL;
	printf("ѧ����Ϣ¼�����\n");

}
//�˵�����
void menu()
{
	printf("\t|------------------------------------------------------------------------|\n");
	printf("\t|                                                                        |\n");
	printf("\t|                        ��ӭʹ��ѧ�����Ѽ���ϵͳ                        |\n");
	printf("\t|                                                                        |\n");
	printf("\t|------------------------------------------------------------------------|\n");
	printf("\t|                          ������ϵͳ�����б�                            |\n");
	printf("\t|                            0.   �˳�                                   |\n");
	printf("\t|                            1.¼�������Ϣ                              |\n");
	printf("\t|                            2.չʾ�����Ϣ                              |\n");
	printf("\t|                            3.��ѯ�����Ϣ                              |\n");
	printf("\t|                            4.ɾ�������Ϣ                              |\n");
	printf("\t|                            5.��������Ϣ                              |\n");
	printf("\t|                            6.�޸������Ϣ                              |\n");
	printf("\t|                            7.ͳ�������Ϣ                              |\n");
	printf("\t|                            8.���������Ϣ                              |\n");
	printf("\t|------------------------------------------------------------------------|\n");
	printf("*����������ʹ����Ӧ����:>");
}
//ѧ����Ϣ¼�뺯��
void input()
{
	FILE* fp;
	S* p;
	if ((fp = fopen(filename, "a")) == NULL) {
		printf("�޷��򿪸��ļ�");
		exit(0);
	}

	printf("�ɹ�����Ϣ������ļ���\n");
	shuru();
	p = h->next;
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex,
			p->MerchKind_1, p->Money1, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("ѧ����Ϣ�ѱ������ļ� %s\n", filename);
	system("cls");
}
//ѧ����Ϣ�������
void output()
{
	system("cls");
	FILE* fp;
	S* m = NULL, * n = NULL; S* p_output;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("�޷��򿪸��ļ�");
		exit(0);
	}
	printf("�ɹ����ļ���\n");

	h = m = (S*)malloc(sizeof(S));
	while (!feof(fp))
	{
		n = (S*)malloc(sizeof(S));
		fscanf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", &n->xuehao, n->name, &n->age, n->sex, &n->MerchKind_1, &n->Money1
			, &n->MerchKind_2, &n->Money2, &n->MerchKind_3, &n->Money3, &n->MerMon);
		m->next = n;
		m = m->next;
	}
	m->next = NULL;
	printf("�ļ����ݶ�ȡ�ɹ�\n");
	fclose(fp);

	p_output = h->next;

	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                        +\n");
	printf("\t+               ����ʹ��ѧ����Ϣչʾ����                 +\n");
	printf("\t+                                                        +\n");
	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (p_output != NULL)
	{

		printf("*ѧ��ѧ��:>%d\t*ѧ������:>%s\n*ѧ������:>%d\t*ѧ���Ա�:>%s\n",
			p_output->xuehao, p_output->name, p_output->age, p_output->sex);
		printf("*��������Ʒ������:%d\t��������Ʒ���ѽ��:>%d\n*ѧϰ����Ʒ������:%d\tѧϰ����Ʒ���ѽ��:>%d\n*��������Ʒ������:%d\t��������Ʒ���ѽ��:>%d\n",
			p_output->MerchKind_1, p_output->Money1, p_output->MerchKind_2, p_output->Money2, p_output->MerchKind_3, p_output->Money3);
		printf("*�������������ܽ��:>%dԪ", p_output->MerMon);
		printf("\n");
		printf("-----------------------------------------------------\n");
		p_output = p_output->next;
	}
	printf("�������������");
	_getch();
	system("cls");
}
//��ѯ��Ϣ�ĺ���
void FindStudent()
{
	S* p_find;
	p_find = h->next;
	char a[15];
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   ����ʹ��ѧ����Ϣ��ѯ����                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("*������Ҫ���ҵ�ѧ��������:>");
	scanf("%s", a);
	while (1)
	{
		if (p_find == NULL) {

			break;
		}
		else if (strcmp(p_find->name, a) == 0)
		{
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t+                    �ɹ���ѯ��ѧ����Ϣ!                      +\n");
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("*ѧ��ѧ��Ϊ:>%d\n*ѧ������Ϊ:>%s\n*ѧ������Ϊ:>%d\n*ѧ���Ա�Ϊ:>%s\n", p_find->xuehao, p_find->name, p_find->age, p_find->sex);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t* *������Ʒ������:>%d *ѧϰ��Ʒ������:>%d *������Ʒ������:>%d\n", p_find->MerchKind_1, p_find->MerchKind_2, p_find->MerchKind_3);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t*������Ʒ���ѽ��:>%d *ѧϰ��Ʒ���ѽ��:>%d *������Ʒ���ѽ��:>%d\n", p_find->MerchKind_1, p_find->MerchKind_2, p_find->MerchKind_3);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t+                      ���������ܽ��:%dԪ                      +\n", p_find->MerMon);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			p_find = p_find->next;
			continue;
		}
		else if (p_find->next != NULL)
		{
			p_find = p_find->next;
		}


	}
	system("pause");
	system("cls");
}
//ͳ��ѧ����Ϣ�ĺ���
void StatStudent()
{
	S* p_stat;
	p_stat = h->next;
	system("cls");
	int count_num = 0;
	int count_male = 0;
	int count_female = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                        +\n");
	printf("\t+               ����ʹ��ѧ����Ϣͳ�ƹ���                 +\n");
	printf("\t+                                                        +\n");
	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (1)
	{
		if (p_stat != NULL)
		{
			count_num++;
			if (strcmp(p_stat->sex, "m") == 0)
			{
				count_male++;
			}
			else
			{
				count_female++;
			}

			one = one + (p_stat->MerchKind_1);
			two = two + (p_stat->MerchKind_2);
			three = three + (p_stat->MerchKind_3);
			p_stat = p_stat->next;
		}
		else
		{
			break;
		}
	}

	printf("*ѧ��������Ϊ:>%d\n", count_num);
	printf("*��������Ϊ:>%d\n", count_male);
	printf("*Ů������Ϊ:>%d\n", count_female);
	printf("*������������Ʒ����:>%d\n", one);
	printf("*����ѧϰ����Ʒ����:>%d\n", two);
	printf("*������������Ʒ����:>%d\n", three);
	system("pause");
	system("cls");
}
//����ѧ����Ϣ
void SortStudent()
{
	int i = 0;
	int j = 0;
	int n = 0;
	S* p;
	S temp;
	S arr[20];//�������滻�ڵ�
	FILE* fp;
	p = h->next;


	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   ����ʹ��ѧ����Ϣ������                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                    ��ѧ���������ѽ������                    +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (1) {

		arr[n] = *p;
		n++;
		if (p->next == NULL)break;
		p = p->next;
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {//ѡ������j=i+1��������Ҫ
			if ((arr[i].MerMon) < (arr[j].MerMon)) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}
	printf("�����ѽ���������£�\n");
	for (i = 0; i < n; i++) {
		printf("*ѧ��ѧ��:>%d  *ѧ������:>%s  *ѧ������:>%d  *ѧ���Ա�>%s\t*�����ܽ��:>%d\n",
			arr[i].xuehao, arr[i].name, arr[i].age, arr[i].sex, arr[i].MerMon);

	}
	system("pause");
	system("cls");

}
//�޸���Ϣ�ĺ���
void xiugai()
{//�������е����ݽ����޸�
	FILE* fp;
	S* p;
	int a; int i;//ѧ����ѧ��
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("�޷��򿪸��ļ�");
		exit(0);


	}//���ļ�
	p = h->next;
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   ����ʹ��ѧ����Ϣ�޸Ĺ���                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                    ͨ��ѧ��ѧ�Ų��������Ϣ                  +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*����ѧ��ѧ��:>");
	scanf("%d", &a);
	while (p->xuehao != a) {//ͨ��ѧ�Ž�������
		if (p->next == NULL) { printf("\t*���޴��ˣ���ȷ��ѧ��!\n"); break; }
		p = p->next;
	}
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                           ��ѯ�ɹ���                        +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                     ��ѡ����Ҫ�޸ĵ���Ϣ                    +\n");
	printf("\t+                        0.�˻����˵�                         +\n");
	printf("\t+                         1.ѧ��ѧ��                          +\n");
	printf("\t+                         2.ѧ������                          +\n");
	printf("\t+                         3.ѧ������                          +\n");
	printf("\t+                         4.ѧ���Ա�                          +\n");
	printf("\t+                     5.��������Ʒ������                      +\n");
	printf("\t+                     6.��������Ʒ���Ѷ�                      +\n");
	printf("\t+                     7.ѧϰ����Ʒ������                      +\n");
	printf("\t+                     8.ѧϰ����Ʒ���Ѷ�                      +\n");
	printf("\t+                     9.��������Ʒ������                      +\n");
	printf("\t+                    10.��������Ʒ���Ѷ�                      +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	scanf("%d", &i);

	switch (i)
	{
	case 1:printf("\t*��������ѧ��ѧ��"); scanf("%d", &p->xuehao); printf("�޸ĳɹ�"); break;
	case 2:printf("\t*��������ѧ������"); scanf("%s", p->name); printf("�޸ĳɹ�"); break;
	case 3:printf("\t*��������ѧ������"); scanf("%d", &p->age); printf("�޸ĳɹ�"); break;
	case 4:printf("\t*��������ѧ���Ա�"); scanf("%d", p->sex); printf("�޸ĳɹ�"); break;
	case 5:printf("\t*��������������Ʒ������:>"); scanf("%d", &p->MerchKind_1); printf("�޸ĳɹ�"); break;
	case 6:printf("\t*��������������Ʒ������:>"); scanf("%d", &p->Money1); printf("�޸ĳɹ�"); break;
	case 7:printf("\t*��������ѧϰ��Ʒ������:>"); scanf("%d", &p->MerchKind_2); printf("�޸ĳɹ�"); break;
	case 8:printf("\t*��������ѧϰ��Ʒ������:>"); scanf("%d", &p->Money2); printf("�޸ĳɹ�"); break;
	case 9:printf("\t*��������������Ʒ������:>"); scanf("%d", &p->MerchKind_3); printf("�޸ĳɹ�"); break;
	case 10:printf("\t*��������������Ʒ������:>"); scanf("%d", &p->Money3); printf("�޸ĳɹ�"); break;
	case 11:printf("\t*�������������ѽ��:>"); scanf("%d", &p->MerMon); break;
	default:printf("\t*���������������,����������!\n");
	}

	p = h->next;//������������ļ�
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("ѧ����Ϣ�ѱ������ļ� %s\n", filename);
}
//ɾ����Ϣ�ĺ���
void shanchu() {
	FILE* fp;
	S* p, * del;
	int a; //ѧ����ѧ��


	if ((fp = fopen(filename, "w")) == NULL) {
		printf("�޷��򿪸��ļ�");
		exit(0);
	}
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   ����ʹ��ѧ����Ϣɾ������                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                   ��ѧ��ѧ��ɾ��ѧ��������Ϣ                 +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*������ѧ��ѧ��:>");
	scanf("%d", &a);
	p = h->next;
	while (p->xuehao != (a - 1)) {
		if (p->next == NULL) { printf("���޴��ˣ���ȷ��ѧ��\n"); break; }
		p = p->next;
	}
	del = p->next;//ɾ������ʵ�ֵ���Ҫ���
	p->next = p->next->next;//ɾ������ʵ�ֵ���Ҫ���
	free(del);
	printf("��ѧ����Ϣɾ���ɹ�\n");

	p = h->next;//������������ļ�
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;

	}
	fclose(fp);
	printf("ѧ����Ϣ�ѱ������ļ� %s\n", filename);
}
//������Ϣ�ĺ���
void charu() {
	FILE* fp;
	S* p, * insert;
	int a; //ѧ����ѧ��


	if ((fp = fopen(filename, "w")) == NULL) {
		printf("�޷��򿪸��ļ�");
		exit(0);
	}
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                  ����ʹ��ѧ����Ϣ���빦��                   +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*��������Ҫ����λ�õ�ѧ��:>");
	scanf("%d", &a);
	p = h->next;
	while (p->xuehao != a) {
		if (p->next == NULL) { printf("���޴��ˣ���ȷ��ѧ��\n"); break; }
		p = p->next;
	}

	insert = (S*)malloc(sizeof(S));
	insert->next = p->next;//���빦��ʵ�ֵ���Ҫ���
	p->next = insert;////���빦��ʵ�ֵ���Ҫ���
	printf("\t*������ѧ��ѧ��:>");
	scanf("%d", &insert->xuehao);
	printf("\t*������ѧ������:>");
	scanf("%s", insert->name);
	printf("\t*������ѧ������:>");
	scanf("%d", &insert->age);
	printf("\t*������ѧ���Ա�:>");
	scanf("%s", insert->sex);
	printf("����ѧ����Ϣ��� \n");
	printf("*�������ѧ������������Ʒ������:>");
	scanf("%d", &insert->MerchKind_1);
	printf("*�������ѧ������������Ʒ�����Ѷ�:>");
	scanf("%d", &insert->Money1);
	printf("*�������ѧ������ѧϰ��Ʒ������:>");
	scanf("%d", &insert->MerchKind_2);
	printf("*�������ѧ������ѧϰ��Ʒ�����Ѷ�:>");
	scanf("%d", &insert->Money2);
	printf("*�������ѧ������������Ʒ������:>");
	scanf("%d", &insert->MerchKind_3);
	printf("*�������ѧ������������Ʒ�����Ѷ�:>");
	scanf("%d", &insert->Money3);
	printf("*������ѧ�����������ܽ��:>");
	scanf("%d", &insert->MerMon);
	p = h->next;//������������ļ�
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("ѧ����Ϣ�ѱ������ļ� %s\n", filename);
}




//�û���¼����
void UserLog()
{
	system("cls");
	FILE* pf = NULL;
	User test, examine;    /*��ע�ắ������ͬ��test����ʹ���������˺ŵ���Ϣ��
						  examine���ڵ��Լ�������Ƿ���ȷ*/
	if ((pf = fopen(filename_use, "rb")) == NULL)
	{
		printf("���ļ�ʧ��!\n");
		return;
	}
	printf("\t******************************************************\n");
	printf("\t*                    ��¼����                        *\n");
	printf("\t******************************************************\n");
	fread(&examine, sizeof(User), 1, pf);
	printf("\t*����������˺�:>");
	scanf("%s", test.account);
	while (1)    //ͨ��whileѭ�����֮ǰ�Ƿ�ע������˺�
	{
		if (strcmp(test.account, examine.account) == 0)
		{
			break;
		}
		else {
			if (!feof(pf))//����һ��ģ������ݺ��ļ�λ�ñ�ǻ��ƶ�����һģ��
			{
				fread(&examine, sizeof(User), 1, pf);
			}
			else {
				printf("\t*���˺Ų�����,��ѡ��ע���˺Ż�����������!\n");
				fclose(pf);
				int repeat;
				printf("\t******************************************************\n");
				printf("\t*                    0.�˳�                          *\n");
				printf("\t*                    1.ע���˺�                      *\n");
				printf("\t*                    2.��������                      *\n");
				printf("\t******************************************************\n");
				do
				{
					printf("\t*�����������:>");
					scanf("%d", &repeat);
					switch (repeat)
					{
					case 0:break;
					case 1:
						UserRegister();    //û���˺�,����ע�����
						return;
					case 2:
						UserLog();      //ͨ��ʹ�ú����ݹ飬���½����¼����
					default:
						printf("\t�������,������������\n");
					}
				} while (repeat);
			}
		}
	}


	//�����Ǽ�����������Ƿ���ȷ
	int lim = 0; //�涨���������Դ�Ĵ���
	for (lim = 1; lim < 4; lim++)
	{
		printf("\t*��������������:>");
		scanf("%s", test.code);
		if (!strcmp(test.code, examine.code))
		{
			system("cls");
			printf("\t|------------------------------------------------------------------------|\n");
			printf("\t|                               ��½�ɹ�                                 |\n");
			printf("\t|------------------------------------------------------------------------|\n");
			printf("\t|************************************************************************|\n");
			fclose(pf);
			//����¼�ɹ�,��ֱ�ӽ���ϵͳ����ʹ�ý���
			int a;
			do {
				menu();
				scanf("%d", &a);
				switch (a)
				{
				case 0:
					printf("�˳��ɹ�!\n"); break;
				case 1:
					input();
					break;
				case 2:
					output();
					break;
				case 3:
					FindStudent();
					break;
				case 7:
					StatStudent();
					break;
				case 8:
					SortStudent();
					break;
				case 4:
					shanchu();
					break;
				case 5:
					charu();
					break;
				case 6:
					xiugai();
					break;
				}
			} while (a);
			return;
		}
		else {
			printf("\t******************************************************\n");
			printf("\t*                  ���������������!                 *\n");
			printf("\t*                  ��ʣ��%d���������                 *\n", 3 - lim);
			printf("\t******************************************************\n");
		}
	}
	//�������������ȷ����ֱ�ӽ��빦��ʹ�ý���
	//����Դ����ȫ�����꣬����˵���¼����
	return;
}
//����������
int main()
{
	int remote = 0;
	do
	{
		system("cls");
		Start();
		scanf("%d", &remote);
		switch (remote)
		{
		case 0:
			return 0;
		case 1:
			UserLog();
			break;
		case 2:
			UserRegister();
			break;
		default:
			printf("�������������������������!\n");
			system("pause");
			system("cls");
		}
	} while (remote);
	return 0;
}