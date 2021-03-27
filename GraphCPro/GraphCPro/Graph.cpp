#define _CRT_SECURE_NO_WARNINGS//消除scanf警告
#include"Graph.h"
#include"Tourism.h"
#include<cstring>
#include<iostream>
#define INF 32767;
using namespace std;
Graph m_Graph;
//初始化图信息
void Init(void)
{
	m_Graph.m_nVexNum = 0;
	int i;
	for (i = 0; i < 20; i++)
	{
		m_Graph.m_aVexs[i].num = -1;
		strcpy(m_Graph.m_aVexs[i].name, "");
		strcpy(m_Graph.m_aVexs[i].desc, "");
		for (int j = 0; j < 20; j++)
			m_Graph.m_aAdjMatrix[i][j] = 0;

	}
}
//插入点
bool InsertVex(Vex sVex)
{
	if (m_Graph.m_nVexNum == 32767)
		return false;
	m_Graph.m_aVexs[m_Graph.m_nVexNum++] = sVex;
	return true;
}
//插入边
bool InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_Graph.m_nVexNum ||
		sEdge.vex2 < 0 || sEdge.vex2 >= m_Graph.m_nVexNum)
		return false;
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return true;
}
Vex GetVex(int nVex) {
	return m_Graph.m_aVexs[nVex];
}
/*
寻找周围景区 相连边存放于aEdge数组中
周围景区数目
*/
int FindEdge(int nVex, Edge aEdge[]) {
	int k = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (m_Graph.m_aAdjMatrix[nVex][i] != 0)
		{
			aEdge[k].vex1 = nVex;
			aEdge[k].vex2 = i;
			aEdge[k].weight = m_Graph.m_aAdjMatrix[nVex][i];
			k++;
		}
	}
	return k; //返回周围景点的数目
}

/*输入参数：int nVex，顶点编号。
输入参数：bVisted[]，bool 类型的数组，用来记录某个顶点是否被遍历过。
输入参数：int &nIndex，记录遍历的深度。
输出参数：PathList &pList，遍历得到的结果。
功能：使用深度优先搜索算法遍历图。*/
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList)
{
	bVisted[nVex] = true; //改为已访问
	pList->vexs[nIndex++] = nVex; //访问顶点nVex
	int nVexNum = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (bVisted[i]) nVexNum++;
	}
	//判断是否所有顶点都访问过
	if (nVexNum == m_Graph.m_nVexNum) {
		pList->next = (PathList)malloc(sizeof(Path));
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			pList->next->vexs[i] = pList->vexs[i];
		}
		pList = pList->next;
		pList->next = NULL;//链表移动
	}
	else {
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			if (!bVisted[i] && (m_Graph.m_aAdjMatrix[nVex][i] > 0) && (m_Graph.m_aAdjMatrix[nVex][i] != 32767)) {
				//递归调用得到一条路径
				DFS(i, bVisted, nIndex, pList);
				bVisted[i] = false; //得到一条路径后将访问的i点置为false
				nIndex--;//回溯
			}
		}
	}
	
}

/*void DFS(int nVex, bool bVisited[], int &nIndex, PathList &pList)

{
	bVisited[nVex] = true; //改为已经访问
	pList->vexs[nIndex++] = nVex;//访问结点nVex
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (m_Graph.m_aAdjMatrix[nVex][i] != 0 && !bVisited[i])
		{
			DFS(i, bVisited, nIndex, pList);
			bVisted[i] = false; 
				nIndex--;
		}
	}
}

*/

/*
输入参数：int nVex，顶点编号。
输出参数：PathList &pList，遍历得到的结果。
功能：通过调用 DFS()函数，得到深度优先搜索遍历结果。*/
void DFSTraverse(int nVex, PathList &pList)
{
	bool bVisited[32767] = { false };
	int nIndex = 0;
	DFS(nVex, bVisited, nIndex, pList);
}


/*
输入：起始景点的编号v1和目的景点的编号v2。
输出：最短路径。
功能：通过Dijkstra算法求得v1到v2的最短路径
*/
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{
	//初始化最短路径
	int flag[20], pre[20];
	int dis[20], k;//dis数组用于储存起始顶点到其余各个顶点的距离
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		flag[i] = 0;
		pre[i] = 0;
		if (m_Graph.m_aAdjMatrix[nVexStart][i] > 0 || i == nVexStart)
		{
			//两点间距离
			dis[i] = m_Graph.m_aAdjMatrix[nVexStart][i];
			//当两个边直接相连，pre初始化为起点
			pre[i] = nVexStart;

		}
		else
		{
			//和起始点不相连的点的距离初始化为INF
			dis[i] = INF;
		}
	}

	flag[nVexStart] = 1;//第一个并入的应该是nStartVex点
	int min;
	//遍历节点数-1次，每次找出一个顶点的最短路径
	for (int i = 1; i < m_Graph.m_nVexNum; i++)
	{
		min = INF;
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			if (flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				k = j;
				//k是与起点相连的最小路径的点
			}
		}
		flag[k] = 1;//表示结点k已经找到最短路径
		if (k == nVexEnd)
		{
			break;
		}
		//将k作为中间点计算nVexSart到所有顶点的最短路径，进行扩充集合
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			int temp;
			//如果结点K与结点j之间无连线
			if (m_Graph.m_aAdjMatrix[k][j] == 0)
			{
				temp = INF;
			}
			else
			{
				temp = min + m_Graph.m_aAdjMatrix[k][j];

			}
			if (flag[j = 0] && (temp < dis[j]))
			{
				dis[j] = temp;
				pre[j] = k;
			}
		}
	}
	
	//路径数
	int Num = 0;
	//从终点开始回溯
	int i = nVexEnd;
	while (i != nVexStart)
	{
		aPath[Num].vex2 = i;
		aPath[Num].vex1 = pre[i];
		aPath[Num].weight = m_Graph.m_aAdjMatrix[pre[i]][i];
		i = pre[i];
		Num++;
	}

	return Num;
}

/*
输入：Edge aPath[]
输出：最小生成树。
功能：通过Prim算法构建最小生成树。
*/

int FindMinTree(int nStart,Edge aPath[])
{
	//哨兵 前置结点 权值
	int flag[20], closest[20], lowcost[20];
	//初始化
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		flag[i] = 0;
		closest[i] = -1;
		if (m_Graph.m_aAdjMatrix[nStart][i] > 0 || i == nStart)
		{
			lowcost[i] = m_Graph.m_aAdjMatrix[nStart][i];
			closest[i] = nStart;
		}
		else {
			lowcost[i] = INF;
		}
	}
	flag[nStart] = 1;
	int Num = 0;

	int min, k;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		min = INF;
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			if (!flag[j] && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (int j = 0; j < m_Graph.m_nVexNum; j++) {
			if (flag[j] == 0 && m_Graph.m_aAdjMatrix[k][j] < lowcost[j] && m_Graph.m_aAdjMatrix[k][j] != 0) {
				lowcost[j] = m_Graph.m_aAdjMatrix[k][j];
				closest[j] = k;
			}
		}
		//储存各边的信息到aPath数组中
		flag[closest[k]] = 1;
		aPath[Num].vex1 = closest[k];
		aPath[Num].vex2 = k;
		aPath[Num].weight= m_Graph.m_aAdjMatrix[closest[k]][k];
		Num++;
		
	}
	return Num;//返回边的数目
}





















