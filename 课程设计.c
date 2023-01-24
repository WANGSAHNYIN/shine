#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#define MAX_NAME 15
#define MAX_SEX 5


//用于注册登录系统的结构体
typedef struct Users
{
	char account[20];    //用字符串定义
	char code[20];       //密码
}User;
struct student
{
	//学生基本信息
	int xuehao;//学号
	char name[MAX_NAME];//姓名
	int age;//年龄
	char sex[MAX_SEX];//性别

	//商品信息
	int MerchKind_1;   //商品种类---日用
	int Money1;        //日用类商品消费金额
	int MerchKind_2;   //商品种类---学习
	int Money2;        //学习类商品消费金额
	int MerchKind_3;  //商品种类---娱乐	
	int Money3;
	int MerMon;       //消费总金额
	struct student* next;
};
typedef struct xiaofei X;
typedef struct student S;//将两种结构体分别用X和S替代
char filename[20] = "D:/StudentInfo.txt";//定义全局变量，储存数据的文件
char filename_use[30] = "D:/Confidential_info.txt";
S* h;





//此函数用于开始界面的布置
void Start()
{
	printf("\t******************************************************\n");
	printf("\t*                                                    *\n");
	printf("\t*            欢迎使用学生消费信息记账系统            *\n");
	printf("\t*            输入相应的相应的数字选择功能            *\n");
	printf("\t*                                                    *\n");
	printf("\t******************************************************\n");
	printf("\t*                    0.退出                          *\n");
	printf("\t*                    1.登录系统                      *\n");
	printf("\t*                    2.注册新的账号                  *\n");
	printf("\t******************************************************\n");
	printf("\t*请输入您的数字:>");
}



//用户注册函数
void UserRegister()
{
	FILE* pf = NULL;
	User test, examine;
	/*定义两个结构体变量,examine用来读取文件中保存的账号密码信息，
	test用于使用者输入信息，再通过examine判断使用者输入的是否重复*/
	system("cls");
	printf("\t******************************************************\n");
	printf("\t*                    注册界面                        *\n");
	printf("\t******************************************************\n");
	if ((pf = fopen(filename_use, "rb")) == NULL)
	{
		printf("文件打开失败!\n");
		return;
	}
	fread(&examine, sizeof(User), 1, pf);
	printf("\t*请输入要注册的账号:>");
	scanf("%s", test.account);//创建账号
	while (1)
	{
		if (strcmp(test.account, examine.account))
		{
			if (!feof(pf))
			{
				fread(&examine.account, sizeof(User), 1, pf);//将文件中的所有已注册的账号挨个调出来检查是否与之重复
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("您输入的账号已存在!注册失败...\n");
			fclose(pf);
			return;
		}
	}
	printf("\t*请输入对应的密码:>");
	scanf("%s", test.code);
	pf = fopen(filename_use, "ab");
	fwrite(&test, sizeof(User), 1, pf);
	system("cls");
	printf("\t******************************************************\n");
	printf("\t*                  账号注册成功!                     *\n");
	printf("\t******************************************************\n");
	printf("\t*请牢记您的账号信息:\n");
	printf("\t*账号:>%s\n", test.account);
	printf("\t*密码:>%s\n", test.code);
	fclose(pf);//关闭文件
	system("pause");
	system("cls");
	return;
}








//学生信息输入函数
void shuru()
{
	S* m;//h头指针，m中指针 负责移动，n尾部指针 负责创建内存
	h = m = (S*)malloc(sizeof(S));


	while (1) {
		S* n = (S*)malloc(sizeof(S));
		system("cls");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\t+                                                        +\n");
		printf("\t+               正在使用学生信息录入功能                 +\n");
		printf("\t+                  请严格按照格式输入                    +\n");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\t+              在学号处输入0以退出录入功能               +\n");
		printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("*请输入学生的学号:>");
		scanf("%d", &n->xuehao);
		if (n->xuehao == 0)break;
		printf("*请输入学生的姓名:>");
		scanf("%s", n->name);
		printf("*请输入学生的年龄:>");
		scanf("%d", &n->age);
		printf("*请输入学生的性别(m为男性，f为女性):>");
		scanf("%s", n->sex);
		printf("*请输入该学生购买日用商品的数量:>");
		scanf("%d", &n->MerchKind_1);
		printf("*请输入该学生购买日用商品的消费额:>");
		scanf("%d", &n->Money1);
		printf("*请输入该学生购买学习商品的数量:>");
		scanf("%d", &n->MerchKind_2);
		printf("*请输入该学生购买学习商品的消费额:>");
		scanf("%d", &n->Money2);
		printf("*请输入该学生购买娱乐商品的数量:>");
		scanf("%d", &n->MerchKind_3);
		printf("*请输入该学生购买娱乐商品的消费额:>");
		scanf("%d", &n->Money3);
		printf("*请输入学生本月消费总金额:>");
		scanf("%d", &n->MerMon);
		m->next = n;
		m = m->next;
	}
	m->next = NULL;
	printf("学生信息录入完毕\n");

}
//菜单函数
void menu()
{
	printf("\t|------------------------------------------------------------------------|\n");
	printf("\t|                                                                        |\n");
	printf("\t|                        欢迎使用学生消费记账系统                        |\n");
	printf("\t|                                                                        |\n");
	printf("\t|------------------------------------------------------------------------|\n");
	printf("\t|                          以下是系统功能列表                            |\n");
	printf("\t|                            0.   退出                                   |\n");
	printf("\t|                            1.录入相关信息                              |\n");
	printf("\t|                            2.展示相关信息                              |\n");
	printf("\t|                            3.查询相关信息                              |\n");
	printf("\t|                            4.删除相关信息                              |\n");
	printf("\t|                            5.添加相关信息                              |\n");
	printf("\t|                            6.修改相关信息                              |\n");
	printf("\t|                            7.统计相关信息                              |\n");
	printf("\t|                            8.排序相关信息                              |\n");
	printf("\t|------------------------------------------------------------------------|\n");
	printf("*输入数字以使用相应功能:>");
}
//学生信息录入函数
void input()
{
	FILE* fp;
	S* p;
	if ((fp = fopen(filename, "a")) == NULL) {
		printf("无法打开该文件");
		exit(0);
	}

	printf("成功打开信息保存的文件！\n");
	shuru();
	p = h->next;
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex,
			p->MerchKind_1, p->Money1, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("学生信息已保存至文件 %s\n", filename);
	system("cls");
}
//学生信息输出函数
void output()
{
	system("cls");
	FILE* fp;
	S* m = NULL, * n = NULL; S* p_output;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("无法打开该文件");
		exit(0);
	}
	printf("成功打开文件！\n");

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
	printf("文件数据读取成功\n");
	fclose(fp);

	p_output = h->next;

	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                        +\n");
	printf("\t+               正在使用学生信息展示功能                 +\n");
	printf("\t+                                                        +\n");
	printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (p_output != NULL)
	{

		printf("*学生学号:>%d\t*学生姓名:>%s\n*学生年龄:>%d\t*学生性别:>%s\n",
			p_output->xuehao, p_output->name, p_output->age, p_output->sex);
		printf("*日用类商品购买量:%d\t日用类商品消费金额:>%d\n*学习类商品购买量:%d\t学习类商品消费金额:>%d\n*娱乐类商品购买量:%d\t娱乐类商品消费金额:>%d\n",
			p_output->MerchKind_1, p_output->Money1, p_output->MerchKind_2, p_output->Money2, p_output->MerchKind_3, p_output->Money3);
		printf("*该生本月消费总金额:>%d元", p_output->MerMon);
		printf("\n");
		printf("-----------------------------------------------------\n");
		p_output = p_output->next;
	}
	printf("按任意键继续！");
	_getch();
	system("cls");
}
//查询信息的函数
void FindStudent()
{
	S* p_find;
	p_find = h->next;
	char a[15];
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   正在使用学生信息查询功能                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("*请输入要查找的学生的姓名:>");
	scanf("%s", a);
	while (1)
	{
		if (p_find == NULL) {

			break;
		}
		else if (strcmp(p_find->name, a) == 0)
		{
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t+                    成功查询到学生信息!                      +\n");
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("*学生学号为:>%d\n*学生姓名为:>%s\n*学生年龄为:>%d\n*学生性别为:>%s\n", p_find->xuehao, p_find->name, p_find->age, p_find->sex);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t* *生活用品消费量:>%d *学习用品消费量:>%d *娱乐用品消费量:>%d\n", p_find->MerchKind_1, p_find->MerchKind_2, p_find->MerchKind_3);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t*生活用品消费金额:>%d *学习用品消费金额:>%d *娱乐用品消费金额:>%d\n", p_find->MerchKind_1, p_find->MerchKind_2, p_find->MerchKind_3);
			printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t+                      本月消费总金额:%d元                      +\n", p_find->MerMon);
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
//统计学生信息的函数
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
	printf("\t+               正在使用学生信息统计功能                 +\n");
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

	printf("*学生总人数为:>%d\n", count_num);
	printf("*男性人数为:>%d\n", count_male);
	printf("*女性人数为:>%d\n", count_female);
	printf("*购买日用类商品总量:>%d\n", one);
	printf("*购买学习类商品总量:>%d\n", two);
	printf("*购买娱乐类商品总量:>%d\n", three);
	system("pause");
	system("cls");
}
//排序学生信息
void SortStudent()
{
	int i = 0;
	int j = 0;
	int n = 0;
	S* p;
	S temp;
	S arr[20];//用数组替换节点
	FILE* fp;
	p = h->next;


	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   正在使用学生信息排序功能                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                    按学生本月消费金额排序                    +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (1) {

		arr[n] = *p;
		n++;
		if (p->next == NULL)break;
		p = p->next;
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {//选择排列j=i+1，超级重要
			if ((arr[i].MerMon) < (arr[j].MerMon)) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}
	printf("按消费金额排序如下：\n");
	for (i = 0; i < n; i++) {
		printf("*学生学号:>%d  *学生姓名:>%s  *学生年龄:>%d  *学生性别：>%s\t*消费总金额:>%d\n",
			arr[i].xuehao, arr[i].name, arr[i].age, arr[i].sex, arr[i].MerMon);

	}
	system("pause");
	system("cls");

}
//修改信息的函数
void xiugai()
{//对链表中的数据进行修改
	FILE* fp;
	S* p;
	int a; int i;//学生的学号
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("无法打开该文件");
		exit(0);


	}//打开文件
	p = h->next;
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   正在使用学生信息修改功能                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                    通过学生学号查找相关信息                  +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*输入学生学号:>");
	scanf("%d", &a);
	while (p->xuehao != a) {//通过学号进行搜素
		if (p->next == NULL) { printf("\t*查无此人，请确认学号!\n"); break; }
		p = p->next;
	}
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                           查询成功！                        +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                     请选择你要修改的信息                    +\n");
	printf("\t+                        0.退回主菜单                         +\n");
	printf("\t+                         1.学生学号                          +\n");
	printf("\t+                         2.学生姓名                          +\n");
	printf("\t+                         3.学生年龄                          +\n");
	printf("\t+                         4.学生性别                          +\n");
	printf("\t+                     5.日用类商品购买量                      +\n");
	printf("\t+                     6.日用类商品消费额                      +\n");
	printf("\t+                     7.学习类商品购买量                      +\n");
	printf("\t+                     8.学习类商品消费额                      +\n");
	printf("\t+                     9.娱乐类商品购买量                      +\n");
	printf("\t+                    10.娱乐类商品消费额                      +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	scanf("%d", &i);

	switch (i)
	{
	case 1:printf("\t*重新输入学生学号"); scanf("%d", &p->xuehao); printf("修改成功"); break;
	case 2:printf("\t*重新输入学生姓名"); scanf("%s", p->name); printf("修改成功"); break;
	case 3:printf("\t*重新输入学生年龄"); scanf("%d", &p->age); printf("修改成功"); break;
	case 4:printf("\t*重新输入学生性别"); scanf("%d", p->sex); printf("修改成功"); break;
	case 5:printf("\t*重新输入生活用品购买量:>"); scanf("%d", &p->MerchKind_1); printf("修改成功"); break;
	case 6:printf("\t*重新输入生活用品购买金额:>"); scanf("%d", &p->Money1); printf("修改成功"); break;
	case 7:printf("\t*重新输入学习用品购买量:>"); scanf("%d", &p->MerchKind_2); printf("修改成功"); break;
	case 8:printf("\t*重新输入学习用品购买金额:>"); scanf("%d", &p->Money2); printf("修改成功"); break;
	case 9:printf("\t*重新输入娱乐用品购买量:>"); scanf("%d", &p->MerchKind_3); printf("修改成功"); break;
	case 10:printf("\t*重新输入娱乐用品购买金额:>"); scanf("%d", &p->Money3); printf("修改成功"); break;
	case 11:printf("\t*重新输入总消费金额:>"); scanf("%d", &p->MerMon); break;
	default:printf("\t*您输入的数字有误,请重新输入!\n");
	}

	p = h->next;//将链表输入进文件
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("学生信息已保存至文件 %s\n", filename);
}
//删除信息的函数
void shanchu() {
	FILE* fp;
	S* p, * del;
	int a; //学生的学号


	if ((fp = fopen(filename, "w")) == NULL) {
		printf("无法打开该文件");
		exit(0);
	}
	system("cls");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                   正在使用学生信息删除功能                  +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t                   按学生学号删除学生所有信息                 +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*请输入学生学号:>");
	scanf("%d", &a);
	p = h->next;
	while (p->xuehao != (a - 1)) {
		if (p->next == NULL) { printf("查无此人，请确认学号\n"); break; }
		p = p->next;
	}
	del = p->next;//删除功能实现的主要语句
	p->next = p->next->next;//删除功能实现的主要语句
	free(del);
	printf("该学生信息删除成功\n");

	p = h->next;//将链表输入进文件
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;

	}
	fclose(fp);
	printf("学生信息已保存至文件 %s\n", filename);
}
//插入信息的函数
void charu() {
	FILE* fp;
	S* p, * insert;
	int a; //学生的学号


	if ((fp = fopen(filename, "w")) == NULL) {
		printf("无法打开该文件");
		exit(0);
	}
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t+                                                             +\n");
	printf("\t+                  正在使用学生信息插入功能                   +\n");
	printf("\t+                                                             +\n");
	printf("\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t*输入你需要插入位置的学号:>");
	scanf("%d", &a);
	p = h->next;
	while (p->xuehao != a) {
		if (p->next == NULL) { printf("查无此人，请确认学号\n"); break; }
		p = p->next;
	}

	insert = (S*)malloc(sizeof(S));
	insert->next = p->next;//插入功能实现的主要语句
	p->next = insert;////插入功能实现的主要语句
	printf("\t*请输入学生学号:>");
	scanf("%d", &insert->xuehao);
	printf("\t*请输入学生姓名:>");
	scanf("%s", insert->name);
	printf("\t*请输入学生年龄:>");
	scanf("%d", &insert->age);
	printf("\t*请输入学生性别:>");
	scanf("%s", insert->sex);
	printf("插入学生信息完毕 \n");
	printf("*请输入该学生购买日用商品的数量:>");
	scanf("%d", &insert->MerchKind_1);
	printf("*请输入该学生购买日用商品的消费额:>");
	scanf("%d", &insert->Money1);
	printf("*请输入该学生购买学习商品的数量:>");
	scanf("%d", &insert->MerchKind_2);
	printf("*请输入该学生购买学习商品的消费额:>");
	scanf("%d", &insert->Money2);
	printf("*请输入该学生购买娱乐商品的数量:>");
	scanf("%d", &insert->MerchKind_3);
	printf("*请输入该学生购买娱乐商品的消费额:>");
	scanf("%d", &insert->Money3);
	printf("*请输入学生本月消费总金额:>");
	scanf("%d", &insert->MerMon);
	p = h->next;//将链表输入进文件
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %s %d %d %d %d %d %d %d\n", p->xuehao, p->name, p->age, p->sex, p->MerchKind_1, p->Money1
			, p->MerchKind_2, p->Money2, p->MerchKind_3, p->Money3, p->MerMon);
		p = p->next;
	}
	fclose(fp);
	printf("学生信息已保存至文件 %s\n", filename);
}




//用户登录函数
void UserLog()
{
	system("cls");
	FILE* pf = NULL;
	User test, examine;    /*与注册函数的相同，test用于使用者输入账号等信息，
						  examine用于电脑检测输入是否正确*/
	if ((pf = fopen(filename_use, "rb")) == NULL)
	{
		printf("打开文件失败!\n");
		return;
	}
	printf("\t******************************************************\n");
	printf("\t*                    登录界面                        *\n");
	printf("\t******************************************************\n");
	fread(&examine, sizeof(User), 1, pf);
	printf("\t*请输入你的账号:>");
	scanf("%s", test.account);
	while (1)    //通过while循环检测之前是否注册过该账号
	{
		if (strcmp(test.account, examine.account) == 0)
		{
			break;
		}
		else {
			if (!feof(pf))//读完一个模块的数据后，文件位置标记会移动到下一模块
			{
				fread(&examine, sizeof(User), 1, pf);
			}
			else {
				printf("\t*该账号不存在,请选择注册账号或者重新输入!\n");
				fclose(pf);
				int repeat;
				printf("\t******************************************************\n");
				printf("\t*                    0.退出                          *\n");
				printf("\t*                    1.注册账号                      *\n");
				printf("\t*                    2.重新输入                      *\n");
				printf("\t******************************************************\n");
				do
				{
					printf("\t*输入操作数字:>");
					scanf("%d", &repeat);
					switch (repeat)
					{
					case 0:break;
					case 1:
						UserRegister();    //没有账号,进入注册界面
						return;
					case 2:
						UserLog();      //通过使用函数递归，重新进入登录界面
					default:
						printf("\t输入错误,请您重新输入\n");
					}
				} while (repeat);
			}
		}
	}


	//下面是检测密码输入是否正确
	int lim = 0; //规定允许密码试错的次数
	for (lim = 1; lim < 4; lim++)
	{
		printf("\t*请输入您的密码:>");
		scanf("%s", test.code);
		if (!strcmp(test.code, examine.code))
		{
			system("cls");
			printf("\t|------------------------------------------------------------------------|\n");
			printf("\t|                               登陆成功                                 |\n");
			printf("\t|------------------------------------------------------------------------|\n");
			printf("\t|************************************************************************|\n");
			fclose(pf);
			//若登录成功,会直接进入系统功能使用界面
			int a;
			do {
				menu();
				scanf("%d", &a);
				switch (a)
				{
				case 0:
					printf("退出成功!\n"); break;
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
			printf("\t*                  您输入的密码有误!                 *\n");
			printf("\t*                  还剩下%d次输入机会                 *\n", 3 - lim);
			printf("\t******************************************************\n");
		}
	}
	//如果密码输入正确，会直接进入功能使用界面
	//如果试错机会全部用完，会回退到登录界面
	return;
}
//主函数部分
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
			printf("您输入的数字有误，请重新输入!\n");
			system("pause");
			system("cls");
		}
	} while (remote);
	return 0;
}