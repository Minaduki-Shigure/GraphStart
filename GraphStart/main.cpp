#include "ALGraph.h"

int main(void)
{
	ALGraph G = GraphInit();
	DFSTraverse(G, 0);
	BFS(G);
	MazeSolve(1, 1, 4, 4);
	system("pause");
	return 0;
}