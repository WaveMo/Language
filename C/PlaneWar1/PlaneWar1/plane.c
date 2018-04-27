#include "plane.h"
char g_PlaneBack[BACK_Y][BACK_X] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
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

char g_PlaneBackTemp[BACK_Y][BACK_X] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
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



int g_heroX = 10;
int g_heroY = 17;

struct _Node *g_pHead = NULL;
struct _Node *g_pEnd = NULL;

int g_score = 0;

//��ʾ�ӵ�
//void ShowDan()
//{
//	struct _Node* pTemp = g_pHead;
//
//	while (pTemp)
//	{
//		//GotoXY(pTemp->y, pTemp->x);
//		//printf("��");
//		
//
//		pTemp = pTemp->pNext;
//	}
//	
//}
//�Ʒ�
void Score()
{
	GotoXY(10, 25);
	printf ("�÷֣�%d",g_score*10);
}

//�����ӵ�
void DeleteDan()
{
	struct _Node* pTemp = g_pHead;

	g_pHead = g_pHead->pNext;
	free(pTemp);
}
//�ɻ���ײ
void DeletePlane()
{
	struct _Node* pTemp = g_pHead;

	while (pTemp)
	{
		//�ж���ɻ���λ��
		if (3 == g_PlaneBackTemp[pTemp->y][pTemp->x])
		{
			struct _Node* pTemptp = pTemp;

			g_PlaneBack[pTemp->y][pTemp->x] = 0;
			
			pTemp = pTemp->pNext;
			g_score++;
			Score();
			//ɾ����ǰ�ڵ� pTemptp  
			DeleteNode(pTemptp);
			//������һ��ѭ��
			continue;
		}

		pTemp = pTemp->pNext;
	}
}
//ɾ������ָ���Ľڵ�
void DeleteNode(struct _Node* p)
{
	//������
	if (NULL == p)
	{
		return ;
	}
	//�������
	if (NULL == g_pHead)
	{
		return ;
	}

	//ɾ���ڵ�  ֻ��һ���ڵ�
	if (g_pHead == g_pEnd)
	{
		if (p == g_pHead)
		{
			free(g_pHead);
			g_pHead = NULL;
			g_pEnd = NULL;
		}
	} //�������ڵ�
	else if (g_pHead->pNext == g_pEnd)
	{
		//ͷ����β��
		if (p == g_pHead)
		{
			free(g_pHead);
			g_pHead = g_pEnd;
			g_pHead->pNext = NULL;
		}
		if (p == g_pEnd)
		{
			free(g_pEnd);
			g_pEnd = g_pHead;
			g_pHead->pNext = NULL;
		}	
	} //����ڵ� >2
	else
	{
		//ɾ����ͷ
		if (p == g_pHead)
		{
			struct _Node* pTemp = g_pHead;
			g_pHead = g_pHead->pNext;
			free(pTemp);
		}
		else if (p == g_pEnd)
		{
			struct _Node* pTemp = g_pHead;
			while (pTemp)
			{
				if (pTemp->pNext == p)
				{
					g_pEnd = pTemp;
					pTemp->pNext = p->pNext;
					free(p);
				}

				pTemp = pTemp->pNext;
			}
		}
		else
		{
			//�ҵ�ɾ���ڵ��ǰһ��
			struct _Node* pTemp = g_pHead;
			while (pTemp)
			{
				if (pTemp->pNext == p)
				{
					pTemp->pNext = p->pNext;//  183 7879 447
					free(p);
				}

				pTemp = pTemp->pNext;
			}
		}
	}
}

//�ӵ�������
void DanRun()
{
	struct _Node* pTemp = g_pHead;

	//������
	if (NULL == g_pHead)
		return ;

	//�߽���ײ
	if (1 == g_pHead->y)
	{
		g_PlaneBack[g_pHead->y][g_pHead->x] = 0;
		DeleteDan();
	}
	

	//���������ӵ��ƶ�
	pTemp = g_pHead;
	while (pTemp)
	{
		//ԭλ���ӵ����
		g_PlaneBack[pTemp->y][pTemp->x] = 0;
	
		pTemp->y-- ;
		//���߽�ͱ���ˣ� �ټ�Խ����
		if (pTemp->y < 1)
			pTemp->y = 1;

		//��λ���ӵ�
		g_PlaneBack[pTemp->y][pTemp->x] = 4;

		pTemp = pTemp->pNext;
	}
	
	//�ɻ���ײ����
	DeletePlane();
}

//�ӵ�����β���
void InsertDan(int y, int x)
{
	//�����ڵ�
	struct _Node *pTemp = (struct _Node*)malloc(sizeof(struct _Node));

	//�ڵ��Ա��ʼ��
	pTemp->y = y;
	pTemp->x = x;
	pTemp->pNext = NULL;

	//����
	if (NULL == g_pHead)
	{
		g_pHead = pTemp;
		//g_pEnd = pTemp;
	}
	else
	{
		g_pEnd->pNext = pTemp;	
	}
	g_pEnd = pTemp;
}
//
//�ɻ�����
void PlaneDown()
{
	int i, j;
	
	for (i = BACK_Y-2; i > 1; i--)
	{
		for (j = 1; j < BACK_X-1; j++)
		{
			//�����ӵ��� Ӣ�۷ɻ����Ͳ���������
			if (2 == g_PlaneBack[i-1][j] || 4 == g_PlaneBack[i-1][j] ) //�ɻ��ӵ����ܿ�
				continue;

			g_PlaneBack[i][j] = g_PlaneBack[i-1][j];
		}
	}

	//�����µĵ��˷ɻ�
	ReducePlane();
}

//�����ɻ�
void ReducePlane()
{
	int i = 0;
	//����
	srand((unsigned int)clock());

	//��һ�����
	for (i = 0; i < BACK_X -1; i++)
	{
		g_PlaneBack[1][i] = 0;
	}

	//���λ�ò����ɻ�
	for (i = 0; i < BACK_X-1; i++)
	{
		int j = rand()%10; 
		
		if (0 == j)
		{
			g_PlaneBack[1][i] = 3;//��ֵ�ɻ�
		}
	}
}

//����
void FengMian()
{
	printf ("\n\n\n\t\t\t        ����ӭ�����ɻ����硷\n");
	printf ("\n\t\t\t      ����������Ī����LNN���С�\n");
	printf ("\n\t\t\t�� W A S D,���Ʒɻ�����, �ո�����ڡ�\n");
	printf ("\n\t\t\t        �� ������������� ��\n");
}

//��ӡ
void PrintfBack1()
{
	int i,
		j;
	//�����Ա���
	char strBackTemp[BACK_Y][BACK_X*2 + 2] = {0};
	char strBackTemp2[BACK_Y*(BACK_X*2 + 2)] = {0};
	//����Ӣ�۵�λ��
	SetHeroPos();

	//װ����
	for (i = 0; i < BACK_Y; i++)
	{
		for (j = 0; j < BACK_X; j++ )
		{
			switch(g_PlaneBack[i][j])
			{
			case 0:
				strcat(strBackTemp[i], "  "); //
				break;
			case 1:
				strcat(strBackTemp[i], "��");
				break;
			case 2:
				strcat(strBackTemp[i], "ʿ");
				break;
			case 3: //���˷ɻ�
				break;
			}
		}
		strcat(strBackTemp[i], "\n");
	}

	//��ӡ����
	for (i = 0; i < BACK_Y; i++)
	{
		//printf (strBackTemp[i]);
		strcat(strBackTemp2, strBackTemp[i]);
	}
	//��ӡһ��
	printf (strBackTemp2);
}

//��������ڿ���̨��λ��
void GotoXY(int y, int x)
{
	COORD rd;
	rd.Y = y;
	rd.X = x*2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
}

void PrintfBack()
{
	int i,
		j;
	
	//����Ӣ�۵�λ��
	SetHeroPos();

	//װ����
	for (i = 1; i < BACK_Y-1; i++)
	{
		for (j = 1; j < BACK_X-1; j++ )
		{
			GotoXY(i, j);

			switch(g_PlaneBack[i][j])
			{
			case 0:
				printf ("  ");  //����̨���
				break;
			case 1:
				//printf ("��");
				break;
			case 2:
				printf ("ʿ");
				break;
			case 3://���˷ɻ�
				printf ("ŵ");
				break;
			case 4:
				printf ("��");
				break;
			}
		}
	}
}

//����Ӣ�۵�λ��
void SetHeroPos()
{
	g_PlaneBack[g_heroY][g_heroX] = 2;
}

//����Ӣ���ƶ�
void HeroPlay() //GetAsyncKeyState
{
	//��¼����
	memcpy(g_PlaneBackTemp[0], g_PlaneBack[0], BACK_X*BACK_Y);

	if (g_heroY > 1 && GetAsyncKeyState('W'))
	{
		//�ߵ�Ӣ�۵�λ��
		GotoXY(g_heroY, g_heroX);
		//Ӣ�۾ɵ�λ�����
		g_PlaneBack[g_heroY][g_heroX] = 0;
		//�ո��滻�� ʿ
		printf("  ");

		g_heroY--;
	}
	if (g_heroY < BACK_Y - 2 && GetAsyncKeyState('S'))
	{
		//ͬ��
		GotoXY(g_heroY, g_heroX);
		g_PlaneBack[g_heroY][g_heroX] = 0;
		printf("  ");

		g_heroY++;
	}

	if ( g_heroX > 1 && GetAsyncKeyState('A') )
	{
		//ͬ��
		GotoXY(g_heroY, g_heroX);
		g_PlaneBack[g_heroY][g_heroX] = 0;
		printf("  ");
		
		g_heroX--;
	}
	if (g_heroX < BACK_X - 2 && GetAsyncKeyState('D'))
	{
		//ͬ��
		GotoXY(g_heroY, g_heroX);
		g_PlaneBack[g_heroY][g_heroX] = 0;
		printf("  ");
		
		g_heroX++;
	}
	if (GetAsyncKeyState(VK_SPACE)&1)
	{
		//�����ӵ�
		InsertDan(g_heroY, g_heroX);
	}

	//�ж�Ӣ������
}

BOOL IsHeroDie1()
{
	if (3 == g_PlaneBackTemp[g_heroY][g_heroX])
	{
		//ײ��
		return false;
	}

	return true;
}