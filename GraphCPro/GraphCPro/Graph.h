#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
struct Vex
{
	int num;
	char name[20];
	char desc[1024];
};
struct Edge
{
	int vex1;
	int vex2;
	int weight;
};

struct Graph
{
	int m_aAdjMatrix[20][20];//邻接矩阵
	Vex m_aVexs[20];//顶点信息 里面有景点编号、名字、描述
	int m_nVexNum;//顶点个数
};//Graph对象，用于存储景区景点图

typedef struct Path
{
	int vexs[20]; //保存一条路径
	Path *next; //下一条路径
}*PathList;

void Init(void);
bool InsertVex(Vex sVex);
bool InsertEdge(Edge sEdge);
Vex GetVex(int nVex);
int FindEdge(int nVex, Edge aEdge[]);
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList);
void DFSTraverse(int nVex, PathList &pList);
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);
int FindMinTree(int nStart, Edge aPath[]);
#endif //GRAPH_H_INCLUDED
