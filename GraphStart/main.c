#include "ALGraph.h"

int main(void)
{
	ALGraph G = GraphInit();
	DFSTraverse(G, 0);
	BFS(G);
	system("pause");
	return 0;
}