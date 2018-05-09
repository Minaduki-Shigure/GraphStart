#include "ALGraph.h"

int main(void)
{
	ALGraph G = GraphInit();
	DFSTraverse(G, 0);
	BFS(G);
	printf("请输入迷宫的入口和出口顶点编号：\n");
	VertexType in, out;
	scanf_s("%d %d", &in, &out);
	MazeSolveBFS(G, in, out);
	system("pause");
	return 0;
}