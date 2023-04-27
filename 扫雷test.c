# my-code
#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*******************************************\n");
	printf("*************1.play     0.exit*************\n");
	printf("*******************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine,'0');
	InitBoard(show,'*');
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("重选\n");
			break;
		}
	} while (input);
 }

int main()
{
	test();
	return 0;
}
