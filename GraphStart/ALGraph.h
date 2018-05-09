#pragma once

#include<stdio.h>
#include<stdlib.h>
#include "CircQueue.h"

typedef int InfoType;
typedef int VertexType;

#define MAX_VERTEX_NUM 20

int visited[MAX_VERTEX_NUM];

typedef struct ArcNode {
	int AdjVex;
	struct ArcNode *NextArc;
	InfoType *info;
}ArcNode;

typedef struct VertexNode {
	VertexType data;
	ArcNode *FirstArc;
}VertexNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph {
	AdjList Vertices;
	int VexNum, ArcNum;
	int kind;
}ALGraph;

ALGraph GraphInit(void);
VertexType FindFistAdjVex(ALGraph g, int v);
VertexType FindNextAdjVex(ALGraph g, int v, int w);
void DFS(ALGraph g, int v);
void DFSTraverse(ALGraph g, int vex);
void BFS(ALGraph g);
void BFSTraverse(ALGraph G);