#include "ALGraph.h"

int main(void)
{
	ALGraph G = GraphInit();
	DFSTraverse(G, 0);
	BFS(G);
	printf("�������Թ�����ںͳ��ڶ����ţ�\n");
	VertexType in, out;
	scanf_s("%d %d", &in, &out);
	MazeSolveBFS(G, in, out);
	system("pause");
	return 0;
}