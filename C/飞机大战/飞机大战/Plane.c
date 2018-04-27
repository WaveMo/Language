#include "Plane.h"

char PlaneBack[BACK_x][BACK_y] = {  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
									1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
                                 };

//�����Ա���
char strBackTemp[BACK_x][BACK_y * 2 + 2];

int hero_X = 17;
int hero_Y = 10;
//��ʼ����
void FengMian()
{
	printf("\n\n\n\t\t\t\t\t\t ����ӭ�����ɻ���ս��\n");
	printf("\n\t\t\t\t\t         ������Ϸ�ɳ���ŵ����������\n");
	printf("\n\t\t\t\t\t��W A S D, ���Ʒ��з���, �ո�����ڡ�\n");
	printf("\n\t\t\t\t\t          ���������������\n");
}

//��ӡ����
void PrintBack1()
{
	int i, j;

	//�����Ա���
	char strBackTemp[BACK_x][BACK_y * 2 + 2] = { 0 };

	//����Ӣ��λ��
	SetHeroPos();
	//װ����
	for (i = 0; i < BACK_x; i++)
	{
		for (j = 0; j < BACK_y; j++)
		{
			switch (PlaneBack[i][j])
			{
			case 0:
				strcat(strBackTemp[i], "  ");
				break;
			case 1:
				strcat(strBackTemp[i], "��");
				break;
			case 2:
				strcat(strBackTemp[i], "ʿ");
				break;
			case 3:
				break;
			}
		}
		strcat(strBackTemp[i], "\n");
	}

    //��ӡ����
	for (i = 0; i < BACK_x; i++)
	{
		printf(strBackTemp[i]);
	}
}

//�������λ��
void Gotoxy(int x, int y)
{
	COORD rd;
	rd.Y = x;
	rd.X = y * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
}
void PrintBack()
{
	int i, j;
	//����Ӣ��λ��
	SetHeroPos();

	//װ����
	for (i = 1; i < BACK_x - 1; i++)
	{
		for (j = 1; j < BACK_y - 1; j++)
		{
			Gotoxy(i, j);
			switch (PlaneBack[i][j])
			{
			case 0:
				/*printf("  ");*/
				break;
			case 1:
				/*printf("��");*/
				break;
			case 2:
				printf("ʿ");
				break;
			case 3:
				break;
			}
		}
	}

}
//����Ӣ�۵�λ��
void SetHeroPos()
{
	PlaneBack[hero_X][hero_Y] = 2;
}

//����Ӣ���ƶ�
void HeroPlay()
{
	Gotoxy(hero_X, hero_Y);
	if (GetAsyncKeyState('W') && hero_X > 1)
	{
		PlaneBack[hero_X][hero_Y] = 0;
		printf("  ");
		hero_X--;
		
	}
	else if (GetAsyncKeyState('S') && hero_X < BACK_x - 2)
	{
		PlaneBack[hero_X][hero_Y] = 0;
		printf("  ");
		hero_X++;
		
	}
	if (GetAsyncKeyState('A') && hero_Y > 1)
	{
		PlaneBack[hero_X][hero_Y] = 0;
		printf("  ");
		hero_Y--;
		
	}
	
	else if (GetAsyncKeyState('D') && hero_Y < BACK_y - 2)
	{
		PlaneBack[hero_X][hero_Y] = 0;
		printf("  ");
		hero_Y++;
		
	}
	if (GetAsyncKeyState( VK_SPACE ))
	{
		//printf("0");
	}
}