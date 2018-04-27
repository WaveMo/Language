#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 200
#define OK 1
typedef int KeyType;
typedef int status;

typedef struct
{
	KeyType r[MAXSIZE + 1];  //r[0]���û������ڱ���Ԫ
	int length;  //˳�����
}SqList;  //˳�������

status CreatList( SqList *L )
{
	L->r[0] = 0;
	printf( "������������鳤�ȣ�\n" );
	scanf( "%d", &L->length );
	printf( "�������������Ԫ�أ�\n" );
	for ( int i = 1; i <= L->length; i++ )
	{
		getchar();
		scanf("%d", &L->r[i]);
	}
	// printf( "��ȷ���������Ԫ��:\n" );
	// for ( int j = 1; j <= L->length; j++ )
	// {
	// 	printf( "%c", L->r[j] );
	// 	printf( " " );
	// }
	return OK;
}

void BInsertSort( SqList L )  //��˳���L���۰��������
{
	int low, high, mid;
	for ( int i = 2; i <= L.length; ++i )
	{
		L.r[0] = L.r[i];  //��L.r[i]�ݴ浽L.r[0]
		low = 1;
		high = i - 1;
		while ( low <= high )  //����[low..high]���۰������������λ��
		{
			mid = (low + high) / 2;  //�۰�
			if ( L.r[0] < L.r[mid] )
				high = mid - 1;  //������ڵͰ���
			else
				low = mid + 1;  //������ڸ߰���
		}
		for ( int j = i - 1; j >= high + 1; --j )
			L.r[j + 1] = L.r[j];  //��¼����
		L.r[high + 1] = L.r[0];  //����
	}
	printf( "\n�����۰��������������Ϊ��\n" );
	for ( int j = 1; j <= L.length; j++ )
	{
		printf( "%d", L.r[j] );
		printf( " " );
	}
}

int main()
{
	SqList L;
	CreatList(&L);
	BInsertSort(L);
	return 0;
}
