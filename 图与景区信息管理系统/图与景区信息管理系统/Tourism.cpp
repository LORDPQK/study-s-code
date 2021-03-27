#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <cstdio>
#include <algorithm>
#include "Graph.h"
#include "Tourism.h"
using namespace std;
extern struct Graph m_Graph;

void CreateGraph(void) {
	Init();
	int num;		         // 景点编号
	char name[20];	// 景点名字
	char desc[1024];//景点描述
	ifstream VexR("Vex.txt"), EdgeR("Edge.txt");
	if (VexR.is_open()) {
		VexR >> m_Graph.m_nVexNum;

		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			VexR >> num >> name >> desc;
			Vex temp(num, name, desc);
			InsertVex(temp, i);

		}
	}
	int vex1, vex2;   //边的两个个顶点
	int weight;  	    //权值
	if (EdgeR.is_open()) {
		while (!EdgeR.eof()) {
			EdgeR >> vex1 >> vex2 >> weight;
			Edge temp(vex1, vex2, weight);
			InsertEdge(temp);
		}

	}
	return;
}//读取文件，创建景区景点图。

void GetSpotInfo(void) {

	cout << "=====查询景点信息=====" << endl;

	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "请输入想要查询的景点编号:";
	int option;
	cin >> option;
	GetVex(option);

}

