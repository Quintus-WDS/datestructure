#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
//邻接表的创立
#define MVNum 100

typedef struct ArcNode {
	int adjvex;						//该边指向的顶点的位置
	struct ArcNode* nextarc;		//指向下一条边的指针
	int info;						//边的权值
}ArcNode;	

typedef struct VNode {
	char date;						//顶点信息
	ArcNode* firstarc;				//指向第一条边的指针
}VNode,AdjList[MVNum];				//AdjList 表示邻接表类型

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;				//当前的顶点数和边数
}ALGraph;
// 查找顶点位置的函数
int LocateVex(ALGraph* G, char v) {
	for (int i = 0; i < G->vexnum; i++) {
		if (G->vertices[i].date == v) {
			return i;
		}
	}
	return -1; // 未找到顶点
}
//生成无向图
void CreateUDG(ALGraph* G) {
	scanf("%d %d", &(G->vexnum), &(G->arcnum));	//输入顶点、边个数
	getchar();
	for (int i = 0; i < G->vexnum; i++) {		//输入顶点信息
		scanf(" %c", &(G->vertices[i].date));
		G->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G->arcnum; k++) {
		char v1, v2;	//边依附的顶点
		int w;			//边的权值
		scanf(" %c %c %d", &v1, &v2, &w);
		//确定v1v2在G中的位置，即G->vertices中的序号
		int i = LocateVex(&G, v1);
		int j = LocateVex(&G, v2);
		if (i == -1 || j == -1) {
			printf("不存在该节点！\n");
			exit(1);
		}
		//将p1插入vi的表边头部
		ArcNode* p1;
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices->firstarc = p1;
		//生成新的边节点p2，插入vj的边表头部
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