
#include "Plane.h"

extern char PlaneBack[BACK_x][BACK_y];

int main(void)
{
	//��ʼ����
	FengMian();
	//�����������
	_getch();

	//��տ���̨
	system("cls");

	//��ӡ����
	PrintBack1();

	while (1)
	{
		//��տ���̨
		/*system("cls");*/
		//Ӣ���ƶ�
		HeroPlay();
		//Ӣ�۶��˾����´�ӡ����
		PrintBack();

		Sleep(100);
	}
	return 0;
}

