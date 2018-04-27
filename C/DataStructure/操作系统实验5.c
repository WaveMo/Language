#include <stdio.h>
#include <stdlib.h>

#define MINSIZE 1    //���ٷָ����С������С
#define REQUEST 1    //��ҵ����ռ�
#define FREE    2    //��ҵ�ͷſռ�

typedef struct memory_info
{
	int address;  //��ʼ��ַ
	int size;     //��С
	int ID;	  //�����У���Ϊ0������ռ�ã���Ϊ��ҵ��ID�����Ը���ID���ͷ��ڴ�ʱ�ҵ��������
	int state;    //�Ƿ����
	struct memory_info *prior;
	struct memory_info *next;
}memoryList;

memoryList *L;    //���з�����
int memory_num = 0;

//��ҵ�������нṹ��
typedef struct job_info
{
	int ID;
	int state;   //0��ʾ���룬1��ʾ�ͷ�
	int size;    //��������ͷŶ����ڴ�
}JOB;

//��ʼ�����з�����Ϊһ��˫������ͷ���ΪL
int InitList()
{
	L = (memoryList *)malloc(sizeof(memoryList)); //LΪͷ��㣬ִ����һ��ʱ��linux���L->stateĬ�ϳ�ʼ��Ϊ0��windows���ᣡ
	memoryList *first = (memoryList *)malloc(sizeof(memoryList));  //firstΪ��һ�����

	L->next = first;
	L->prior = NULL;
	first->next = NULL;
	first->prior = L;
	first->address = 0;
	first->size = memory_num;
	first->ID = 0;
	first->state = 0;
	return 0;
}
//����ַ������ͷ�ҵ�β���ҵ����ʵľͷ���
int alloc_firstfit(JOB *job)
{
	memoryList *p = L->next;
	while(p != NULL)
    	{
		if(p->state == 0&&p->size>job->size)
		{
            if(p->size-job->size <= MINSIZE)
			{
               	p->state = 1;		//ֱ�Ӱ�����������������ҵ
				p->ID = job->ID;		//��¼�������������ĸ���ҵ
           		}
			else		//�ӷ����л���job->size��С�ķ��������޸��й����ݽṹ
			{
                memoryList *t = (memoryList *)malloc(sizeof(memoryList));
				t->address = p->address+job->size;
                t->size = p->size-job->size;
               	t->state = 0;
				t->ID = 0;
				t->prior = p;
                t->next = p->next;
                if(p->next != NULL)
				{
                    p->next->prior = t;
                }
               	p->next = t;
                p->size = job->size;
                p->state = 1;
				p->ID = job->ID;
			}
			break;
        	}
		p = p->next;
    	}
	return 0;
}
//����������ҵ��С��������С�ķ�����
int alloc_bestfit(JOB *job)
{
	int minSize = 640;
	memoryList *p = L->next;
	memoryList *min = NULL;		//minָ����С�ķ���
	while(p != NULL)			//�ҵ��ָܷ���ҵ����С���н��
	{
		if(p->state == 0&&p->size>job->size&&p->size <= minSize)
		{
			minSize = p->size;
			min = p;
		}
		p = p->next;
	}
	if(min->size-job->size <= MINSIZE)
	{
		min->state = 1;		//ֱ�Ӱ�����������������ҵ
		min->ID = job->ID;		//��¼�������������ĸ���ҵ
	}
	else		//�ӷ����л���job->size��С�ķ��������޸��й����ݽṹ
	{
		memoryList *t = (memoryList *)malloc(sizeof(memoryList));
		t->address = min->address+job->size;
		t->size = min->size-job->size;
		t->state = 0;
		t->ID=0;
		t->prior = min;
		t->next = min->next;
		if(min->next != NULL)
		{
			min->next->prior = t;
		}
		min->next = t;
		min->size = job->size;
		min->state = 1;
		min->ID = job->ID;
	}
	return 0;
}
//���鷽��֮һ���������������з�������
int freeNode(JOB *job)
{
	memoryList *p = L->next;
	while(p != NULL)
	{
		if(p->ID == job->ID)//�ҵ�����ڵ�
		{
			//��һ�������ǰһ���ڷ������У���һ������ռ�û�û�к�һ����
			if((p->prior->state == 0&&p->next->state == 1&&p->prior != L)||
				(p->prior->state == 0&&p->next == NULL&&p->prior != L))
			//�����мǣ������õ�p->prior->state��ʼ��Ϊ0����windows����state==0
			{
				p->prior->size = p->prior->size+p->size;
				p->prior->next = p->next;
				if(p->next != NULL)
				{
					p->next->prior = p->prior;
				}
			}
		 	//�ڶ����������һ���ڷ������У�ǰһ������ռ�û���ͷ���
			else if((p->next->state == 0&&p->prior->state == 1)||(p->next->state == 0&&p->prior == L))
			{
				p->ID = 0;
				p->state = 0;
				p->size = p->size+p->next->size;
				if(p->next->next != NULL)
				{
					p->next->next->prior = p;
				}
				p->next = p->next->next;
			}
			//�����������ǰ�����������
			else if(p->prior->state == 0&&p->next->state == 0)
			{
				p->prior->size = p->prior->size+p->next->size+p->size;
				p->prior->next = p->next->next;
				if(p->next->next != NULL)
				{
					p->next->next->prior = p->prior;
				}
			}
			//�����������ǰ�������������
			else
			{
				p->ID = 0;
				p->state = 0;
			}
			break;
		}
	p = p->next;
}
	return 0;
}
int print()
{
	printf("\nִ�к��״̬ͼ����\n\n");
	memoryList *p = L->next;
	printf("---------------------------------------------\n");
	printf("  %-10s%-10s%-20s%-10s\n", "address","size","ID(0Ϊ���У�", "state");
	while(p != NULL)
	{
	    printf("---------------------------------------------\n");
		printf("  %-10d%-10d%-20d%-10d\n", p->address,p->size,p->ID,p->state);
		p = p->next;
	}
	printf("---------------------------------------------\n");
	return 0;
}

int main()
{
	//������Ŀ�������ݣ�����һ����ҵ��������
	JOB job;
	int option;		//ѡ���״���Ӧ�㷨���������Ӧ�㷨
	printf("-------------------------------------------------\n");
	printf("            ��ѡ��̬���������㷨               \n");
	printf("                1.�״���Ӧ�㷨                   \n");
	printf("                2.�����Ӧ�㷨                   \n");
	printf("                0.�˳�����                       \n");
	printf("-------------------------------------------------\n");
	scanf("%d", &option);
	if(option == 1)     //ִ���״���Ӧ�㷨
	{
		printf("\n");
		printf("------------------------------------------------\n");
		printf("         �������״���Ӧ�㷨��ִ�й���:          \n");
		printf("------------------------------------------------\n");
		printf("\n�������ʼ�������ڴ��С:\n");
		scanf("%d", &memory_num);
		printf("\n����Ϊ������ڴ棬���Ժ�...\n");
		InitList();		//��ʼ�����з�����
		print();
		printf("\n����1��ʾ�����ڴ棬����2��ʾ�ͷ��ڴ棬����0�˳�\n");
		while((scanf("%d", &job.state)) && (job.state != 0))
		{

			if(job.state == REQUEST)	//�����ڴ�ռ䣬�����״���Ӧ�㷨
			{
				printf("\n������Ҫ�����ڴ�ռ����ҵID:\n");
				scanf("%d", &job.ID);
				printf("\n���������ҵ���ڴ�ռ�\n");
				scanf("%d", &job.size);
				if(job.size > memory_num)
				{
					printf("\n�Բ�����������ڴ�ռ���ڿ����ڴ�ռ䣡\n");
					printf("\n����ռ�ʧ�ܣ�\n");
				}
				else
				{
					printf("\n����Ϊ��ҵ%d����%dKB�����Ժ�...\n", job.ID,job.size);
					alloc_firstfit(&job);
					print();
				}
			}
			if(job.state == FREE)		//�ͷ��ڴ�ռ䣬�����ڴ�
			{
				printf("\n������Ҫ�ͷ��ڴ�ռ����ҵID:\n");
				scanf("%d", &job.ID);
				printf("\n���������ҵҪ�ͷŵ��ڴ�ռ�\n");
				scanf("%d", &job.size);
				printf("\n����Ϊ��ҵ%d�ͷ�%dKB�����Ժ�...\n", job.ID,job.size);
				freeNode(&job);
				print();
			}
			printf("\n����1��ʾ�����ڴ棬����2��ʾ�ͷ��ڴ棬����0�˳�\n");
		}
	}
	else if(option == 2)      //ִ�������Ӧ�㷨
	{
		printf("\n");
		printf("------------------------------------------------\n");
		printf("         �����������Ӧ�㷨��ִ�й���:          \n");
		printf("------------------------------------------------\n");
		printf("\n�������ʼ�������ڴ��С:\n");
		scanf("%d", &memory_num);
		printf("\n����Ϊ������ڴ棬���Ժ�...\n");
		InitList();		//��ʼ�����з�����
		print();
		printf("\n����1��ʾ�����ڴ棬����2��ʾ�ͷ��ڴ棬����0�˳�\n");
		while((scanf("%d", &job.state)) && (job.state != -1))
		{
			if(job.state == REQUEST)		//�����ڴ�ռ䣬���������Ӧ�㷨
			{
				printf("\n������Ҫ�����ڴ�ռ����ҵID:\n");
				scanf("%d", &job.ID);
				printf("\n���������ҵҪ������ڴ�ռ�\n");
				scanf("%d", &job.size);
				printf("\n����Ϊ��ҵ%d����%dKB�����Ժ�...\n", job.ID,job.size);
				alloc_bestfit(&job);
				print();
			}
			if(job.state == FREE)			//�ͷ��ڴ�ռ䣬�����ڴ�
			{
				printf("\n������Ҫ�ͷ��ڴ�ռ����ҵID:\n");
				scanf("%d", &job.ID);
				printf("\n���������ҵҪ�ͷŵ��ڴ�ռ�\n");
				scanf("%d", &job.size);
				printf("\n����Ϊ��ҵ%d�ͷ�%dKB�����Ժ�...\n", job.ID,job.size);
				freeNode(&job);
				print();
			}
			printf("\n����1��ʾ�����ڴ棬����2��ʾ�ͷ��ڴ棬����0�˳�\n");
		}
	}

	return 0;
}
