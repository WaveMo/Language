#include <stdio.h>

void QuickSort(int s[], int left, int right)
{
	int i, j, key;
	i = left;
	j = right;
	key = s[i];    //��һ������Ϊ��׼ֵ,���ڷ��������,һ��ѡ��һ����,�����������������
	while(i < j)
	{
	    while(i < j && key < s[j])  //�����ҳ��ұ�С�ڻ�׼ֵ������,ÿ��j��һ,ֱ���ҵ�Ϊֹ
	    {
	    	j--;
	    }
	    if(i < j)     //����һ��˵���Ѿ��ҵ��Ȼ�׼ֵС������,�����ͻ�׼ֵ����λ��,i++����һ��Ԫ��
	    {
	    	s[i] = s[j];
	    	i++;
	    }
	    while(i < j && key >= s[i])
	    {
	        i++;
	    }
	    if(i < j)
	    {
	    	s[j] = s[i];
	    	j--;
	    }
	}
	s[i] = key;   //��ʱi=j
	if(left < i)  //���õݹ��˳�������
	{
		QuickSort(s, left, i-1);
	}
	if(i < right)
	{
		QuickSort(s, i+1, right);
	}
}

int main(int argc, char const *argv[])
{
	int i, left, right, s[10];
	printf("������10�����֣�\n");
	for(i=0; i<10; i++)
	{
		scanf("%d", &s[i]);
	}
	printf("���������������ߵ��±�left�����ұߵ��±�right��\n");
	scanf("%d %d", &left, &right);
	QuickSort(s, left, right);
	printf("��������������˳��Ϊ��\n");
	for(i=0; i<10; i++)
	{
		if(i==0)
		{
			printf("%d", s[i]);
		}
		else
		{
			printf("%4d", s[i]);
		}
	}
	printf("\n");
	return 0;
}