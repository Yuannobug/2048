#include"game.h"

void game()
{
	
	int option = 0;
	printf("是否查看游戏规则\n");
	printf("1.是       0.否 \n");
	scanf("%d", &option);
	switch(option)
	{
		case 1:rule(); break;
		default:printf("游戏正式开始！\n"); break;
	}
	my_game();
}


int main()
{
	int option = 0; int judge = 1;
	printf("********************\n");
	printf("    欢迎来到2048    \n");
	printf("********************\n");
	printf("    是否开始游戏    \n");
	printf("********************\n");
	printf("  1.是         0.否 \n");
	printf("********************\n");
	while (judge)
	{
		scanf("%d", &option);
		switch (option)
		{
		case 0:printf("谢谢游玩，欢迎下次体验！\n"); judge = 0; break;
		case 1:game(); printf("是否继续游戏：1. 是  0.否\n"); scanf("%d", &judge); break;
		default:printf("错误的输入方式，请重新输入！\n"); break;
		}
	}
	return 0;
}