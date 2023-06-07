# my-code
#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("通讯录已满，无法增加\n");
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");

	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空\n");
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//void DelContact(const struct Contact* ps)
//{
//	char name[MAX_NAME];
//	printf("请输入要删除人的名字:>");
//	scanf("%s", name);
//
//}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int i = 0;
	int pos=FindByName(ps, name);//找到返回下标，找不到返回-1
	if(pos == -1)
		printf("要查找的人不存在\n");
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
		printf("此人不存在\n");
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");

	}
}


int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_by_name);
}
