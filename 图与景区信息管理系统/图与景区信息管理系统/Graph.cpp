#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Graph.h"
#include "Tourism.h"
 Graph m_Graph;
using namespace std;

void Init(void) {
	m_Graph.m_nVexNum = 0;
	for (int i = 0; i < 20; i++) {
		strcpy(m_Graph.m_aVexs[i].name, "");
		strcpy(m_Graph.m_aVexs[i].desc, "");
		m_Graph.m_aVexs[i].num = -1;
		for (int j = 0; j < 20; j++) {
			if (i == j) m_Graph.m_aAdjMatrix[i][j] = 0;
			else m_Graph.m_aAdjMatrix[i][j] = MAX;
		}

	}

}// 初始化图结构。
void InsertVex(Vex sVex, int i) {
	m_Graph.m_aVexs[i].num = sVex.num;
	strcpy(m_Graph.m_aVexs[i].name, sVex.name);
	strcpy(m_Graph.m_aVexs[i].desc, sVex.desc);

}// 将顶点添加到顶点数组中。
void InsertEdge(Edge sEdge) {
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
}// 将边保存到邻接矩阵中。
void GetVex(int nVex) {

	cout << m_Graph.m_aVexs[nVex].name << endl;
	cout << m_Graph.m_aVexs[nVex].desc << endl;
	cout << "-----周边景区-----" << endl;
	FindEdge(nVex);

}// 查询指定顶点信息。
int FindEdge(int nVex) {

	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (i != m_Graph.m_aVexs[nVex].num&&m_Graph.m_aAdjMatrix[m_Graph.m_aVexs[nVex].num][i] != MAX) {
			cout << m_Graph.m_aVexs[nVex].name << "-" << m_Graph.m_aVexs[i].name << " " << m_Graph.m_aAdjMatrix[m_Graph.m_aVexs[nVex].num][i] << endl;
		}
	}
	return 0;

}// 查询与指定顶点相连的边。
int GetVexnum(void) {

	return m_Graph.m_nVexNum;
}
