#include <stdio.h>

void insort(int s[], int n)
{
	int i;
	for(i=2; i<=n; i++)
	{
		s[0] = s[i];     //�����ڱ�
		while(s[0] < s[i-1] && i > 0)
		{
			s[i] = s[i-1];    //���С���򽻻�λ��
			i--;
		}
		s[i] = s[0];
	}
}
int main(int argc, char const *argv[])
{
	int s[11], i;
	printf("������10�����֣�\n");
	for(i=1; i<11; i++)
	{
		scanf("%d", &s[i]);
	}
	insort(s, 10);
	printf("����������˳��Ϊ��\n");
	for(i=1; i<11; i++)
	{
		if(i==1)
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