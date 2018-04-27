#include <stdio.h>

#define MAXSIZE 200  //�洢�ռ��ʼ������
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;  //Status�Ǻ��������ͣ���ֵ�Ǻ��������״̬���룬��OK��
typedef struct  //�������Ա�ṹ��
{
    ElemType data[MAXSIZE];  //����洢����Ԫ�أ����ֵΪMAXSIZE
    int length;  //���Ա�ĳ���
}SqList;
Status SetList(SqList *L)  //���û��Լ�����һ�����Ա�
{
    printf("������������Ա�ĳ���\n");
    scanf("%d", &L->length);
    printf("������������Ա�\n");
    for(int i = 0; i < L->length; i++)
    {
        scanf("%d", &L->data[i]);
    }
    printf("��ϲ�㣬���Ѿ��ɹ�������������Ա�\n");
    return OK;
}
Status GetElem(SqList L, int i )  //���Ԫ�ز���
{
    int e;
    if(L.length == 0 || i > L.length)
        return ERROR;
    e = L.data[i-1];
    printf("���õ�Ԫ���ǣ�%d\n", e);
    return OK;
}
Status ListInsert(SqList *L, int i, ElemType e)  //����Ԫ�ز���
{
    int k;
    if(L->length == MAXSIZE)  //˳�����Ա�����
        return ERROR;
    if(i < 1 || i > L->length)  //��i���ڷ�Χ��
        return ERROR;
    if(i <= L->length)  //�����������λ�ò��ڱ�β
    {
        for(k = L->length; k >= i - 1; k--)  //��Ҫ�����λ�ú�����Ԫ������ƶ�һλ
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;  //����Ԫ�ز���
    L->length++;
    printf("��ϲ�㣬���Ѿ�������Ԫ�� %d\n", e);
    printf("����������Ա��������ģ�\n");
    for(int j = 0; j < L->length; j++)
    {
        printf("%d", L->data[j]);
        printf(j == L->length-1 ? "\n" : " ");
    }
    return OK;
}
Status ListDelete(SqList *L, int i)  //ɾ��Ԫ�ز���
{
    int e, k;
    if(L->length == 0)  //���Ա�Ϊ��
        return ERROR;
    if(i < 1 || i > L->length)  //ɾ��λ�ò���ȷ
        return ERROR;
    e = L->data[i-1];
    if(i < L->length)  //���ɾ���Ĳ�������λ��
    {
        for(k = i; k < L->length; k++)  //��ɾ��λ�ú���Ԫ��ǰ��
            L->data[i-1] = L->data[i];
    }
    L->length--;
    printf("��ϲ�㣬���Ѿ�ɾ����Ԫ�� %d\n", e);
    printf("����������Ա��������ģ�\n");
    for(int j = 0; j < L->length; j++)
    {
        printf("%d", L->data[j]);
        printf(j == L->length-1 ? "\n" : " ");
    }
    return OK;
    return OK;
}
int main(int argc, char const *argv[])
{
    int i, j, e, k;
    SqList L;
    SetList(&L);
    printf("��������Ҫ��õ�Ԫ�ص�λ�ã�\n");
    scanf("%d", &i);
    GetElem(L, i);
    printf("��������Ҫ����Ԫ�ص�λ�ã�\n");
    scanf("%d", &j);
    printf("��������Ҫ�����Ԫ�����ݣ�\n");
    scanf("%d", &e);
    ListInsert(&L, j, e);
    printf("��������Ҫɾ����Ԫ�ص�λ�ã�\n");
    scanf("%d", &k);
    ListDelete(&L, k);
    return 0;
}
