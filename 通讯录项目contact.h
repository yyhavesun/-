# my-code
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,//0
	ADD,
	DEL,//1
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
struct PeoInfo  //人的信息
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;//记录当前已经有的元素个数
};

void InitContact(struct Contact* ps);

void AddContact(struct Contact* ps);

void ShowContact(const struct Contact* ps);

void DelContact(struct Contact* ps);

void SearchContact(const struct Contact* ps);

void ModifyContact(struct Contact* ps);

void SortContact(struct Contact* ps);
