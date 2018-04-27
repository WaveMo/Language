#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef char TElemType;
typedef struct BiTNode  //���ṹ
{
    char data;  //�������
    struct BiTNode *lchild, *rchild;  //���Һ���ָ��
}BiTNode, *BiTree;

BiTree CreateBitree(BiTree *T) {
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            exit (0);
        (*T)->data = ch;  //���ɸ����
        CreateBitree (&(*T)->lchild);  //����������
        CreateBitree (&(*T)->rchild);  //����������
    }
    return *T;
}
BiTree SearchBST(BiTree T, TElemType key)
{
    if (!T)  //���Ҳ��ɹ�
    {
        printf("���Ҳ��ɹ�\n");
        return NULL;
    }
    else if(key == T->data)  //���ҳɹ�
    {
        printf("���ҳɹ�\n");
        return T;
    }
    else if (key < T->data)
        return SearchBST(T->lchild, key);  //����������������
    else
        return SearchBST(T->rchild, key);  //����������������
}
void PrintBST( BiTree T )
{
    if( T ) {
        PrintBST( T->lchild );
        printf("%c ", T->data);
        PrintBST( T->rchild );
    }
}
int main(int argc, char const *argv[]) {
    BiTree T;
    TElemType key;
    CreateBitree(&T);
    printf("���������");
    PrintBST(T);
    printf("\n��������Ҫ���ҵ�Ԫ�أ�\n");
    fflush(stdin);
    scanf("%c", &key);
    SearchBST(T, key);
    getchar();
    return 0;
}
