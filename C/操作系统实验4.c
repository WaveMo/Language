#include <stdio.h>

typedef struct PCB
{
    int id;
    int priority;
    int cputime;
    int alltime;
    char *state;
}PCB;

PCB p[5] = {
                {  0,  9,  0,  3,  "READY"},
                {  1, 38,  0,  3,  "READY"},
                {  2, 30,  0,  6,  "READY"},
                {  3, 29,  0,  3,  "READY"},
                {  4,  0,  0,  4,  "READY"}
           };  //����5�����̵�PCB

int i;
int runtime = 0;  //��ʾcpu���е�ʱ��
int ready_count;  //��ʾͳ�ƾ��������еĽ�����
int ready_queue[5] = { -1, -1, -1, -1, -1};  //���ڴ洢�����ľ������е�ID��

//���ڲ������������Ľ���ID
int maxPriority()
{
    int tag;
    int max;
    for (i = 0; i < 5; i++ )
    {
        if ("END" != p[i].state)
        {
            max = p[i].priority;
            tag = i;
            break;
        }

    }
    for (i = 0; i < 5; i++)
    {
        if (("END" != p[i].state) && (max < p[i].priority))
        {
            max = p[i].priority;
            tag = i;
        }
    }
    return p[tag].id;
}

//���ڿ�������
int partition(int left, int right)
{
    int pivotKey = p[ready_queue[left]].priority;
    int pivotId = ready_queue[left];

    while (left < right)
    {
        while (left < right && p[ready_queue[right]].priority <= pivotKey)
        {
            right--;
        }
        ready_queue[left] = ready_queue[right];
        while (left < right && p[ready_queue[left]].priority >= pivotKey)
        {
            left++;
        }
        ready_queue[right] = ready_queue[left];
    }
    ready_queue[left] = pivotId;
    return left;
}

//���������㷨
int quick_sort(int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int pivotPos = partition(left, right);
    quick_sort(left, pivotPos - 1);
    quick_sort(pivotPos + 1, right);
 }

 //�����������
int get_ready_queue()
{
    ready_count = 0;
    for (i = 0; i < 5; i++)
    {
        if ("READY" == p[i].state)
        {
            ready_queue[ready_count] = p[i].id;
            ready_count++;
        }
    }
    quick_sort(0, ready_count - 1); //ʹ�ÿ������򷨶Ծ������н�������
    return 0;
 }

 //��ӡ������̵�PCB
int printPCB()
{
    get_ready_queue();
    printf("RUNTIME: %d\n", runtime);
    printf("RUNNING PROGRAM:");
    for (i = 0; i < 5; i++)
    {
        if ("RUNNING" == p[i].state)
        {
            printf("ID%d\n", p[i].id);
            break;
        }
    }
    if (5 == i)   //û���������еĽ���
    {
        printf("\n");
    }
    printf("READY_QUEUE:");
    for (i = 0; i < ready_count; i++)
    {
        printf("->ID%d", ready_queue[i]);
    }
    printf("\n");
    for (i = 0; i < 60; i++)
        printf("=");
    printf("\n");
    printf("ID          %-10d%-10d%-10d%-10d%-10d\n",
        p[0].id, p[1].id, p[2].id, p[3].id, p[4].id);

    printf("PRIORITY    %-10d%-10d%-10d%-10d%-10d\n",
        p[0].priority, p[1].priority, p[2].priority, p[3].priority,p[4].priority);

    printf("CPUTIME     %-10d%-10d%-10d%-10d%-10d\n",
        p[0].cputime, p[1].cputime, p[2].cputime, p[3].cputime, p[4].cputime);

    printf("ALLTIME     %-10d%-10d%-10d%-10d%-10d\n",
        p[0].alltime, p[1].alltime, p[2].alltime, p[3].alltime, p[4].alltime);

    printf("STATE       %-10s%-10s%-10s%-10s%-10s\n",
        p[0].state, p[1].state, p[2].state, p[3].state, p[4].state);

    return 0;
}

//ģ����̵����й��̣���ʱ��Ƭִ��һ�������еĲ���
void run()
{
    for (i = 0; i < 5; i++)
    {
        //�ý��������н���
        if ("END" == p[i].state)
            {
                continue;
            }
        //�ý�����������
        if ("RUNNING" == p[i].state)
        {
            p[i].cputime++;
            p[i].alltime--;
            if (0 != p[i].alltime)
            {
                p[i].priority -= 3;
                p[i].state = "READY";
            }
            else
            {
                p[i].priority = -1;
                p[i].state = "END";
            }
        }
    //�ý��̴��ھ���״̬
    else
        {
            p[i].priority++;
        }
    }
 }

int main()
{
    int end_count = 0;     //����ͳ�������н����Ľ�����
    int max;      //����ͳ�����������Ľ���id

    for (i = 0; i < 5; i++)
    {
        if (0 == p[i].alltime)
        end_count++;
    }

    printf("���̳�ʼ״̬����:\n");
    printPCB();
    printf("�밴�س���ִ����һ��ʱ��Ƭ");
    getchar();
    printf("\n");

    while (1)
    {
        if (5 == end_count)    //������̶������н���
        {
            break;
        }
        runtime++;   //CPUʱ��Ƭ��1
        max = maxPriority();  //�������ȼ����Ľ��̵�ID
        p[max].state = "RUNNING";
        printPCB();
        run();
        if ("END" == p[max].state)
        {
            end_count++;
        }
        printf("�밴�س���ִ����һ��ʱ��Ƭ");
        getchar();
        printf("\n");
    }
    runtime++;
    printPCB();
    printf("���н�����ִ�����\n");
    return 0;
}
