#include "ALGraph.h"

ALGraph GraphInit(void)
{
	int i, k;
	ALGraph g;
	ArcNode *node;
	VertexType gef, gel;
	printf("顶点数：");
	scanf_s("%d", &g.VexNum);
	printf("边数：");
	scanf_s("%d", &g.ArcNum);
	for (i = 0; i<g.VexNum; i++)
	{
		g.Vertices[i].data = i;
		g.Vertices[i].FirstArc = NULL;
	}
	printf("请输入边。例如，0与2之间有边，则输入0 2 Enter\n");
	for (k = 0; k<g.ArcNum; k++)
	{
		printf("请输入第%d条边的信息：", k + 1);
		scanf_s("%d %d", &gef, &gel);
		gef = gef = 1;
		gel = gel - 1;
		node = (ArcNode*)malloc(sizeof(ArcNode));
		if (node == NULL) 
			exit(-1);
		node->AdjVex = gel;
		node->NextArc = g.Vertices[gef].FirstArc;
		g.Vertices[gef].FirstArc = node;
		node = (ArcNode*)malloc(sizeof(ArcNode));
		if (node == NULL) 
			exit(-1);
		node->AdjVex = gef;
		node->NextArc = g.Vertices[gel].FirstArc;
		g.Vertices[gel].FirstArc = node;
	}
	printf("Init success!\n");
	return g;
}

VertexType FindFistAdjVex(ALGraph g, int v)
{
	ArcNode *ptr = g.Vertices[v].FirstArc;
	if (ptr)
		return ptr->AdjVex;
	else
		return -1;
}

VertexType FindNextAdjVex(ALGraph g, int v, int w)
{
	ArcNode *ptr = g.Vertices[v].FirstArc;
	while (ptr)
	{
		if (ptr->AdjVex == w)
			break;
		ptr = ptr->NextArc;
	}
	if (ptr->AdjVex != w || !ptr->NextArc)
		return -1;
	return ptr->NextArc->AdjVex;
}

void DFS(ALGraph g, int v)
{
	ArcNode *ptr;
	visited[v] = 1;
	printf("%d ", g.Vertices[v].data);
	for (ptr = g.Vertices[v].FirstArc; ptr; ptr = ptr->NextArc)
	{
		if (!visited[ptr->AdjVex])
			DFS(g, ptr->AdjVex);
	}
	return;
}

void DFSTraverse(ALGraph g, int vex)
{
	for (int i = 0; i < g.VexNum; i++)
		visited[i] = 0;
	DFS(g, vex);
	for (int v = 0; v < g.VexNum; v++)
		if (!visited[v])
			DFS(g, v);
	putchar('\n');
	return;
}

void BFS(ALGraph g)
{
	for (int i = 0; i < g.VexNum; i++)
		visited[i] = 0;
	CircQueue q = QueueInit(MAX_VERTEX_NUM);
	int v;
	int u;
	ArcNode *ptr;
	for (v = 0; v < g.VexNum; v++)
	{
		if (!visited[v])
		{
			visited[v] = 1;
			printf("%d ", g.Vertices[v].data);
			EnQueue(&q, v);
			while (q.front != q.rear)
			{
				u = q.base[q.front];
				DeQueue(&q);
				for (ptr = g.Vertices[v].FirstArc; ptr; ptr = ptr->NextArc)
				{
					if (!visited[ptr->AdjVex])
					{
						visited[ptr->AdjVex] = 1;
						printf("%d ", g.Vertices[ptr->AdjVex].data);
						EnQueue(&q, ptr->AdjVex);
					}
				}
			}
		}
	}
	putchar('\n');
	return;
}