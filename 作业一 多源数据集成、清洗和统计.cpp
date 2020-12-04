﻿#include <stdio.h>
#include <malloc.h>  //得到指向大小为Size的内存区域的首字节的指针//
#include <string.h>
#include <math.h>
#include <stdlib.h>  //标准库函数// 
//score%d这样的是否可行？
#define LEN sizeof(struct students) 
int n;
struct students
{
	char ID[7];//id
	char name[30];     //名字
	char city[15];     //城市
	char gender[15];     //性别
	char height[15];     //身高
	char score1[6]; //成绩1
	char score2[6];//成绩2
	char score3[6];//成绩3
	char score4[6];//成绩4
	char score5[6];//成绩5
	char score6[6];//成绩6
	char score7[6];//成绩7
	char score8[6];//成绩8
	char score9[6];//成绩9
	char score10[6];//成绩10
	char constitution[20];//体能
	int normative;//不规范性检测，当数据冲突时，填写得较为规范的可行度较高
	struct students* next;
};




struct students* openexcel(struct students* head)
{
	int idlong;//id补全用
	int checknor;
	int checkheight;
	struct students* p1, * p2, * p3;
	p3 = NULL;
	printf("请输入打开的csv文件名\n");
	char fname[30] = { 0 };
	char c[100];
	int m = 0;//一行数据的第几个ID,Name,City,Gender,Height,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,Constitution
	scanf_s("%s", fname, 30);
	for (int i = 0; i < 30; i++)
	{
		if (fname[i] == 0)
		{
			fname[i] = '.';
			fname[i + 1] = 'c';
			fname[i + 2] = 's';
			fname[i + 3] = 'v';
			fname[i + 4] = '\0';
			break;
		}
	}
	FILE* fp = NULL;
	if (NULL == (fp = fopen(fname, "r+")))
	{
		printf("文件打开失败，请检查!\n");
		return(head);
	}
	else
	{
		printf("csv文件打开成功\n");
		head = NULL;
	}
	p2 = (struct students*)malloc(LEN);
	p1 = (struct students*)malloc(LEN);
	p3 = NULL;
	if (p1 == NULL) {
		printf("内存分配不成功！\n");
	}
	head = p1;
	rewind(fp);
	while (!feof(fp))
	{

		for (int j = 0; j < 100; j++)
		{
			if (m == 16)
			{

				m = 0;
				p3 = p1;//防止最后溢出多一个结构体
				p1->next = p2;
				p1 = p2;
				p2 = (struct students*)malloc(LEN);
			}
			fscanf_s(fp, "%c", &c[j], 1);//逐个获取输入字符（包括空格和换行符）
			if (c[j] == ',' || c[j] == '\n' || c[j] == ' ')
			{
				c[j] = '\0';
				switch (m)
				{

				case 0:
				{
					p1->normative = 0;
					if (!strcmp("ID", c))
					{

					}
					else
					{

						if (j == 1)
						{
							c[5] = c[0];
							c[0] = '2';
							c[1] = '0';
							c[2] = '2';
							c[3] = '0';
							c[4] = '0';
							c[6] = '\0';
						}
						else if (j == 2)
						{
							c[4] = c[0];
							c[5] = c[1];
							c[0] = '2';
							c[1] = '0';
							c[2] = '2';
							c[3] = '0';
							c[6] = '\0';
						}
						else
						{
							c[3] = c[0];
							c[4] = c[1];
							c[5] = c[2];
							c[0] = '2';
							c[1] = '0';
							c[2] = '2';
							c[6] = '\0';
						}
					}
					strcpy(p1->ID, c);
					break;
				}
				case 1:
				{
					strcpy(p1->name, c);
					break;
				}
				case 2:
				{
					strcpy(p1->city, c);
					break;
				}
				case 3:
				{
					if (!strcmp("male", c))
					{
						strcpy(p1->gender, "boy");
						p1->normative += 1;
					}
					else if (!strcmp("female", c))
					{
						strcpy(p1->gender, "girl");
						p1->normative += 1;
					}
					else
					{
						strcpy(p1->gender, c);
					}
					break;
				}
				case 4:
				{
					if (strcmp("\0", c))
					{
						checkheight = atoi(c);
						if (checkheight < 3)
						{
							c[1] = c[2];
							c[2] = c[3];
							c[3] = '\0';
							p1->normative += 1;
						}
					}
					strcpy(p1->height, c);
					break;
				}
				case 5:
				{
					if (!strcmp("\0", c))
					{//没有数据，不规范性+1
						p1->normative += 1;
					}
					strcpy(p1->score1, c);
					break;
				}

				case 6:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score2, c);
					break;
				}

				case 7:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score3, c);
					break;
				}
				case 8:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score4, c);
					break;
				}
				case 9:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score5, c);
					break;
				}
				case 10:
				{if (!strcmp("\0", c))
				{
					p1->normative += 1;
				}
				strcpy(p1->score6, c);
				break;
				}
				case 11:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score7, c);
					break;
				}
				case 12:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score8, c);
					break;
				}
				case 13:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score9, c);
					break;
				}
				case 14:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score10, c);
					break;
				}
				case 15:
				{

					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->constitution, c);
					break;
				}
				}
				m++;
				j = 0;
				break;
			}
		}

	}
	rewind(fp);
	p1 = p3;
	p1->next = NULL;
	return head;
}

struct students* opentxt(struct students* head)
{
	struct students* p1, * p2, * p3;
	int checkheight;
	printf("请输入打开的txt文件名\n");
	char fname[30] = { 0 };
	char c[100];
	int m = 0;//一行数据的第几个ID,Name,City,Gender,Height,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,Constitution
	scanf_s("%s", fname, 30);
	for (int i = 0; i < 30; i++)
	{
		if (fname[i] == 0)
		{
			fname[i] = '.';
			fname[i + 1] = 't';
			fname[i + 2] = 'x';
			fname[i + 3] = 't';
			fname[i + 4] = '\0';
			break;
		}
	}
	FILE* fp = NULL;
	if (NULL == (fp = fopen(fname, "r+")))
	{
		printf("文件打开失败，请检查!\n");
		return(head);
	}
	else
	{
		printf("txt文件打开成功\n");
		head = NULL;
	}
	p3 = NULL;
	p2 = (struct students*)malloc(LEN);
	p1 = (struct students*)malloc(LEN);
	if (p1 == NULL) {
		printf("内存分配不成功！\n");
	}
	head = p1;
	rewind(fp);
	while (!feof(fp))
	{

		for (int j = 0; j < 100; j++)
		{
			if (m == 16)
			{
				m = 0;
				p3 = p1;//防止最后溢出多一个结构体
				p1->next = p2;
				p1 = p2;
				p2 = (struct students*)malloc(LEN);
			}
			fscanf_s(fp, "%c", &c[j], 1);//逐个获取输入字符（包括空格和换行符）
			if (c[j] == ',' || c[j] == '\n')
			{
				c[j] = '\0';
				switch (m)
				{

				case 0:
				{
					p1->normative = 0;
					strcpy(p1->ID, c);
					break;
				}
				case 1:
				{
					strcpy(p1->name, c);
					break;
				}
				case 2:
				{
					strcpy(p1->city, c);
					break;
				}
				case 3:
				{//先不按照TXT的规范来，
					if (!strcmp("male", c))
					{
						strcpy(p1->gender, "boy");

					}
					else if (!strcmp("female", c))
					{
						strcpy(p1->gender, "girl");

					}
					else
					{
						strcpy(p1->gender, c);
						p1->normative += 1;
					}
					break;
				}
				case 4:
				{//先不按照TXT的规范来
					/*if (strcmp("\0", c))
					{
						checkheight = (int)c;
						if (checkheight > 3)
						{
							c[3] = c[3];
							c[2] = c[1];
							c[1] = ',';
							c[ 4] ='\0';
							p1->normative += 1;
						}
					}*/
					if (strcmp("\0", c))
					{

						checkheight = atoi(c);
						if (checkheight < 3)
						{

							c[1] = c[2];
							c[2] = c[3];
							c[3] = '\0';
						}
						else
						{
							p1->normative += 1;
						}

					}
					else
					{
						p1->normative += 1;
					}
					strcpy(p1->height, c);

					break;
				}
				case 5:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score1, c);
					break;
				}

				case 6:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score2, c);
					break;
				}

				case 7:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score3, c);
					break;
				}
				case 8:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score4, c);
					break;
				}
				case 9:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score5, c);
					break;
				}
				case 10:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score6, c);
					break;
				}
				case 11:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score7, c);
					break;
				}
				case 12:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score8, c);
					break;
				}
				case 13:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score9, c);
					break;
				}
				case 14:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->score10, c);
					break;
				}
				case 15:
				{
					if (!strcmp("\0", c))
					{
						p1->normative += 1;
					}
					strcpy(p1->constitution, c);
					break;
				}
				}
				m++;
				j = 0;
				break;
			}
		}

	}
	rewind(fp);
	p1 = p3;
	p1->next = NULL;
	return head;
}
//数据合并
struct students* merge(struct students* head1, struct students* head2)
{
	struct students* head3;
	head3 = head2;
	int id1, id2;
	while (!strcmp("ID", head1->ID))
	{
		head1 = head1->next;

	}
	while (!strcmp("ID", head2->ID))
	{
		head2 = head2->next;

	}

	//以规范度为第一标准，相同时以execl为准
	while (head1 != NULL && head2 != NULL)
	{


		//先解决冲突的，以ID为基准来比对

		id1 = atoi(head1->ID);
		id2 = atoi(head2->ID);

		while (id2 >= id1)
		{
			id1 = atoi(head1->ID);
			id2 = atoi(head2->ID);
			if (id2 == id1)
			{


				//开始比对
				if (head1->normative < head2->normative)
				{//txt内的不规范性小于execl里的,txt覆盖execl

					if (strcmp("\0", head1->name))//相同为0，不同为1
					{

						strcpy(head2->name, head1->name);
					}
					if (strcmp("\0", head1->city))
					{
						strcpy(head2->city, head1->city);
					}
					if (strcmp("\0", head1->gender))
					{
						strcpy(head2->gender, head1->gender);
					}
					if (strcmp("\0", head1->height))
					{

						strcpy(head2->height, head1->height);
					}
					if (strcmp("\0", head1->score1))
					{
						strcpy(head2->score1, head1->score1);
					}
					if (strcmp("\0", head1->score2))
					{
						strcpy(head2->score2, head1->score2);
					}
					if (strcmp("\0", head1->score3))
					{
						strcpy(head2->score3, head1->score3);
					}
					if (strcmp("\0", head1->score4))
					{
						strcpy(head2->score4, head1->score4);
					}
					if (strcmp("\0", head1->score5))
					{
						strcpy(head2->score5, head1->score5);
					}
					if (strcmp("\0", head1->score6))
					{
						strcpy(head2->score6, head1->score6);
					}
					if (strcmp("\0", head1->score7))
					{
						strcpy(head2->score7, head1->score7);
					}
					if (strcmp("\0", head1->score8))
					{
						strcpy(head2->score8, head1->score8);
					}
					if (strcmp("\0", head1->score9))
					{
						strcpy(head2->score9, head1->score9);
					}
					if (strcmp("\0", head1->score10))
					{
						strcpy(head2->score10, head1->score10);
					}
					if (strcmp("\0", head1->constitution))
					{
						strcpy(head2->constitution, head1->constitution);
					}
					head2->normative = head1->normative;
				}

				//补充execl里没有的数据
				if (!strcmp("\0", head2->name))//相同为0，不同为1
				{

					strcpy(head2->name, head1->name);
				}
				if (!strcmp("\0", head2->city))
				{
					strcpy(head2->city, head1->city);
				}
				if (!strcmp("\0", head2->gender))
				{
					strcpy(head2->gender, head1->gender);
				}
				if (!strcmp("\0", head2->height))
				{

					strcpy(head2->height, head1->height);
				}
				if (!strcmp("\0", head2->score1))
				{
					strcpy(head2->score1, head1->score1);
				}
				if (!strcmp("\0", head2->score2))
				{
					strcpy(head2->score2, head1->score2);
				}
				if (!strcmp("\0", head2->score3))
				{
					strcpy(head2->score3, head1->score3);
				}
				if (!strcmp("\0", head2->score4))
				{
					strcpy(head2->score4, head1->score4);
				}
				if (!strcmp("\0", head2->score5))
				{
					strcpy(head2->score5, head1->score5);
				}
				if (!strcmp("\0", head2->score6))
				{
					strcpy(head2->score6, head1->score6);
				}
				if (!strcmp("\0", head2->score7))
				{
					strcpy(head2->score7, head1->score7);
				}
				if (!strcmp("\0", head2->score8))
				{
					strcpy(head2->score8, head1->score8);
				}
				if (!strcmp("\0", head2->score9))
				{
					strcpy(head2->score9, head1->score9);
				}
				if (!strcmp("\0", head2->score10))
				{
					strcpy(head2->score10, head1->score10);
				}
				if (!strcmp("\0", head2->constitution))
				{
					strcpy(head2->constitution, head1->constitution);
				}
			}
			head1 = head1->next;//下一条数据
			if (head1 != NULL && head1->next != NULL)
			{
				id1 = atoi(head1->ID);
			}
		}
		head2 = head2->next;//下一条对比的csv数据
		if (head2 != NULL && head2->next != NULL)
		{
			id2 = atoi(head2->ID);
		}

	}

	return(head3);
}
//数据插入
struct students* charu(struct students* head1, struct students* head2)
{//此操作后txt里的链表数据被转移到execl里，所以最后再读取一遍源文件
	struct students* head3, * p3, * p4, * p5, * p6;
	head3 = head2;
	int id1, id2, id3;
	p6 = head1;
	while (!strcmp("ID", head1->ID))
	{
		head1 = head1->next;

	}
	while (!strcmp("ID", head2->ID))
	{
		head2 = head2->next;

	}
	p3 = head2->next;

	while (head1 != NULL && head2 != NULL && p3 != NULL)
	{
		id1 = atoi(head1->ID);
		id2 = atoi(head2->ID);
		id3 = atoi(p3->ID);
		if (id1 <= id2)
		{
			if (head1->next == NULL)
			{
				break;
			}
			head1 = head1->next;
			p6 = p6->next;
			id1 = atoi(head1->ID);
		}
		else if (id1 >= id3)
		{
			if (p3->next == NULL)
			{
				break;
			}
			head2 = p3;
			p3 = p3->next;
			id2 = atoi(head2->ID);
			id3 = atoi(head2->ID);
		}
		else
		{

			p6->next = head1->next;
			p5 = head1->next;
			p4 = head2->next;
			head2->next = head1;
			head1->next = p4;
			head2 = head1;
			head1 = p5;
			id1 = atoi(head1->ID);
			id2 = atoi(head2->ID);
			id3 = atoi(p3->ID);
		}

	}
	return(head3);
}
struct students* quchong(struct students* head3)
{
	struct students* p1, * p2, * p3;
	int id1, id2;
	p1 = head3;
	p2 = p1->next;
	p3 = p1;
	while (!strcmp("ID", p1->ID))
	{
		p1 = p1->next;

	}
	while (!strcmp("ID", p2->ID))
	{
		p2 = p2->next;

	}while (!strcmp("ID", p3->ID))
	{
		p3 = p3->next;

	}
	p1 = p3->next;
	p2 = p1->next;
	while (p1 != NULL && p2 != NULL)
	{
		id1 = atoi(p1->ID);
		id2 = atoi(p2->ID);

		if (id1 == id2)
		{

			if (p1->normative <= p2->normative)//先的数据比后的数据规范的时候
			{
				p1->next = p2->next;
				p2->next = NULL;
				free(p2);//删除掉无用数据，释放空间
				p2 = p1->next;
				p3 = p3->next;
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				p3->next = p2;
				p1->next = NULL;
				free(p1);
				p1 = p2;
				p2 = p2->next;
			}
		}
		else
		{
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}


	}
	return(head3);
}
int pingjun(struct students* head3)
{

	int scoresum[9] = { 0 };
	int sum = 0;//统计的人数
	double ave = 0;//平均值
	while (!strcmp("ID", head3->ID))
	{
		head3 = head3->next;

	}
	while (head3 != NULL)
	{
		if (strcmp("Beijing", head3->city))
		{

		}
		else
		{
			scoresum[0] += atoi(head3->score1);
			scoresum[1] += atoi(head3->score2);
			scoresum[2] += atoi(head3->score3);
			scoresum[3] += atoi(head3->score4);
			scoresum[4] += atoi(head3->score5);
			scoresum[5] += atoi(head3->score6);
			scoresum[6] += atoi(head3->score7);
			scoresum[7] += atoi(head3->score8);
			scoresum[8] += atoi(head3->score9);
			sum++;
		}
		head3 = head3->next;

	}
	printf("家乡在北京的同学的各个成绩的平均值为\n");
	for (int i = 0; i < 9; i++)
	{
		ave = scoresum[i] / sum;
		printf("成绩%d平均值为%f\n", i + 1, ave);
	}
	return 0;
}
int shuliang(struct students* head3)
{
	int num = 0;
	int c1 = 0;
	int c9 = 0;

	while (!strcmp("ID", head3->ID))
	{
		head3 = head3->next;

	}
	while (head3 != NULL)
	{
		c1 = atoi(head3->score1);
		c9 = atoi(head3->score9);
		if (!strcmp("Guangzhou", head3->city) && c1 > 80 && c9 > 9 && !strcmp("boy", head3->gender))
		{
			num++;
		}
		head3 = head3->next;
	}
	printf("学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量为%d\n", num);
	return 0;

}
int tineng(struct students* head3)
{
	double c1 = 0;//广州女生数量
	double c2 = 0;//上海女生数量
	double s1 = 0;//广州女生体能总分数
	double s2 = 0;//上海女生体能总分数
	//bad/general/good/excellent分别为0,1,3,4分
	while (!strcmp("ID", head3->ID))
	{
		head3 = head3->next;

	}
	while (head3 != NULL)
	{

		if (!strcmp("Guangzhou", head3->city) && !strcmp("girl", head3->gender))
		{//广州的

			if (!strcmp("excellent", head3->constitution))
			{
				s1 += 4;

			}
			else if (!strcmp("good", head3->constitution))
			{
				s1 += 3;

			}
			else if (!strcmp("general", head3->constitution))
			{
				s1 += 1;

			}
			else if (!strcmp("bad", head3->constitution))
			{

			}
			else
			{
				//没有成绩
				c1--;
			}
			c1++;
		}
		else if (!strcmp("Shanghai", head3->city) && !strcmp("girl", head3->gender))
		{//上海的

			if (!strcmp("excellent", head3->constitution))
			{
				s2 += 4;

			}
			else if (!strcmp("good", head3->constitution))
			{
				s2 += 3;

			}
			else if (!strcmp("general", head3->constitution))
			{
				s2 += 1;

			}
			else if (!strcmp("bad", head3->constitution))
			{

			}
			else
			{
				//没有成绩，不算进去
				c2--;
			}
			c2++;
		}

		head3 = head3->next;
	}
	printf("广州的女生体能水平平均分数为%f,上海的女生体能水平平均分数为%f\n", s1 / c1, s2 / c2);
	if ((s1 / c1) > (s2 / c2))
	{
		printf("广州的女生体能水平较高\n");
	}
	else if ((s1 / c1) < (s2 / c2))
	{
		printf("上海的女生体能水平较高\n");
	}
	else
	{
		printf("两者都是同一水平\n");
	}
	{

	}
	return 0;
}
int xiangguan(struct students* head3)
{
	int n = 0;//数组长度
	struct students* p1;
	int j = 0;
	float ave[10] = { 0 };
	float std[10] = { 0 };
	float correl[10] = { 0 };//相关性
	float zanshi = 0;
	int num = 0;//统计的学生数量

	while (!strcmp("ID", head3->ID))
	{
		head3 = head3->next;

	}
	p1 = head3;
	while (head3 != NULL)
	{
		n++;
		head3 = head3->next;
	}

	int* a;
	float* ak;
	int* b[9], * bk[9];
	a = (int*)calloc(n, sizeof(int));
	ak = (float*)calloc(n, sizeof(float));//动态申请内存
	for (int i = 0; i < 9; i++)
	{
		bk[i] = (int*)malloc(n * (sizeof(int)));//动态申请内存同时初始化，每个元素都为零
		b[i] = (int*)malloc(n * (sizeof(int)));//动态申请内存
		memset(b[i], 0, n);
		memset(bk[i], 0, n);
	}
	head3 = p1;

	j = 0;
	while (head3 != NULL)
	{
		if (!strcmp("excellent", head3->constitution))
		{
			a[j] = 4;

		}
		else if (!strcmp("good", head3->constitution))
		{
			a[j] = 3;

		}
		else if (!strcmp("general", head3->constitution))
		{
			a[j] = 1;

		}
		else if (!strcmp("bad", head3->constitution))
		{

		}
		else
		{
			//没有成绩，当0

		}

		b[0][j] = atoi(head3->score1);
		b[1][j] = atoi(head3->score2);
		b[2][j] = atoi(head3->score3);
		b[3][j] = atoi(head3->score4);
		b[4][j] = atoi(head3->score5);
		b[5][j] = atoi(head3->score6);
		b[6][j] = atoi(head3->score7);
		b[7][j] = atoi(head3->score8);
		b[8][j] = atoi(head3->score9);
		num++;
		j++;
		head3 = head3->next;
	}
	for (int i = 0; i < num; i++)
	{
		ave[0] += b[0][i];
		ave[1] += b[1][i];
		ave[2] += b[2][i];
		ave[3] += b[3][i];
		ave[4] += b[4][i];
		ave[5] += b[5][i];
		ave[6] += b[6][i];
		ave[7] += b[7][i];
		ave[8] += b[8][i];
		ave[9] += a[i];

	}

	for (int i = 0; i < 10; i++)
	{
		ave[i] = ave[i] / num;//平均
	}

	//成绩的标准差计算
	for (int k = 0; k < 9; k++)
	{
		for (int i = 0; i < num; i++)
		{
			std[k] += ((b[k][i] - ave[k]) * (b[k][i] - ave[k])) / num;
		}
	}
	//体能的标准差计算
	for (int i = 0; i < num; i++)
	{
		std[9] += ((a[i] - ave[9]) * (a[i] - ave[9])) / num;
	}

	for (int i = 0; i < 10; i++)
	{
		std[i] = sqrt(std[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < num; j++)
		{
			bk[i][j] = (b[i][j] - ave[i]) / std[i];
		}
	}
	for (int j = 0; j < num; j++)
	{
		ak[j] = (a[j] - ave[9]) / std[9];
	}
	//点乘计算相关性
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < num; j++)
		{
			correl[i] += ak[j] * bk[i][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		printf("成绩%d与体能成绩的相关性为：%f\n", i + 1, correl[i]);
	}
	return 0;
}
int tongji(struct students* head3)
{
	char num[10];
	while (1)
	{
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("++请选择操作\n");
		printf("++1 统计学生中家乡在Beijing的所有课程的平均成绩\n");
		printf("++2 学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量\n");
		printf("++3 比较广州和上海两地女生的平均体能测试成绩\n");
		printf("++4 学习成绩和体能测试成绩，两者的相关性\n");
		printf("++9 返回\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		gets_s(num);
		switch (*num)
		{
		case'1':
		{
			pingjun(head3);
			break;
		}
		case'2':
		{
			shuliang(head3);
			break;
		}
		case'3':
		{
			tineng(head3);
			break;
		}
		case'4':
		{
			xiangguan(head3);
			break;
		}
		case'9':
		{
			return 0;
		}
		}
	}
	return 0;
}
void print(struct students* head)
{
	struct students* p;
	int num = 1;
	if (head != NULL)
	{
		p = head;
		while (p != NULL)
		{
			printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", p->ID, p->name, p->city, p->gender, p->height, p->score1, p->score2, p->score3, p->score4, p->score5, p->score6, p->score7, p->score8, p->score9, p->score10, p->constitution);
			p = p->next;
			printf("\n");
		}

	}
	else
		printf("学生信息为空,无法输出!\n");
}

int main()
{
	struct students* head1 = NULL;
	struct students* head2 = NULL;
	struct students* head3 = NULL;//合并后数据
	struct students* s1 = NULL;
	int txt = 5;
	while (1)
	{


		char num[10];
		printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
		printf("*=*                 程序说明                            *=*\n");
		printf("*=*   多源数据集成、清洗和统计，请确保读入了两个文件    *=*\n");
		printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");

		printf("************************\n");
		printf("***     1 打开txt   ****\n");
		printf("***     2 打开exec  ****\n");
		printf("***     3 输出      ****\n");
		printf("***     4 合并      ****\n");
		printf("***     5 统计      ****\n");
		printf("***     6退出       ****\n");
		printf("************************\n");
		printf("请输入您选择的操作:");
		fflush(stdin);
		gets_s(num);
		switch (*num)
		{
		case '1':

		{
			head1 = opentxt(head1);//打开
			txt = 0;
			break;
		}
		case '2':

			head2 = openexcel(head2);
			break;
		case '3':
			printf("txt文件数据\n");
			if (txt == 1)
			{
				printf("注意！因为合并了数据所以txt文件有一部分剪切了\n");
			}
			print(head1);
			printf("csv文件数据\n");
			print(head2);
			break;
		case '4':
			if (head1 == NULL || head2 == NULL)
			{
				printf("没有足够的数据来合并\n");
			}
			else
			{
				txt = 1;
				s1 = head1;
				head3 = merge(head1, head2);//合并
				head1 = s1;
				head3 = charu(head1, head3);//插入
				head3 = quchong(head3);//去重
				printf("数据合并成功，以下是合并后数据\n");
				print(head3);
			}

			break;
		case '5':
			tongji(head3);
			pingjun(head3);
			break;

		case '6':
			return 0;
		}

	}
}