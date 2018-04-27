#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;//Boolean�ǲ������ͣ���ֵ��TRUE��FALSE
#define MAXVEX 10//��󶥵���
Boolean visited[MAXVEX];//���ʱ�־������
#define TRUE 1
#define FALSE 0
typedef struct
{
	VertexType Vexs[MAXVEX];//�����
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ���
	int numVertexes;//ͼ�е�ǰ�Ķ���
}MGraph;

void CreateMGraph(MGraph *G) //����һ������ͼ
{
	int i, j,  k, w;
	printf("�����붥����\n");
	scanf("%d", &G->numVertexes);//���붥����
	printf("��������Ӧ��Ŀ�Ķ�����Ϣ���Խ��������\n");
	fflush(stdin);
	for (i = 0; i < G->numVertexes; ++i)//���붥����Ϣ�����������
	{
		printf("����%d: ",i+1);
		scanf("%c", &G->Vexs[i]);
		fflush(stdin);
	}
	for (i = 0; i < G->numVertexes; i++)//��ʼ���߱�
	{
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = 0;
	}
	printf("�������ڽӾ���\n");
	for (k = 0; k < G->numVertexes; k++)//����(vi,vj)��Ϣ�������ڽӾ���
	{
		for(w = 0; w < G->numVertexes; w++)
			scanf("%d", &G->arc[k][w]);
	}
}
void DFS(MGraph G, int i)//�ڽӾ����������ȵݹ��㷨
{
	int j;
	visited[i] = TRUE;
	printf("%C", G.Vexs[i]);//��ӡ���㣬Ҳ������������
	printf(" ");
	for (j = 0; j < G.numVertexes; j++)
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);//��Ϊ���ʵ��ڽӶ���ݹ����
}
void DFSTraverse(MGraph G)//������ȱ���
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;//��ʼ�����ж���״̬����δ���ʹ�״̬
	for (i = 0; i < G.numVertexes; i++)
		if (!visited[i])//��δ���ʵĶ������DFS��������ͨͼ��ֻ��ִ��һ��
			DFS(G, i);
}
int main()
{
	MGraph G;
	CreateMGraph(&G);
	printf("\n��ȱ���:\n");
	DFSTraverse(G);
	return 0;
}
/*
0 0 0 0 1 0 0
0 0 1 1 0 0 0
0 1 0 1 0 0 0
0 1 0 0 1 1 0
1 0 0 1 0 0 1
0 0 0 1 0 0 0
0 0 0 0 1 0 0
*/
