#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;  //Status�Ǻ��������ͣ���ֵ�Ǻ��������״̬���룬��OK��
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;  //����LinkList
Status SetList(LinkList *L)
{
    LinkList cur, pre, head, p;
    int n;
    printf("����������ĳ���:\n");
    scanf("%d", &n);
    cur = *L = (struct Node *)malloc(sizeof(Node));  //����һ���µĿռ��ͷ���
    printf("�������������ݣ�\n");
    cur = *L;  //preΪָ��β���Ľ��
    scanf("%d", &cur->data);
    head = cur;
    for (int i = 1; i < n; i++)
    {
        pre = cur;  //�������ɵĽ����Ϊ��һ������ǰһ�����
        cur = (Node *)malloc(sizeof(Node));  //�����½��
        scanf("%d", &cur->data);
        pre->next = cur;  //�������ɵĽ�㸳ֵ��ǰһ������next
    }
    cur->next = NULL;
    printf("���ڵ������������ģ�\n");
    for(cur = head; cur; pre = cur,cur = cur->next)
        printf ("%d ", cur->data);
    printf("\n");
    return OK;
}
Status GetElem(LinkList L)  //���Ԫ�ز���
{
    int i, j;
    ElemType e;
    LinkList p;
    printf("��������Ҫ���Ԫ�ص��±꣺\n");
    scanf("%d", &i);
    p = L->next;  //��pָ������L�ĵ�һ�����
    j = 1;  //jΪ��ʱ��
    while(p && j < i)  //p��Ϊ�ն��Ҽ�ʱ��j��û�е���iʱ��ѭ������
    {
        p = p->next;  //��pָ����һ�����
        j++;
    }
    if(!p || j > i)
        return ERROR;  //��i����㲻����
    e = p->data;
    printf("��ϲ�㣬���õĵ�%d��Ԫ��Ϊ��%d\n", i+1, e);
    return OK;
}
Status ListInsert(LinkList *L)  //����Ԫ�ز���
{
    int i, j;
    ElemType e;
    LinkList p, s;
    printf ("��������Ҫ����Ԫ�ص��±꣺\n");
    scanf("%d", &i);
    printf ("��������Ҫ�����Ԫ�����ݣ�\n");
    scanf("%d", &e);
    p = *L;  //������ĵ�һ����㸳ֵ��p
    j = 1;
    while (p && j < i)  //Ѱ�ҵ�i-1�����,
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));  //�����µĽ��
    s->data = e;
    s->next = p->next;  //��p�ĺ�����㸳ֵ��s�ĺ���
    p->next = s;  //��s��ֵ��p�ĺ���
    printf ("��ϲ�㣬�������ݳɹ�\n");
    p = *L;
    printf("���ڵ������������ģ�\n");
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
Status ListDelete(LinkList *L)  //ɾ��Ԫ�ز���
{
    int i, j;
    ElemType e;
    LinkList p, q;
    p = *L;
    j = 1;
    printf ("��������Ҫɾ����Ԫ�ص��±꣺\n");
    scanf ("%d", &i);
    while (p->next && j < i)  //����Ѱ�ҵ�i-1�����
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;  //��i����㲻����
    q = p->next;
    p->next = q->next;  //��q�ĺ�����ֵ��p�ĺ���
    e = q->data;
    printf("����ɾ����Ԫ��Ϊ��%d\n", e);
    free(q);
    p = *L;
    printf ("��ϲ�㣬ɾ�����ݳɹ�\n");
    printf("���ڵ������������ģ�\n");
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
int main(int argc, char const *argv[])
{
    LinkList L;
    SetList(&L);
    GetElem(L);
    ListInsert(&L);
    ListDelete(&L);
    return 0;
}
