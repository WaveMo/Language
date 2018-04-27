#include <stdio.h>

void shellsort(int s[], int n)  //ϣ��������
{
	int i, gap, temp;
	for(gap=n/2; gap>0; gap/=2)
	{
		for(i=gap; i<n; i++)
		{
			temp = s[i];     //�����ڱ�
			while(temp < s[i-gap] && i-gap >= 0)  //�����s[0]��Ϊ�ڱ�����ôi-gap>=0����ʡ��
			{
				s[i] = s[i-gap];
				i -= gap;
			}
			s[i] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int i, s[10];
	printf("������10�����֣�\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &s[i]);
	}
	printf("ϣ������������Ϊ��\n");
	shellsort(s, 10);
	for (i = 0; i < 10; i++)
	{
		if(i == 0)
		{
			printf("%d", s[i]);
		}
		else
		{
			printf("%4d", s[i]);
		}
	}
	return 0;
}