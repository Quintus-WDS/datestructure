#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
//�ڽӱ�Ĵ���
#define MVNum 100

typedef struct ArcNode {
	int adjvex;						//�ñ�ָ��Ķ����λ��
	struct ArcNode* nextarc;		//ָ����һ���ߵ�ָ��
	int info;						//�ߵ�Ȩֵ
}ArcNode;	

typedef struct VNode {
	char date;						//������Ϣ
	ArcNode* firstarc;				//ָ���һ���ߵ�ָ��
}VNode,AdjList[MVNum];				//AdjList ��ʾ�ڽӱ�����

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;				//��ǰ�Ķ������ͱ���
}ALGraph;
// ���Ҷ���λ�õĺ���
int LocateVex(ALGraph* G, char v) {
	for (int i = 0; i < G->vexnum; i++) {
		if (G->vertices[i].date == v) {
			return i;
		}
	}
	return -1; // δ�ҵ�����
}
//��������ͼ
void CreateUDG(ALGraph* G) {
	scanf("%d %d", &(G->vexnum), &(G->arcnum));	//���붥�㡢�߸���
	getchar();
	for (int i = 0; i < G->vexnum; i++) {		//���붥����Ϣ
		scanf(" %c", &(G->vertices[i].date));
		G->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G->arcnum; k++) {
		char v1, v2;	//�������Ķ���
		int w;			//�ߵ�Ȩֵ
		scanf(" %c %c %d", &v1, &v2, &w);
		//ȷ��v1v2��G�е�λ�ã���G->vertices�е����
		int i = LocateVex(&G, v1);
		int j = LocateVex(&G, v2);
		if (i == -1 || j == -1) {
			printf("�����ڸýڵ㣡\n");
			exit(1);
		}
		//��p1����vi�ı��ͷ��
		ArcNode* p1;
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices->firstarc = p1;
		//�����µı߽ڵ�p2������vj�ı߱�ͷ��
		ArcNode* p2;
		p2->adjvex = i;
		p2->nextarc = G->vertices[j].firstarc;
	}
}

int main() {
	ALGraph A;
	CreateUDG(&A);
	return 0;
}