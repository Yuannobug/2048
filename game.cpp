#include"game.h"
void rule()//��Ϸ����
{
	printf("��Ϸ����\n");
	printf("����������������ĸ������ƶ�\n");
	printf("����ͬ��������ʱ���Ժϳ�Ϊ��������֮��\n");
	printf("����ϳɳ���2048ʱ,��Ϸ�ɹ���\n");
	printf("����������ʱ����Ϸʧ�ܣ�\n");
	printf("\n");
	printf("�ƶ���˵����\n");
	printf("A.���� D.���� S.���� W.����\n ");
	printf("ע��ASDW��Ϊ��д\n\n");
}

int random()//���������
{
	int i = 0;
	i = rand() % 2;
	if (i == 0)
		return 2;
	else
		return 4;
}

int my_check(int board[4][4])//�����Ϸ�Ƿ����
{
	int i = 0; int j = 0; int judge = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 2048)
			{
				printf("��ϲ�㣬��Ϸʤ����\n");
				return 1;
			}
			else if (board[i][j] == 0)
				judge++;
			else
				continue;
		}
	}
	if (judge == 0)
	{
		printf("��Ϸʧ��!\n");
		return 0;
	}
	else
		return -1;
}

void showboard(int board[4][4])//��ӡ����
{
	int i = 0; int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
				printf("    ");
			else
				printf("%-4d", board[i][j]);
			printf("|");
		}
		printf("\n");
		printf("--------------------\n");
	}
}

void moveleft(int board[4][4])
{
	int i = 0; int j = 0; int k = 0; int m = 0;
	for (i = 0; i < 4; i++)
	{
		m = 0;
		for(j=0;j<3;j++)//�����еĿո��Ƶ����ұ�
		{
			if (board[i][j] == 0)
			{
				for (k = j; k < 3; k++)
				{
					board[i][k] = board[i][k+ 1];
					board[i][k + 1] = 0;
				}
				j--;
			}
			m++;
			if (m == 4)
				break;
		}
		for (j = 0; j < 2; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{
				board[i][j] = 2 * board[i][j];
				for (k = j+1; k < 3; k++)
				{
					board[i][k] = board[i][k + 1];
					board[i][k + 1] = 0;
				}
			}
		}
		if (board[i][2] == board[i][3])
		{
			board[i][2] = 2 * board[i][2];
			board[i][3] = 0;
		}
	}
}

void moveright(int board[4][4])
{
	int i = 0; int j = 0; int k = 0; int m = 0;
	for (i = 3; i >=0; i--)
	{
		m = 0;
		for (j = 3; j >0; j--)//�����еĿո��Ƶ������
		{
			if (board[i][j] == 0)
			{
				for (k = j; k >0; k--)
				{
					board[i][k] = board[i][k-1];
					board[i][k -1] = 0;
				}
				j++;
			}
			m++;
			if (m == 4)
				break;
		}
		for (j = 3; j > 1; j--)
		{
			if (board[i][j] == board[i][j - 1])
			{
				board[i][j] = 2 * board[i][j];
				for (k = j -1; k >0; k--)
				{
					board[i][k] = board[i][k - 1];
					board[i][k - 1] = 0;
				}
			}
		}
		if (board[i][1] == board[i][0])
		{
			board[i][1] = 2 * board[i][0];
			board[i][0] = 0;
		}

	}
}

void moveup(int board[4][4])
{
	int i = 0; int j = 0; int m = 0; int k = 0;
	for (j = 0; j < 4; j++)
	{
		m = 0;
		for (i = 0; i < 3; i++)//�����еĿո��Ƶ����±�
		{
			if (board[i][j] == 0)
			{
				for (k = i; k < 3; k++)
				{
					board[k][j] = board[k+1][j];
					board[k+1][j] = 0;
				}
				i--;
			}
			m++;
			if (m == 4)
				break;
		}
		for (i = 0; i < 2; i++)
		{
			if (board[i][j] == board[i+1][j ])
			{
				board[i][j] = 2 * board[i][j];
				for (k = i+1; k < 3; k++)
				{
					board[k][j] = board[k+1][j];
					board[k+1][j] = 0;
				}
			}
		}
		if (board[2][j] == board[3][j])
		{
			board[2][j] = 2 * board[3][j];
			board[3][j] = 0;
		}

	}
}

void moveoff(int board[4][4])
{
	int i = 0; int j = 0; int m = 0; int k = 0;
	for (j = 3; j >= 0; j--)
	{
		m = 0;
		for (i = 3; i >0; i--)//�����еĿո��Ƶ����ϱ�
		{
			if (board[i][j] == 0)
			{
				for (k = i; k > 0; k--)
				{
					board[k][j] = board[k - 1][j];
					board[k - 1][j] = 0;
				}
				i++;
			}
			m++;
			if (m == 4)
				break;
		}
		for (i = 3; i >1; i--)
		{
			if (board[i][j] == board[i - 1][j])
			{
				board[i][j] = 2 * board[i][j];
				for (k = i - 1; k >0; k--)
				{
					board[k][j] = board[k - 1][j];
					board[k - 1][j] = 0;
				}
			}
		}
		if (board[1][j] == board[0][j])
		{
			board[1][j] = 2 * board[1][j];
			board[0][j] = 0;
		}

	}
}

void produce(int board[4][4])//ÿ���ƶ������ɵ������
{
	int i = 0; int j = 0;
	while (1)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] != 0)
			continue;
		else
		{
			board[i][j]=random();
			break;
		}
	}
}

void my_game()
{
	srand((unsigned int)time(NULL));
	int board[4][4] = { 0 };
	int i = 0; int j = 0; int k = 0;
	char choice = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}
	for (k = 0; k < 2; k++)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] != 0)
		{
			k--;
			continue;
		}
		else
			board[i][j] = random();
	}
	showboard(board);
	getchar();
	while(1)
	{
		printf("��ѡ������Ҫ�ƶ��ķ���:\n");
		scanf("%c", &choice);
		switch (choice)
		{
		case 'A':moveleft(board);  break;
		case 'D':moveright(board); break;
		case 'W':moveup(board); break;
		case 'S':moveoff(board); break;
		default:printf("��ҪϺ�����\n"); continue; 
		}
		if (my_check(board) != 0 && my_check(board) != 1)
		{
			produce(board);
			showboard(board);
		}
		else
		{
			showboard(board);
			break;
		}
	}
    
}