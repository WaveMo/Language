#include <stdio.h>

#define MAXSIZE 200
#define OK 1
typedef int SElemType;  //SElemType���͸���ʵ������������������int
typedef struct
{
    SElemType data[MAXSIZE];
    int top;  //����ջ��ָ��
}SqStack;

int Push( SqStack *s, SElemType e )
{
    if ( s->top == MAXSIZE - 1 )  //ջ��
    {
        return 0;
    }
    s->top++;  //ջ��ָ��+1
    s->data[s->top] = e;  //���²���Ԫ�ظ�ֵ��ջ���ռ�
    return 1;
}
int Pop( SqStack *s, SElemType *e)
{
    if ( s->top == -1 )
        return 0;
    *e = s->data[s->top];  //��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
    s->top--;  //ջ��ָ��-1
    return 1;
}
