
#include "plane.h"

int main(void)
{
	unsigned int nCount = 0;
	//����ʾ���
	CONSOLE_CURSOR_INFO cur_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);

	//����
	FengMian();

	//���ո������
	_getch();

	//��տ���̨
	system("cls");

	//��ʾ����
	PrintfBack1();

	while (1)
	{
		//�ӵ�������
		DanRun();
		//��տ���̨
		//system("cls");
		if (0 == nCount % 10)
		{
			//�ɻ�����
			PlaneDown();
		}

		
		//Ӣ���˶�
		HeroPlay();

		//��ʾ����
		PrintfBack();
		//Ӣ�������ж�
		if (false == IsHeroDie1())
		{
			break;
		}
		nCount++;
		Sleep(50);
	}
	GotoXY(21, 0);
	printf ("�ɻ�ը��\n");
	system("pause");
	return 0;
}

