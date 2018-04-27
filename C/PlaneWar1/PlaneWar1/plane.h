#ifndef _PLANE   //#pragma once
#define _PLANE
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


//������С
#define  BACK_X   20
#define  BACK_Y   20

struct _Node
{
	int y;
	int x;
	struct _Node* pNext;
};
typedef int bool;
#define true  1
#define false 0
//����
void FengMian();
//��ӡ
void PrintfBack();
//����Ӣ�۵�λ��
void SetHeroPos();
//����Ӣ���ƶ�
void HeroPlay(); //GetAsyncKeyState
//��ӡ
void PrintfBack1();
//�������λ��
void GotoXY(int x, int y);
//�����ɻ�
void ReducePlane();
//�ɻ�����
void PlaneDown();
//�ӵ�����β���
void InsertDan(int y, int x);
//�ӵ�������
void DanRun();
//��ʾ�ӵ�
void ShowDan();
//�����ӵ�
void DeleteDan();
//�ɻ���ײ
void DeletePlane();
//ɾ������ָ���Ľڵ�
void DeleteNode(struct _Node* p);
//�Ʒ�
void Score();
//�Ʒ�
bool IsHeroDie1();


#endif